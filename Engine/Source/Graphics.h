#pragma once

#include "Macro.h"
#include "ColorUtils.h"

class Body;
class Window;
class Texture;
class Font;
struct SDL_Renderer;


/**
 * 그래픽스 옵션 플래그입니다.
 * 
 * @see https://wiki.libsdl.org/SDL_RendererFlags
 */
enum class EGraphicsFlags : int32_t
{
	SOFTWARE = 0x00000001,
	ACCELERATED = 0x00000002,
	PRESENTVSYNC = 0x00000004,
	TARGETTEXTURE = 0x00000008
};


/**
 * 그래픽스 옵션 플래그의 or 연산을 수행합니다.
 *
 * @param InLhs - or 연산의 우측 피연산자입니다.
 * @param InRhs - or 연산의 좌측 피연산자입니다.
 *
 * @return or 연산을 수행한 결과를 반환합니다.
 */
inline EGraphicsFlags operator|(const EGraphicsFlags& InLhs, const EGraphicsFlags& InRhs)
{
	return static_cast<EGraphicsFlags>(static_cast<uint32_t>(InLhs) | static_cast<uint32_t>(InRhs));
}


/**
 * 게임 내에 그래픽스 관련 처리를 하는 클래스입니다.
 */
class Graphics
{
public:
	/**
	 * 그래픽스 클래스의 생성자입니다.
	 * @see https://wiki.libsdl.org/SDL_CreateRenderer
	 * 
	 * @param InWindow - 그래픽스 클래스 초기화 시 참조할 윈도우 클래스의 인스턴스입니다.
	 * @param InFlags - 그래픽스 생성 옵션입니다.
	 * 
	 * @throws 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 * 
	 * @see https://wiki.libsdl.org/SDL_CreateRenderer
	 */
	explicit Graphics(Window& InWindow, const EGraphicsFlags& InFlags);


	/**
	 * 그래픽스 클래스의 가상 소멸자입니다.
	 */
	virtual ~Graphics();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Graphics);


	/**
	 * 프레임 렌더링을 시작합니다.
	 *
	 * @param InColor - 벡버퍼를 비울 색상입니다.
	 *
	 * @throws 백버퍼 초기화에 실패할 경우, C++ 표준 예외를 던집니다.
	 */
	void BeginFrame(const LinearColor& InColor);


	/**
	 * 프레임 렌더링을 종료하고, 벡버퍼를 화면에 표시합니다.
	 */
	void EndFrame();


	/**
	 * SDL 렌더러의 포인터를 얻습니다.
	 *
	 * @return SDL 렌더러의 포인터를 반환합니다.
	 */
	SDL_Renderer* GetRenderer() { return Renderer_; }


	/**
	 * 벡버퍼에 2D 점을 그립니다.
	 *
	 * @param InPosition - 점의 위치입니다.
	 * @param InColor - 점의 색상입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawPoint2D(const Vec2i& InPosition, const LinearColor& InColor);


	/**
	 * 벡버퍼에 2D 선을 그립니다.
	 *
	 * @param InPosition0 - 선분의 한 끝점입니다.
	 * @param InPosition1 - 선분의 다른 한 끝점입니다.
	 * @param InColor - 선분의 색상입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawLine2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor);


	/**
	 * 벡버퍼에 2D 사각형을 그립니다.
	 *
	 * @param InPosition0 - 사각형의 왼쪽 상단점입니다.
	 * @param InPosition1 - 사각형의 오른쪽 하단점입니다.
	 * @param InColor - 사각형의 색상입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawRect2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor);


	/**
	 * 벡버퍼에 2D 사각형을 그립니다.
	 *
	 * @param InCenterPosition - 사각형의 중심이 위치할 화면상의 좌표입니다.
	 * @param InWidth - 사각형의 가로 길이입니다.
	 * @param InHeight - 사각형의 세로 길이입니다.
	 * @param InColor - 사각형의 색상입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor);


	/**
	 * 벡버퍼에 채움 2D 사각형을 그립니다.
	 *
	 * @param InPosition0 - 채움 사각형의 왼쪽 상단점입니다.
	 * @param InPosition1 - 채움 사각형의 오른쪽 하단점입니다.
	 * @param InColor - 채움 사각형의 색상입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawFillRect2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor);


	/**
	 * 벡버퍼에 채움 2D 사각형을 그립니다.
	 *
	 * @param InCenterPosition - 사각형의 중심이 위치할 화면상의 좌표입니다.
	 * @param InWidth - 사각형의 가로 길이입니다.
	 * @param InHeight - 사각형의 세로 길이입니다
	 * @param InColor - 사각형의 색상입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawFillRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor);


	/**
	 * 백버퍼에 텍스처를 그립니다.
	 * 이때, 회전 각도는 60분법 기준입니다.
	 *
	 * @param InTexture - 벡버퍼에 그릴 텍스처입니다.
	 * @param InPosition0 - 텍스처의 왼쪽 상단이 위치할 화면상의 좌표입니다.
	 * @param InPosition1 - 텍스처의 왼쪽 상단이 위치할 화면상의 좌표입니다.
	 * @param InRotateAngle - 렌더링할 텍스처의 회전 각도입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawTexture2D(Texture& InTexture, const Vec2i& InPosition0, const Vec2i& InPosition1, float InRotateAngle = 0.0f);


	/**
	 * 백버퍼에 텍스처를 그립니다.
	 * 이때, 회전 각도는 60분법 기준입니다.
	 *
	 * @param InTexture - 벡버퍼에 그릴 텍스처입니다.
	 * @param InCenterPosition - 텍스처의 중심이 위치할 화면상의 좌표입니다.
	 * @param InWidth- 백버퍼에 렌더링할 텍스처의 가로 크기 입니다
	 * @param InHeight- 백버퍼에 렌더링할 텍스처의 원본 텍스처 대비 세로 크기 비율입니다.
	 * @param InRotateAngle - 렌더링할 텍스처의 회전 각도입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, float InRotateAngle = 0.0f);


	/**
	 * 백버퍼에 텍스처 원본을 그립니다.
	 * 이때, 회전 각도는 60분법 기준입니다.
	 *
	 * @param InTexture - 벡버퍼에 그릴 텍스처입니다.
	 * @param InCenterPosition - 텍스처의 중심이 위치할 화면상의 좌표입니다.
	 * @param InRotateAngle - 렌더링할 텍스처의 회전 각도입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, float InRotateAngle = 0.0f);


	/**
	 * 벡버퍼에 텍스트를 그립니다.
	 *
	 * @param InFont- 트루 타입 폰트입니다.
	 * @param InText - 벡버퍼에 그릴 텍스트입니다.
	 * @param InCenterPosition - 텍스트의 중심이 위치할 화면상의 좌표입니다.
	 * @param InColor - 텍스트의 색상입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawText2D(Font& InFont, const std::wstring& InText, const Vec2i& InCenterPosition, const LinearColor& InColor);


	/**
	 * 벡버퍼에 오브젝트 몸체의 외곽선을 그립니다.
	 * 
	 * @param InBody - 외곽선을 그릴 오브젝트의 몸체입니다.
	 * @param InColor - 외곽선의 색상입니다.
	 * 
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void DrawBodyOutline(Body& InBody, const LinearColor& InColor);


private:
	/**
	 * SDL 렌더러의 컬러 상태를 설정합니다.
	 *
	 * @param InColor - 변경할 SDL 렌더러의 컬러 상태입니다.
	 *
	 * @throws 렌더 색상 설정에 실패할 경우, C++ 표준 예외를 던집니다.
	 */
	void SetDrawColor(const LinearColor& InColor);


	/**
	 * SDL 렌더러의 컬러 상태를 설정합니다.
	 *
	 * @param InRed - 변경할 SDL 렌더러의 컬러 Red값 입니다.
	 * @param InGreen - 변경할 SDL 렌더러의 컬러 Green값 입니다.
	 * @param InBlue - 변경할 SDL 렌더러의 컬러 Blue값 입니다.
	 * @param InAlpha - 변경할 SDL 렌더러의 컬러 Alpha값 입니다.
	 *
	 * @throws 렌더 색상 설정에 실패할 경우, C++ 표준 예외를 던집니다.
	 */
	void SetDrawColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha);


private:
	/**
	 * 그래픽스 내에서 관리하는 SDL 렌더러입니다.
	 */
	SDL_Renderer* Renderer_ = nullptr;
};