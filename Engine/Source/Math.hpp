#pragma once

#include <Vector.hpp>

#include <cmath>
#include <limits>
#include <algorithm>
#include <chrono>
#include <random>
#include <array>


/**
 * float Ÿ���� ����(��) ���Դϴ�.
 */
const float PI_F = 3.1415926535F;


/**
 * double Ÿ���� ����(��) ���Դϴ�.
 */
const double PI_D = 3.1415926535897931;


/**
 * float Ÿ���� Ÿ���� ���Ƿ�(��) ���Դϴ�.
 */
const float EPSILON_F = std::numeric_limits<float>::epsilon();


/**
 * double Ÿ���� ���Ƿ�(��) ���Դϴ�.
 */
const double EPSILON_D = std::numeric_limits<double>::epsilon();


/**
 * float Ÿ���� ���Ѵ� ���Դϴ�.
 */
const float INFINITY_F = std::numeric_limits<float>::infinity();


/**
 * double Ÿ���� ���Ѵ� ���Դϴ�.
 */
const double INFINITY_D = std::numeric_limits<double>::infinity();


/**
 * float Ÿ���� ���� ���Ѵ� ���Դϴ�.
 */
const float NINFINITY_F = -std::numeric_limits<float>::infinity();


/**
 * double Ÿ���� ���� ���Ѵ� ���Դϴ�.
 */
const double NINFINITY_D = -std::numeric_limits<double>::infinity();


/**
 * ��� �����Դϴ�.
 */
using BoundingBox = std::array<Vec2f, 4>;


/**
 * ���� ���� ����� �����ϴ� Ŭ�����Դϴ�.
 */
class Math
{
public:
	/**
	 * ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
	 *
	 * @param InRadian - ��ȯ�� ���� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���ʺй� ���Դϴ�.
	 */
	inline static float ToDegree(float InRadian)
	{
		return (InRadian * 180.0f) / PI_F;
	}


	/**
	 * ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
	 * 
	 * @param InRadian - ��ȯ�� ���� ���Դϴ�.
	 * 
	 * @return ��ȯ�� ���ʺй� ���Դϴ�.
	 */
	inline static double ToDegree(double InRadian)
	{
		return (InRadian * 180.0) / PI_D;
	}


	/**
	 * ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
	 *
	 * @param InDegree - ��ȯ�� ���ʺй� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���� ���Դϴ�.
	 */
	inline static float ToRadian(float InDegree)
	{
		return (InDegree * PI_F) / 180.0f;
	}


	/**
	 * ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
	 * 
	 * @param InDegree - ��ȯ�� ���ʺй� ���Դϴ�.
	 * 
	 * @return ��ȯ�� ���� ���Դϴ�.
	 */
	inline static double ToRadian(double InDegree)
	{
		return (InDegree * PI_D) / 180.0;
	}


	/**
	 * 0�� �Ѿ��� ����� ������ Ȯ���մϴ�.
	 * 
	 * @param InValue - 0�� �Ѿ��� ������� Ȯ���� ���Դϴ�.
	 * @param InEpsilon - ���Ƿ� ���Դϴ�.
	 */
	inline static bool IsNearZero(const float& InValue, const float InEpsilon = EPSILON_F)
	{
		return (fabs(InValue) <= InEpsilon);
	}


	/**
	 * ������ ������ �����մϴ�.
	 *
	 * @param InMinValue - ������ ���� ������ �ּڰ��Դϴ�.
	 * @param InMaxValue - ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return  ������ ������ ������ ��ȯ�մϴ�.
	 */
	template <typename T>
	inline static int32_t GenerateRandomInt(const T& InMinValue, const T& InMaxValue)
	{
		T MinValue = std::min<T>(InMinValue, InMaxValue);
		T MaxValue = std::max<T>(InMinValue, InMaxValue);

		std::random_device RandomDevice;
		std::mt19937 Generator(RandomDevice());
		std::uniform_int_distribution<T> Distribution(InMinValue, InMaxValue);

		return Distribution(Generator);
	}


	/**
	 * ������ �Ǽ��� �����մϴ�.
	 *
	 * @param InMinValue - ������ ���� ������ �ּڰ��Դϴ�.
	 * @param InMaxValue - ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return  ������ ������ �Ǽ��� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline static float GenerateRandomFloat(const T& InMinValue, const T& InMaxValue)
	{
		T MinValue = std::min<T>(InMinValue, InMaxValue);
		T MaxValue = std::max<T>(InMinValue, InMaxValue);

		std::random_device RandomDevice;
		std::mt19937 Generator(RandomDevice());
		std::uniform_real_distribution<T> Distribution(MinValue, MaxValue);

		return Distribution(Generator);
	}


	/**
	 * ���� Ư�� ������ �ڸ��ϴ�.
	 * 
	 * @param Ư�� ������ �ڸ� ���Դϴ�.
	 * @param Ư�� ������ �ּҰ��Դϴ�.
	 * @param Ư�� ������ �ִ밪�Դϴ�.
	 * 
	 * @return Ư�� ������ �ڸ� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline static T Clamp(const T& InValue, const T& InMinValue, const T& InMaxValue)
	{
		return std::clamp<T>(InValue, InMinValue, InMaxValue);
	}


	/**
	 * ��� ���ڸ� ����մϴ�.
	 *
	 * @param InCenter - ��� ������ �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ��� ������ ���� ũ���Դϴ�.
	 * @param InHeight - ��� ������ ���� ũ���Դϴ�.
	 */
	static BoundingBox CalculateBoundingBox(const Vec2f& InCenter, const float& InWidth, const float& InHeight)
	{
		float HalfOfWidth = InWidth / 2.0f;
		float HalfOfHeight = InHeight / 2.0f;

		BoundingBox BoundingPositions = {
			Vec2f(-HalfOfWidth, -HalfOfHeight) + InCenter,
			Vec2f(+HalfOfWidth, -HalfOfHeight) + InCenter,
			Vec2f(+HalfOfWidth, +HalfOfHeight) + InCenter,
			Vec2f(-HalfOfWidth, +HalfOfHeight) + InCenter,
		};

		return BoundingPositions;
	}


	/**
	 * ���� ��� ���� ���� �����ϴ��� �˻��մϴ�.
	 * 
	 * @param InPosition - �˻縦 ������ ���Դϴ�.
	 * @param InBoundingBox - �˻縦 ������ ��� ���� �Դϴ�.
	 * 
	 * @return - ���� ��� ���� ���� ���� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsPositionInsideBoundingBox(const Vec2f& InPosition, const BoundingBox& InBoundingBox)
	{
		Vec2f MinPosition = InBoundingBox[0];
		Vec2f MaxPosition = InBoundingBox[2];

		return (MinPosition.x <= InPosition.x && InPosition.x <= MaxPosition.x)
			&& (MinPosition.y <= InPosition.y && InPosition.y <= MaxPosition.y);
	}


	/**
	 * 2���� float ��ǥ�� pixel ��ǥ�� ��ȯ�մϴ�.
	 * https://www.realtimerendering.com/blog/the-center-of-the-pixel-is-0-50-5/
	 *
	 * @param InPosition - float ��ǥ�Դϴ�.
	 *
	 * @return ��ȯ�� pixel ��ǥ�� ��ȯ�մϴ�.
	 */
	inline static Vec2i ConvertPixelCoordinate(const Vec2f& InPosition)
	{
		return Vec2i(
			static_cast<int32_t>(InPosition.x + 0.5f),
			static_cast<int32_t>(InPosition.y + 0.5f)
		);
	}


	/**
	 * �Է� ���� Normal ���͸� �������κ��� �ݻ� ���͸� ����ϴ�.
	 * �̶�, Normal ���ʹ� �ݵ�� ����ȭ�Ǿ� �־�� �մϴ�.
	 * 
	 * @param InVector - �ݻ� ���͸� ����� �����Դϴ�.
	 * @param InNormal - �ݻ� ���͸� ����� �� ������ �Ǵ� Normal �����Դϴ�.
	 * 
	 * @return �Է� ���� Normal ���͸� �������κ��� ���� �ݻ� ���͸� ��ȯ�մϴ�.
	 */
	inline static Vec2f Reflect(const Vec2f& InVector, const Vec2f& InNormal)
	{
		Vec2f Normal = InNormal;
		float Project = InVector * InNormal;

		Normal.x *= (Project * 2.0f);
		Normal.y *= (Project * 2.0f);

		return InVector - Normal;
	}
};