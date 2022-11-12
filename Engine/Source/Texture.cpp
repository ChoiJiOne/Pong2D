#include "Texture.h"
#include "Graphics.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <stb/stb_image.h>
// @third party code - END

Texture::Texture(Graphics& InGraphics, const std::string& InPath)
{
	std::vector<uint8_t> Buffer;
	int32_t Format = 0, Width = 0, Height = 0;

	CHECK((LoadTextureFromFile(InPath, Buffer, Format, Width, Height)), "failed to load texture file");

	Texture_ = CreateTextureResource(InGraphics, Buffer, Format, Width, Height);
	CHECK((Texture_ != nullptr), "failed to create texture resource");

	CHECK((SDL_SetTextureBlendMode(Texture_, SDL_BLENDMODE_BLEND) == 0), "failed to set blend mode in texture");
}

Texture::Texture(SDL_Texture* InTexture)
{
	CHECK((InTexture != nullptr), "invalid constructor parameter");
	Texture_ = InTexture;
}

Texture::~Texture()
{
	if (Texture_)
	{
		SDL_DestroyTexture(Texture_);
		Texture_ = nullptr;
	}
}

void Texture::GetSize(int32_t& OutWidth, int32_t& OutHeight)
{
	CHECK((SDL_QueryTexture(Texture_, nullptr, nullptr, &OutWidth, &OutHeight) == 0), "failed to query texture size")
}

bool Texture::LoadTextureFromFile(const std::string& InPath, std::vector<uint8_t>& OutBuffer, int32_t& OutFormat, int32_t& OutWidth, int32_t& OutHeight)
{
	uint8_t* Buffer = stbi_load(InPath.c_str(), &OutWidth, &OutHeight, &OutFormat, 0);

	if (!Buffer) return false;

	std::size_t BufferSize = OutWidth * OutHeight * OutFormat;
	OutBuffer.resize(BufferSize);
	std::copy(Buffer, Buffer + BufferSize, &OutBuffer[0]);

	stbi_image_free(Buffer);
	Buffer = nullptr;

	return true;
}

SDL_Texture* Texture::CreateTextureResource(Graphics& InGraphics, const std::vector<uint8_t>& InBuffer, const int32_t& InFormat, const int32_t& InWidth, const int32_t& InHeight)
{
	int32_t Pitch = InWidth * InFormat;

	uint32_t Format;
	switch (InFormat)
	{
	case 4:
		Format = SDL_PIXELFORMAT_RGBA32;
		break;
	case 3:
		Format = SDL_PIXELFORMAT_RGB24;
		break;
	case 2:
		Format = SDL_PIXELFORMAT_RGB565;
		break;
	case 1:
		Format = SDL_PIXELFORMAT_RGB332;
		break;
	default:
		ENFORCE_THROW_EXCEPTION("not support texture resource format...");
		break;
	}

	SDL_Texture* Texture = SDL_CreateTexture(InGraphics.GetRenderer(), Format, SDL_TEXTUREACCESS_STATIC, InWidth, InHeight);
	CHECK((Texture != nullptr), "failed to SDL_CreateTexture");

	CHECK((SDL_UpdateTexture(Texture, nullptr, reinterpret_cast<const void*>(&InBuffer[0]), Pitch) == 0), "failed to contain texture buffer");

	return Texture;
}