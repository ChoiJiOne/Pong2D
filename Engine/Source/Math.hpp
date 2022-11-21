#pragma once

#include <Vector.hpp>

#include <cmath>
#include <limits>
#include <algorithm>
#include <chrono>
#include <random>
#include <array>


/**
 * float 타입의 파이(π) 값입니다.
 */
const float PI_F = 3.1415926535F;


/**
 * double 타입의 파이(π) 값입니다.
 */
const double PI_D = 3.1415926535897931;


/**
 * float 타입의 타입의 엡실론(ε) 값입니다.
 */
const float EPSILON_F = std::numeric_limits<float>::epsilon();


/**
 * double 타입의 엡실론(ε) 값입니다.
 */
const double EPSILON_D = std::numeric_limits<double>::epsilon();


/**
 * float 타입의 무한대 값입니다.
 */
const float INFINITY_F = std::numeric_limits<float>::infinity();


/**
 * double 타입의 무한대 값입니다.
 */
const double INFINITY_D = std::numeric_limits<double>::infinity();


/**
 * float 타입의 음의 무한대 값입니다.
 */
const float NINFINITY_F = -std::numeric_limits<float>::infinity();


/**
 * double 타입의 음의 무한대 값입니다.
 */
const double NINFINITY_D = -std::numeric_limits<double>::infinity();


/**
 * 경계 상자입니다.
 */
using BoundingBox = std::array<Vec2f, 4>;


/**
 * 수학 관련 기능을 제공하는 클래스입니다.
 */
class Math
{
public:
	/**
	 * 라디안 각을 육십분법 각으로 변환합니다.
	 *
	 * @param InRadian - 변환할 라디안 각입니다.
	 *
	 * @return 변환된 육십분법 각입니다.
	 */
	inline static float ToDegree(float InRadian)
	{
		return (InRadian * 180.0f) / PI_F;
	}


	/**
	 * 라디안 각을 육십분법 각으로 변환합니다.
	 * 
	 * @param InRadian - 변환할 라디안 각입니다.
	 * 
	 * @return 변환된 육십분법 각입니다.
	 */
	inline static double ToDegree(double InRadian)
	{
		return (InRadian * 180.0) / PI_D;
	}


	/**
	 * 육십분법 각을 라디안 각으로 변환합니다.
	 *
	 * @param InDegree - 변환할 육십분법 각입니다.
	 *
	 * @return 변환된 라디안 각입니다.
	 */
	inline static float ToRadian(float InDegree)
	{
		return (InDegree * PI_F) / 180.0f;
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
		return (InDegree * PI_D) / 180.0;
	}


	/**
	 * 0에 한없이 가까운 값인지 확인합니다.
	 * 
	 * @param InValue - 0에 한없이 가까운지 확인할 값입니다.
	 * @param InEpsilon - 엡실론 값입니다.
	 */
	inline static bool IsNearZero(const float& InValue, const float InEpsilon = EPSILON_F)
	{
		return (fabs(InValue) <= InEpsilon);
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
	 * 경계 상자를 계산합니다.
	 *
	 * @param InCenter - 경계 영역의 중심 좌표입니다.
	 * @param InWidth - 경계 영역의 가로 크기입니다.
	 * @param InHeight - 경계 영역의 세로 크기입니다.
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
	 * 점이 경계 상자 내에 존재하는지 검사합니다.
	 * 
	 * @param InPosition - 검사를 수행할 점입니다.
	 * @param InBoundingBox - 검사를 수행할 경계 상자 입니다.
	 * 
	 * @return - 점이 경계 상자 영역 내에 존재하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsPositionInsideBoundingBox(const Vec2f& InPosition, const BoundingBox& InBoundingBox)
	{
		Vec2f MinPosition = InBoundingBox[0];
		Vec2f MaxPosition = InBoundingBox[2];

		return (MinPosition.x <= InPosition.x && InPosition.x <= MaxPosition.x)
			&& (MinPosition.y <= InPosition.y && InPosition.y <= MaxPosition.y);
	}


	/**
	 * 2차원 float 좌표를 pixel 좌표로 변환합니다.
	 * https://www.realtimerendering.com/blog/the-center-of-the-pixel-is-0-50-5/
	 *
	 * @param InPosition - float 좌표입니다.
	 *
	 * @return 변환된 pixel 좌표를 반환합니다.
	 */
	inline static Vec2i ConvertPixelCoordinate(const Vec2f& InPosition)
	{
		return Vec2i(
			static_cast<int32_t>(InPosition.x + 0.5f),
			static_cast<int32_t>(InPosition.y + 0.5f)
		);
	}


	/**
	 * 입력 받은 Normal 벡터를 기준으로부터 반사 벡터를 얻습니다.
	 * 이때, Normal 벡터는 반드시 정규화되어 있어야 합니다.
	 * 
	 * @param InVector - 반사 벡터를 계산할 벡터입니다.
	 * @param InNormal - 반사 벡터를 계산할 때 기준이 되는 Normal 벡터입니다.
	 * 
	 * @return 입력 받은 Normal 벡터를 기준으로부터 계산된 반사 벡터를 반환합니다.
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