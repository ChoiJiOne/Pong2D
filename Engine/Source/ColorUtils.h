#pragma once

#include "Vector.h"


/**
 * 32bit ���� RGBA ������ �����մϴ�.
 */
using RGBA32 = uint32_t;


/**
 * ���� ������ �����մϴ�.
 */
using LinearColor = Vec4f;


/**
 * ���� ���� ����� �����ϴ� Ŭ�����Դϴ�.
 */
class ColorUtils
{
public:
	/**
	 * �������Դϴ�.
	 */
	static LinearColor Black;


	/**
	 * �������Դϴ�.
	 */
	static LinearColor Red;


	/**
	 * �ʷϻ��Դϴ�.
	 */
	static LinearColor Green;


	/**
	 * �Ķ����Դϴ�.
	 */
	static LinearColor Blue;


	/**
	 * ������Դϴ�.
	 */
	static LinearColor Yellow;


	/**
	 * ����Ÿ���Դϴ�.
	 */
	static LinearColor Magenta;


	/**
	 * �þ���Դϴ�.
	 */
	static LinearColor Cyan;


	/**
	 * �Ͼ���Դϴ�.
	 */
	static LinearColor White;


	/**
	 * ȸ���Դϴ�.
	 */
	static LinearColor Gray;


	/**
	 * R8, G8, B8, A8 ���� RGBA32�� ��ȯ�մϴ�.
	 *
	 * @param InRed - ���� ��ȯ�� ������ R���Դϴ�.
	 * @param InGreen - ���� ��ȯ�� ������ G���Դϴ�.
	 * @param InBlue - ���� ��ȯ�� ������ B���Դϴ�.
	 * @param InAlpha - ���� ��ȯ�� ������ A���Դϴ�.
	 *
	 * @return  ��ȯ�� RGBA32�� ��ȯ�մϴ�.
	 */
	static RGBA32 ToRGBA32(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha);


	/**
	 * LinearColor ���� RGBA32 ������ ��ȯ�մϴ�.
	 *
	 * @param InColor - ��ȯ�� ������ LinearColor �Դϴ�.
	 *
	 * @return  ��ȯ�� �Ϸ�� RGBA32 ���Դϴ�.
	 */
	static RGBA32 ToRGBA32(const LinearColor& InColor);


	/**
	 * R8, G8, B8, A8 ���� LinearColor�� ��ȯ�մϴ�.
	 *
	 * @param InRed - ���� ��ȯ�� ������ R���Դϴ�.
	 * @param InGreen - ���� ��ȯ�� ������ G���Դϴ�.
	 * @param InBlue - ���� ��ȯ�� ������ B���Դϴ�.
	 * @param InAlpha - ���� ��ȯ�� ������ A���Դϴ�.
	 *
	 * @return  ��ȯ�� LinearColor�� ��ȯ�մϴ�.
	 */
	static LinearColor ToLinearColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha);


	/**
	 * RGBA32 ���� LinearColor ������ ��ȯ�մϴ�.
	 *
	 * @param InRGBA32 - ��ȯ�� ������ RGBA ���Դϴ�.
	 *
	 * @return  ��ȯ�� �Ϸ�� LinearColor ���Դϴ�.
	 */
	static LinearColor ToLinearColor(const RGBA32& InRGBA32);


	/**
	 * RGBA32 ���� R8G8B8A8 ������ ��ȯ�մϴ�.
	 *
	 * @param InRGBA32 - ��ȯ�� ������ RGBA ���Դϴ�.
	 * @param OutRed - ��ȯ�� �Ϸ�� R���Դϴ�.
	 * @param OutGreen - ��ȯ�� �Ϸ�� G���Դϴ�.
	 * @param OutBlue - ��ȯ�� �Ϸ�� B���Դϴ�.
	 * @param OutAlpha - ��ȯ�� �Ϸ�� A���Դϴ�.
	 */
	static void ToR8G8B8A8(const RGBA32& InRGBA32, uint8_t& OutRed, uint8_t& OutGreen, uint8_t& OutBlue, uint8_t& OutAlpha);


	/**
	 * LinearColor ���� R8G8B8A8 ������ ��ȯ�մϴ�.
	 *
	 * @param InColor - ��ȯ�� ������ LinearColor �Դϴ�.
	 * @param OutRed - ��ȯ�� �Ϸ�� R���Դϴ�.
	 * @param OutGreen - ��ȯ�� �Ϸ�� G���Դϴ�.
	 * @param OutBlue - ��ȯ�� �Ϸ�� B���Դϴ�.
	 * @param OutAlpha - ��ȯ�� �Ϸ�� A���Դϴ�.
	 */
	static void ToR8G8B8A8(const LinearColor& InColor, uint8_t& OutRed, uint8_t& OutGreen, uint8_t& OutBlue, uint8_t& OutAlpha);
};