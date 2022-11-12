#include "Font.h"
#include "Graphics.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>
// @third party code - END

Font::Font(
	Graphics& InGraphics,
	const std::string& InPath,
	int32_t InBeginCodePoint,
	int32_t InEndCodePoint,
	float InFontSize
) : BeginCodePoint_(InBeginCodePoint),
	EndCodePoint_(InEndCodePoint)
{
	std::vector<uint8_t> Buffer;
	CHECK((LoadTrueTypeFontFromFile(InPath, Buffer)), "failed to load trye type font");

	stbtt_fontinfo Info;
	CHECK((stbtt_InitFont(
		&Info,
		reinterpret_cast<const unsigned char*>(&Buffer[0]),
		stbtt_GetFontOffsetForIndex(reinterpret_cast<const unsigned char*>(&Buffer[0]), 0)
	) != 0), "failed to initialize stb_truetype");

	int32_t BitmapSize = 0;
	std::shared_ptr<uint8_t[]> Bitmap = GenerateTextureAtlasBitmap(Buffer, BeginCodePoint_, EndCodePoint_, InFontSize, CharacterInfos_, BitmapSize);

	TextureAtlas_ = CreateTextureAtlasFromBitmap(InGraphics, Bitmap, BitmapSize);
}

Font::~Font()
{
	if (TextureAtlas_)
	{
		SDL_DestroyTexture(TextureAtlas_);
		TextureAtlas_ = nullptr;
	}
}

const CharacterInfo& Font::GetCharacterInfo(int32_t InCodePoint) const
{
	CHECK(HasCodePointInRange(InCodePoint), "code point is out of range");
	int32_t Index = InCodePoint - BeginCodePoint_;
	return CharacterInfos_[Index];
}

bool Font::HasCodePointInRange(int32_t InCodePoint) const
{
	return (BeginCodePoint_ <= InCodePoint) && (InCodePoint <= EndCodePoint_);
}

void Font::MeasureText(const std::wstring& InText, int32_t& OutWidth, int32_t& OutHeight) const
{
	int32_t TextHeight = -1;
	int32_t TextWidth = 0;

	for (const auto& Unicode : InText)
	{
		const CharacterInfo& UnicodeInfo = GetCharacterInfo(static_cast<int32_t>(Unicode));

		int32_t CurrWidth = static_cast<int32_t>(UnicodeInfo.XAdvance);
		int32_t CurrHeight = UnicodeInfo.Position1.y - UnicodeInfo.Position0.y;

		TextWidth += CurrWidth;

		if (CurrHeight > TextHeight)
		{
			TextHeight = CurrHeight;
		}
	}

	OutWidth = TextWidth;
	OutHeight = TextHeight;
}

bool Font::LoadTrueTypeFontFromFile(const std::string& InPath, std::vector<uint8_t>& OutBuffer)
{
	OutBuffer.resize(1 << 25);

	FILE* FontFile = nullptr;
	fopen_s(&FontFile, InPath.c_str(), "rb");

	if (!FontFile) return false;

	fread(&OutBuffer[0], 1, 1 << 25, FontFile);
	fclose(FontFile);

	return true;
}

std::shared_ptr<uint8_t[]> Font::GenerateTextureAtlasBitmap(
	const std::vector<uint8_t>& InBuffer, 
	int32_t InBeginCodePoint, 
	int32_t InEndCodePoint, 
	float InFontSize, 
	std::vector<CharacterInfo>& OutCharacterInfos, 
	int32_t& OutSize
)
{
	std::vector<stbtt_packedchar> Packedchars(InEndCodePoint - InBeginCodePoint + 1);
	OutCharacterInfos.resize(InEndCodePoint - InBeginCodePoint + 1);

	int32_t Success = 0;
	stbtt_pack_context PackContext;
	std::shared_ptr<uint8_t[]> Bitmap = nullptr;

	for (int32_t Size = 16; Size < 8192; Size *= 2)
	{
		Bitmap = std::make_unique<uint8_t[]>(Size * Size);
		Success = stbtt_PackBegin(&PackContext, Bitmap.get(), Size, Size, 0, 1, nullptr);
		stbtt_PackSetOversampling(&PackContext, 1, 1);

		Success = stbtt_PackFontRange(
			&PackContext,
			reinterpret_cast<const unsigned char*>(&InBuffer[0]),
			0,
			InFontSize,
			InBeginCodePoint,
			static_cast<int>(Packedchars.size()),
			&Packedchars[0]
		);

		if (Success)
		{
			stbtt_PackEnd(&PackContext);
			OutSize = Size;
			break;
		}
		else
		{
			stbtt_PackEnd(&PackContext);
			Bitmap.reset();
		}
	}

	for (std::size_t Index = 0; Index < Packedchars.size(); ++Index)
	{
		OutCharacterInfos[Index].CodePoint = Index + InBeginCodePoint;

		OutCharacterInfos[Index].Position0 = Vec2i(Packedchars[Index].x0, Packedchars[Index].y0);
		OutCharacterInfos[Index].Position1 = Vec2i(Packedchars[Index].x1, Packedchars[Index].y1);

		OutCharacterInfos[Index].XOffset = Packedchars[Index].xoff;
		OutCharacterInfos[Index].YOffset = Packedchars[Index].yoff;

		OutCharacterInfos[Index].XOffset2 = Packedchars[Index].xoff2;
		OutCharacterInfos[Index].YOffset2 = Packedchars[Index].yoff2;

		OutCharacterInfos[Index].XAdvance = Packedchars[Index].xadvance;
	}

	return Bitmap;
}

SDL_Texture* Font::CreateTextureAtlasFromBitmap(Graphics& InGraphics, const std::shared_ptr<uint8_t[]>& InBitmap, const int32_t InSize)
{
	auto Pixels = std::make_unique<uint32_t[]>(InSize * InSize);

	SDL_Texture* TextureAtlas = SDL_CreateTexture(InGraphics.GetRenderer(), SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, InSize, InSize);
	CHECK((TextureAtlas != nullptr), "failed to create texture altas");

	CHECK((SDL_SetTextureBlendMode(TextureAtlas, SDL_BLENDMODE_BLEND) == 0), "failed to set blend mode in texture atlas");

	SDL_PixelFormat* Format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32);
	CHECK((Format != nullptr), "failed to alloc format");

	for (int32_t index = 0; index < InSize * InSize; ++index)
	{
		Pixels[index] = SDL_MapRGBA(Format, 0xFF, 0xFF, 0xFF, InBitmap[index]);
	}

	CHECK((SDL_UpdateTexture(TextureAtlas, nullptr, Pixels.get(), InSize * sizeof(uint32_t)) == 0), "failed to update texture atlas");

	SDL_FreeFormat(Format);
	Format = nullptr;

	return TextureAtlas;
}