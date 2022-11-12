#include "Graphics.h"
#include "Body.h"
#include "Window.h"
#include "Texture.h"
#include "Font.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

Graphics::Graphics(Window& InWindow, const EGraphicsFlags& InFlags)
{
	Renderer_ = SDL_CreateRenderer(InWindow.GetWindow(), -1, static_cast<uint32_t>(InFlags));
	CHECK((Renderer_ != nullptr), "failed to create renderer");
}

Graphics::~Graphics()
{
	if (Renderer_)
	{
		SDL_DestroyRenderer(Renderer_);
		Renderer_ = nullptr;
	}
}

void Graphics::BeginFrame(const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderClear(Renderer_) == 0), SDL_GetError());
}

void Graphics::EndFrame()
{
	SDL_RenderPresent(Renderer_);
}

void Graphics::DrawPoint2D(const Vec2i& InPosition, const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderDrawPoint(Renderer_, InPosition.x, InPosition.y) == 0), SDL_GetError());
}

void Graphics::DrawLine2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderDrawLine(Renderer_, InPosition0.x, InPosition0.y, InPosition1.x, InPosition1.y) == 0), SDL_GetError());
}

void Graphics::DrawRect2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor)
{
	SetDrawColor(InColor);

	SDL_Rect Rect = {
		std::min(InPosition0.x, InPosition1.x),
		std::min(InPosition0.y, InPosition1.y),
		std::abs(InPosition1.x - InPosition0.x),
		std::abs(InPosition1.y - InPosition0.y)
	};

	CHECK((SDL_RenderDrawRect(Renderer_, &Rect) == 0), SDL_GetError());
}

void Graphics::DrawRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i Position0 = InCenterPosition - DeltaPosition;
	Vec2i Position1 = InCenterPosition + DeltaPosition;

	DrawRect2D(Position0, Position1, InColor);
}

void Graphics::DrawFillRect2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor)
{
	SetDrawColor(InColor);

	SDL_Rect Rect = {
		std::min(InPosition0.x, InPosition1.x),
		std::min(InPosition0.y, InPosition1.y),
		std::abs(InPosition1.x - InPosition0.x),
		std::abs(InPosition1.y - InPosition0.y)
	};

	CHECK((SDL_RenderFillRect(Renderer_, &Rect) == 0), SDL_GetError());
}

void Graphics::DrawFillRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i Position0 = InCenterPosition - DeltaPosition;
	Vec2i Position1 = InCenterPosition + DeltaPosition;

	DrawFillRect2D(Position0, Position1, InColor);
}

void Graphics::DrawTexture2D(Texture& InTexture, const Vec2i& InPosition0, const Vec2i& InPosition1, float InRotateAngle)
{
	SDL_Rect Rect = {
		std::min(InPosition0.x, InPosition1.x),
		std::min(InPosition0.y, InPosition1.y),
		std::abs(InPosition1.x - InPosition0.x),
		std::abs(InPosition1.y - InPosition0.y),
	};

	CHECK((SDL_RenderCopyEx(Renderer_, InTexture.GetTexture(), nullptr, &Rect, InRotateAngle, nullptr, SDL_FLIP_NONE) == 0), SDL_GetError());
}

void Graphics::DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, float InRotateAngle)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i Position0 = InCenterPosition - DeltaPosition;
	Vec2i Position1 = InCenterPosition + DeltaPosition;

	DrawTexture2D(InTexture, Position0, Position1, InRotateAngle);
}

void Graphics::DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, float InRotateAngle)
{
	int32_t TextureWidth = 0;
	int32_t TextureHeight = 0;
	InTexture.GetSize(TextureWidth, TextureHeight);

	DrawTexture2D(InTexture, InCenterPosition, TextureWidth, TextureHeight, InRotateAngle);
}

void Graphics::DrawText2D(Font& InFont, const std::wstring& InText, const Vec2i& InCenterPosition, const LinearColor& InColor)
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

void Graphics::DrawBodyOutline(Body& InBody, const LinearColor& InColor)
{
	const std::array<Vec2f, 4>& Positions = InBody.GetBoundingPositions();

	for (std::size_t Index = 0; Index < Positions.size(); ++Index)
	{
		DrawLine2D(
			Vec2i(static_cast<int32_t>(Positions[Index].x + 0.5f), static_cast<int32_t>(Positions[Index].y + 0.5f)),
			Vec2i(static_cast<int32_t>(Positions[(Index + 1) % Positions.size()].x + 0.5f), static_cast<int32_t>(Positions[(Index + 1) % Positions.size()].y + 0.5f)),
			ColorUtils::Black
		);
	}
}

void Graphics::SetDrawColor(const LinearColor& InColor)
{
	uint8_t R = 0, G = 0, B = 0, A = 0;
	ColorUtils::ToR8G8B8A8(InColor, R, G, B, A);
	SetDrawColor(R, G, B, A);
}

void Graphics::SetDrawColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha)
{
	CHECK((SDL_SetRenderDrawColor(Renderer_, InRed, InGreen, InBlue, InAlpha) == 0), SDL_GetError());
}
