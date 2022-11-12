#pragma once

#include <cmath>
#include <algorithm>
#include <chrono>
#include <random>


/**
 * 파이(π) 값입니다.
 */
const double PI = 3.1415926535897931;


/**
 * 엡실론(ε) 값입니다.
 */
const double EPSILON = 4.94065645841247E-324;


/**
 * 수학 관련 기능을 제공하는 클래스입니다.
 */
class MathUtils
{
public:
	/**
	 * 라디안 각을 육십분법 각으로 변환합니다.
	 * 
	 * @param InRadian - 변환할 라디안 각입니다.
	 * 
	 * @return 변환된 육십분법 각입니다.
	 */
	inline static double ToDegree(double InRadian)
	{
		return (InRadian * 180.0) / PI;
	}


	/**
	 * 육십분법 각을 라디안 각으로 변환합니다.
	 * 
	 * @param InDegree - 변환할 육십분법 각입니다.
	 * 
	 * @return 변환된 라디안 각입니다.
	 */
	inline static double ToRadian(double InDegree)
	{
		return (InDegree * PI) / 180.0;
	}


	/**
	 * 임의의 정수를 생성합니다.
	 *
	 * @param InMinValue - 생성할 난수 범위의 최솟값입니다.
	 * @param InMaxValue - 생성할 난수 범위의 최댓값입니다.
	 *
	 * @return  생성된 임의의 정수를 반환합니다.
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
	 * 임의의 실수를 생성합니다.
	 *
	 * @param InMinValue - 생성할 난수 범위의 최솟값입니다.
	 * @param InMaxValue - 생성할 난수 범위의 최댓값입니다.
	 *
	 * @return  생성된 임의의 실수를 반환합니다.
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
	 * 값을 특정 범위로 자릅니다.
	 * 
	 * @param 특정 범위로 자를 값입니다.
	 * @param 특정 범위의 최소값입니다.
	 * @param 특정 범위의 최대값입니다.
	 * 
	 * @return 특정 범위로 자른 값을 반환합니다.
	 */
	template <typename T>
	inline static T Clamp(const T& InValue, const T& InMinValue, const T& InMaxValue)
	{
		return std::clamp<T>(InValue, InMinValue, InMaxValue);
	}


	/**
	 * 경계 영역 점들을 계산합니다.
	 *
	 * @param InCenter - 경계 영역의 중심 좌표입니다.
	 * @param InWidth - 경계 영역의 가로 크기입니다.
	 * @param InHeight - 경계 영역의 세로 크기입니다.
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