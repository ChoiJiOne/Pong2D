#include <Color.h>
#include <Math.hpp>

#include <algorithm>

LinearColor Color::Black   = LinearColor(0.0f, 0.0f, 0.0f, 1.0f);
LinearColor Color::Red     = LinearColor(1.0f, 0.0f, 0.0f, 1.0f);
LinearColor Color::Green   = LinearColor(0.0f, 1.0f, 0.0f, 1.0f);
LinearColor Color::Blue    = LinearColor(0.0f, 0.0f, 1.0f, 1.0f);
LinearColor Color::Yellow  = LinearColor(1.0f, 1.0f, 0.0f, 1.0f);
LinearColor Color::Magenta = LinearColor(1.0f, 0.0f, 1.0f, 1.0f);
LinearColor Color::Cyan    = LinearColor(0.0f, 1.0f, 1.0f, 1.0f);
LinearColor Color::White   = LinearColor(1.0f, 1.0f, 1.0f, 1.0f);
LinearColor Color::Gray    = LinearColor(0.5f, 0.5f, 0.5f, 1.0f);

RGBA32 Color::ToRGBA32(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha)
{
	return (InAlpha << 24) + (InBlue << 16) + (InGreen << 8) + (InRed << 0);
}

RGBA32 Color::ToRGBA32(const LinearColor& InColor)
{
	uint8_t R = 0, G = 0, B = 0, A = 0;
	ToR8G8B8A8(InColor, R, G, B, A);
	return ToRGBA32(R, G, B, A);
}

LinearColor Color::ToLinearColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha)
{
	return LinearColor(
		Math::Clamp<float>(static_cast<float>(InRed)   / 255.0f, 0.0f, 1.0f),
		Math::Clamp<float>(static_cast<float>(InGreen) / 255.0f, 0.0f, 1.0f),
		Math::Clamp<float>(static_cast<float>(InBlue)  / 255.0f, 0.0f, 1.0f),
		Math::Clamp<float>(static_cast<float>(InAlpha) / 255.0f, 0.0f, 1.0f)
	);
}

LinearColor Color::ToLinearColor(const RGBA32& InRGBA32)
{
	uint8_t R = 0, G = 0, B = 0, A = 0;
	ToR8G8B8A8(InRGBA32, R, G, B, A);
	return ToLinearColor(R, G, B, A);
}

void Color::ToR8G8B8A8(const RGBA32& InRGBA32, uint8_t& OutRed, uint8_t& OutGreen, uint8_t& OutBlue, uint8_t& OutAlpha)
{
	OutRed   = (InRGBA32 >>  0) & 255;
	OutGreen = (InRGBA32 >>  8) & 255;
	OutBlue  = (InRGBA32 >> 16) & 255;
	OutAlpha = (InRGBA32 >> 24) & 255;
}

void Color::ToR8G8B8A8(const LinearColor& InColor, uint8_t& OutRed, uint8_t& OutGreen, uint8_t& OutBlue, uint8_t& OutAlpha)
{
	OutRed   = static_cast<uint8_t>(Math::Clamp<float>(InColor.x, 0.0f, 1.0f) * 255.0f);
	OutGreen = static_cast<uint8_t>(Math::Clamp<float>(InColor.y, 0.0f, 1.0f) * 255.0f);
	OutBlue  = static_cast<uint8_t>(Math::Clamp<float>(InColor.z, 0.0f, 1.0f) * 255.0f);
	OutAlpha = static_cast<uint8_t>(Math::Clamp<float>(InColor.w, 0.0f, 1.0f) * 255.0f);
}