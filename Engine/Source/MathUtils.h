#pragma once

#include <cmath>
#include <algorithm>
#include <chrono>
#include <random>


/**
 * ����(��) ���Դϴ�.
 */
const double PI = 3.1415926535897931;


/**
 * ���Ƿ�(��) ���Դϴ�.
 */
const double EPSILON = 4.94065645841247E-324;


/**
 * ���� ���� ����� �����ϴ� Ŭ�����Դϴ�.
 */
class MathUtils
{
public:
	/**
	 * ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
	 * 
	 * @param InRadian - ��ȯ�� ���� ���Դϴ�.
	 * 
	 * @return ��ȯ�� ���ʺй� ���Դϴ�.
	 */
	inline static double ToDegree(double InRadian)
	{
		return (InRadian * 180.0) / PI;
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
		return (InDegree * PI) / 180.0;
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
	 * ��� ���� ������ ����մϴ�.
	 *
	 * @param InCenter - ��� ������ �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ��� ������ ���� ũ���Դϴ�.
	 * @param InHeight - ��� ������ ���� ũ���Դϴ�.
	 */
	static std::array<Vec2f, 4> CalculateBoundingPositions(const Vec2f& InCenter, const float& InWidth, const float& InHeight)
	{
		float HalfOfWidth = InWidth / 2.0f;
		float HalfOfHeight = InHeight / 2.0f;

		std::array<Vec2f, 4> BoundingPositions = {
			Vec2f(-HalfOfWidth, -HalfOfHeight) + InCenter,
			Vec2f(+HalfOfWidth, -HalfOfHeight) + InCenter,
			Vec2f(+HalfOfWidth, +HalfOfHeight) + InCenter,
			Vec2f(-HalfOfWidth, +HalfOfHeight) + InCenter,
		};

		return BoundingPositions;
	}
};