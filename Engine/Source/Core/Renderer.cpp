#include "Core/Renderer.h"
#include "Core/Window.h"

#include "Resource/Texture.h"
#include "Resource/Font.h"

#include "Misc/MathUtils.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

Renderer::Renderer(Window& InWindow, const ERendererFlags& InFlags)
{
	Renderer_ = SDL_CreateRenderer(InWindow.GetWindow(), -1, static_cast<uint32_t>(InFlags));
	CHECK((Renderer_ != nullptr), "failed to create renderer");
}

Renderer::~Renderer()
{
	if (Renderer_)
	{
		SDL_DestroyRenderer(Renderer_);
		Renderer_ = nullptr;
	}
}

void Renderer::BeginFrame(const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderClear(Renderer_) == 0), SDL_GetError());
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(Renderer_);
}

void Renderer::DrawPoint2D(const Vec2i& InPosition, const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderDrawPoint(Renderer_, InPosition.x, InPosition.y) == 0), SDL_GetError());
}

void Renderer::DrawLine2D(const Vec2i& InPositionFrom, const Vec2i& InPositionTo, const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderDrawLine(
		Renderer_, 
		InPositionFrom.x, InPositionFrom.y,
		InPositionTo.x, InPositionTo.y
	) == 0), SDL_GetError());
}

void Renderer::DrawRect2D(const Vec2i& InPositionFrom, const Vec2i& InPositionTo, const LinearColor& InColor)
{
	SetDrawColor(InColor);

	SDL_Rect Rect = {
		std::min(InPositionFrom.x, InPositionTo.x),
		std::min(InPositionFrom.y, InPositionTo.y),
		std::abs(InPositionTo.x - InPositionFrom.x),
		std::abs(InPositionTo.y - InPositionFrom.y)
	};

	CHECK((SDL_RenderDrawRect(Renderer_, &Rect) == 0), SDL_GetError());
}

void Renderer::DrawRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i PositionFrom = InCenterPosition - DeltaPosition;
	Vec2i PositionTo = InCenterPosition + DeltaPosition;

	DrawRect2D(PositionFrom, PositionTo, InColor);
}

void Renderer::DrawFillRect2D(const Vec2i& InPositionFrom, const Vec2i& InPositionTo, const LinearColor& InColor)
{
	SetDrawColor(InColor);

	SDL_Rect Rect = {
		std::min(InPositionFrom.x, InPositionTo.x),
		std::min(InPositionFrom.y, InPositionTo.y),
		std::abs(InPositionTo.x - InPositionFrom.x),
		std::abs(InPositionTo.y - InPositionFrom.y)
	};

	CHECK((SDL_RenderFillRect(Renderer_, &Rect) == 0), SDL_GetError());
}

void Renderer::DrawFillRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i PositionFrom = InCenterPosition - DeltaPosition;
	Vec2i PositionTo = InCenterPosition + DeltaPosition;

	DrawFillRect2D(PositionFrom, PositionTo, InColor);
}

void Renderer::DrawTexture2D(Texture& InTexture, const Vec2i& InPositionFrom, const Vec2i& InPositionTo, float InRotateAngle)
{
	SDL_Rect Rect = {
		std::min(InPositionFrom.x, InPositionTo.x),
		std::min(InPositionFrom.y, InPositionTo.y),
		std::abs(InPositionTo.x - InPositionFrom.x),
		std::abs(InPositionTo.y - InPositionFrom.y),
	};

	CHECK((SDL_RenderCopyEx(Renderer_, InTexture.GetTexture(), nullptr, &Rect, InRotateAngle, nullptr, SDL_FLIP_NONE) == 0), SDL_GetError());
}

void Renderer::DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, float InRotateAngle)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i Position0 = InCenterPosition - DeltaPosition;
	Vec2i Position1 = InCenterPosition + DeltaPosition;

	DrawTexture2D(InTexture, Position0, Position1, InRotateAngle);
}

void Renderer::DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, float InRotateAngle)
{
	int32_t TextureWidth = 0;
	int32_t TextureHeight = 0;
	InTexture.GetSize(TextureWidth, TextureHeight);

	DrawTexture2D(InTexture, InCenterPosition, TextureWidth, TextureHeight, InRotateAngle);
}

void Renderer::DrawText2D(Font& InFont, const std::wstring& InText, const Vec2i& InCenterPosition, const LinearColor& InColor)
{
	int32_t TextWidth = 0, TextHeight = 0;
	InFont.MeasureText(InText, TextWidth, TextHeight);

	Vec2i Position(
		InCenterPosition.x - static_cast<int32_t>(static_cast<float>(TextWidth) / 2.0f),
		InCenterPosition.y + static_cast<int32_t>(static_cast<float>(TextHeight) / 2.0f)
	);

	uint8_t R = 0, G = 0, B = 0, A = 0;
	ColorUtils::ToR8G8B8A8(InColor, R, G, B, A);

	for (auto& Unicode : InText)
	{
		SDL_Texture* TextureAtlas = InFont.GetTextureAtlas();

		CHECK((SDL_SetTextureColorMod(TextureAtlas, R, G, B) == 0), SDL_GetError());
		CHECK((SDL_SetTextureAlphaMod(TextureAtlas, A) == 0), SDL_GetError());

		const CharacterInfo& UnicodeInfo = InFont.GetCharacterInfo(static_cast<int32_t>(Unicode));

		SDL_Rect Src =
		{
			UnicodeInfo.Position0.x,
			UnicodeInfo.Position0.y,
			UnicodeInfo.Position1.x - UnicodeInfo.Position0.x,
			UnicodeInfo.Position1.y - UnicodeInfo.Position0.y
		};

		SDL_Rect Dst =
		{
			Position.x + static_cast<int32_t>(UnicodeInfo.XOffset),
			Position.y + static_cast<int32_t>(UnicodeInfo.YOffset),
			(UnicodeInfo.Position1.x - UnicodeInfo.Position0.x),
			(UnicodeInfo.Position1.y - UnicodeInfo.Position0.y)
		};

		SDL_RenderCopy(Renderer_, TextureAtlas, &Src, &Dst);
		Position.x += static_cast<int32_t>(UnicodeInfo.XAdvance);
	}
}

void Renderer::SetDrawColor(const LinearColor& InColor)
{
	uint8_t R = 0, G = 0, B = 0, A = 0;
	ColorUtils::ToR8G8B8A8(InColor, R, G, B, A);
	SetDrawColor(R, G, B, A);
}

void Renderer::SetDrawColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha)
{
	CHECK((SDL_SetRenderDrawColor(Renderer_, InRed, InGreen, InBlue, InAlpha) == 0), SDL_GetError());
}
