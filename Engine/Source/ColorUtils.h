#pragma once

#include "Vector.h"


/**
 * 32bit 압축 RGBA 색상을 정의합니다.
 */
using RGBA32 = uint32_t;


/**
 * 선형 색상을 정의합니다.
 */
using LinearColor = Vec4f;


/**
 * 색상 관련 기능을 제공하는 클래스입니다.
 */
class ColorUtils
{
public:
	/**
	 * 검정색입니다.
	 */
	static LinearColor Black;


	/**
	 * 빨간색입니다.
	 */
	static LinearColor Red;


	/**
	 * 초록색입니다.
	 */
	static LinearColor Green;


	/**
	 * 파란색입니다.
	 */
	static LinearColor Blue;


	/**
	 * 노란색입니다.
	 */
	static LinearColor Yellow;


	/**
	 * 마젠타색입니다.
	 */
	static LinearColor Magenta;


	/**
	 * 시얀색입니다.
	 */
	static LinearColor Cyan;


	/**
	 * 하얀색입니다.
	 */
	static LinearColor White;


	/**
	 * 회색입니다.
	 */
	static LinearColor Gray;


	/**
	 * R8, G8, B8, A8 값을 RGBA32로 변환합니다.
	 *
	 * @param InRed - 색상 변환을 수행할 R값입니다.
	 * @param InGreen - 색상 변환을 수행할 G값입니다.
	 * @param InBlue - 색상 변환을 수행할 B값입니다.
	 * @param InAlpha - 색상 변환을 수행할 A값입니다.
	 *
	 * @return  변환된 RGBA32를 반환합니다.
	 */
	static RGBA32 ToRGBA32(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha);


	/**
	 * LinearColor 값을 RGBA32 값으로 변환합니다.
	 *
	 * @param InColor - 변환을 수행할 LinearColor 입니다.
	 *
	 * @return  변환이 완료된 RGBA32 값입니다.
	 */
	static RGBA32 ToRGBA32(const LinearColor& InColor);


	/**
	 * R8, G8, B8, A8 값을 LinearColor로 변환합니다.
	 *
	 * @param InRed - 색상 변환을 수행할 R값입니다.
	 * @param InGreen - 색상 변환을 수행할 G값입니다.
	 * @param InBlue - 색상 변환을 수행할 B값입니다.
	 * @param InAlpha - 색상 변환을 수행할 A값입니다.
	 *
	 * @return  변환된 LinearColor를 반환합니다.
	 */
	static LinearColor ToLinearColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha);


	/**
	 * RGBA32 값을 LinearColor 값으로 변환합니다.
	 *
	 * @param InRGBA32 - 변환을 수행할 RGBA 값입니다.
	 *
	 * @return  변환이 완료된 LinearColor 값입니다.
	 */
	static LinearColor ToLinearColor(const RGBA32& InRGBA32);


	/**
	 * RGBA32 값을 R8G8B8A8 값으로 변환합니다.
	 *
	 * @param InRGBA32 - 변환을 수행할 RGBA 값입니다.
	 * @param OutRed - 변환이 완료된 R값입니다.
	 * @param OutGreen - 변환이 완료된 G값입니다.
	 * @param OutBlue - 변환이 완료된 B값입니다.
	 * @param OutAlpha - 변환이 완료된 A값입니다.
	 */
	static void ToR8G8B8A8(const RGBA32& InRGBA32, uint8_t& OutRed, uint8_t& OutGreen, uint8_t& OutBlue, uint8_t& OutAlpha);


	/**
	 * LinearColor 값을 R8G8B8A8 값으로 변환합니다.
	 *
	 * @param InColor - 변환을 수행할 LinearColor 입니다.
	 * @param OutRed - 변환이 완료된 R값입니다.
	 * @param OutGreen - 변환이 완료된 G값입니다.
	 * @param OutBlue - 변환이 완료된 B값입니다.
	 * @param OutAlpha - 변환이 완료된 A값입니다.
	 */
	static void ToR8G8B8A8(const LinearColor& InColor, uint8_t& OutRed, uint8_t& OutGreen, uint8_t& OutBlue, uint8_t& OutAlpha);
};