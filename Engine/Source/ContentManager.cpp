#include <ContentManager.h>
#include <CommandLineManager.h>
#include <Renderer.h>

#include <fstream>

ContentManager ContentManager::ContentManager_;

void ContentManager::Init()
{
	ContentPath_ = CommandLineManager::Get().GetValue("-Content");
}

void ContentManager::Quit()
{
	for (auto& sound : Sounds_)
	{
		sound.second.reset();
	}

	for (auto& music : Musics_)
	{
		music.second.reset();
	}

	for (auto& texture : Textures_)
	{
		texture.second.reset();
	}

	for (auto& font : Fonts_)
	{
		font.second.reset();
	}
}

Texture& ContentManager::LoadTexture(const std::size_t& InKey, Renderer& InRenderer, const std::string& InPath)
{
	CHECK(!HaveTexture(InKey), "collision texture key or already load texture resource");

	std::unique_ptr<Texture> NewTexture = std::make_unique<Texture>(InRenderer, ContentPath_ + InPath);
	Textures_.insert({ InKey, std::move(NewTexture) });

	return *Textures_.at(InKey);
}

void ContentManager::RemoveTexture(const std::size_t& InKey)
{
	if (!HaveTexture(InKey)) return;
	Textures_.erase(InKey);
}

bool ContentManager::HaveTexture(const std::size_t& InKey)
{
	return Textures_.find(InKey) != Textures_.end();
}

Texture& ContentManager::GetTexture(const std::size_t& InKey)
{
	CHECK(HaveTexture(InKey), "can't find texture resource");
	return *Textures_.at(InKey);
}

Font& ContentManager::LoadFont(const std::size_t& InKey, Renderer& InRenderer, const std::string& InPath, int32_t InBeginCodePoint, int32_t InEndCodePoint, float InFontSize)
{
	CHECK(!HaveFont(InKey), "collision font key or already load font resource");

	std::unique_ptr<Font> NewFont = std::make_unique<Font>(InRenderer, ContentPath_ + InPath, InBeginCodePoint, InEndCodePoint, InFontSize);
	Fonts_.insert({ InKey, std::move(NewFont) });

	return *Fonts_.at(InKey);
}

void ContentManager::RemoveFont(const std::size_t& InKey)
{
	if (!HaveFont(InKey)) return;
	Fonts_.erase(InKey);
}

bool ContentManager::HaveFont(const std::size_t& InKey)
{
	return Fonts_.find(InKey) != Fonts_.end();
}

Font& ContentManager::GetFont(const std::size_t& InKey)
{
	CHECK(HaveFont(InKey), "can't find font resource");
	return *Fonts_.at(InKey);
}

Json& ContentManager::LoadJson(const std::size_t& InKey, const std::string& InPath)
{
	CHECK(!HaveJson(InKey), "collision Json key or already load json resource");

	std::ifstream JsonFile(ContentPath_ + InPath);
	CHECK((JsonFile.is_open()), "failed to load json file");
	
	Jsons_.insert({ InKey, Json::parse(JsonFile) });

	return Jsons_.at(InKey);
}

void ContentManager::RemoveJson(const std::size_t& InKey)
{
	if (!HaveJson(InKey)) return;
	Jsons_.erase(InKey);
}

bool ContentManager::HaveJson(const std::size_t& InKey)
{
	return Jsons_.find(InKey) != Jsons_.end();
}

Json& ContentManager::GetJson(const std::size_t& InKey)
{
	CHECK(HaveJson(InKey), "can't find json resource");
	return Jsons_.at(InKey);
}

Music& ContentManager::LoadMusic(const std::size_t& InKey, const std::string& InPath)
{
	CHECK(!HaveMusic(InKey), "collision music key or already load music resource");

	std::unique_ptr<Music> NewMusic = std::make_unique<Music>(ContentPath_ + InPath);
	Musics_.insert({ InKey, std::move(NewMusic) });

	return *Musics_.at(InKey);
}

void ContentManager::RemoveMusic(const std::size_t& InKey)
{
	if (!HaveMusic(InKey)) return;
	Musics_.erase(InKey);
}

bool ContentManager::HaveMusic(const std::size_t& InKey)
{
	return Musics_.find(InKey) != Musics_.end();
}

Music& ContentManager::GetMusic(const std::size_t& InKey)
{
	CHECK(HaveMusic(InKey), "can't find music resource");
	return *Musics_.at(InKey);
}

Sound& ContentManager::LoadSound(const std::size_t& InKey, const std::string& InPath)
{
	CHECK(!HaveSound(InKey), "collision sound key or already load sound resource");

	std::unique_ptr<Sound> NewSound = std::make_unique<Sound>(ContentPath_ + InPath);
	Sounds_.insert({ InKey, std::move(NewSound) });

	return *Sounds_.at(InKey);
}

void ContentManager::RemoveSound(const std::size_t& InKey)
{
	if (!HaveSound(InKey)) return;
	Sounds_.erase(InKey);
}

bool ContentManager::HaveSound(const std::size_t& InKey)
{
	return Sounds_.find(InKey) != Sounds_.end();
}

Sound& ContentManager::GetSound(const std::size_t& InKey)
{
	CHECK(HaveSound(InKey), "can't find sound resource");
	return *Sounds_.at(InKey);
}
