#pragma once

#include "Macro.h"

#include <string>

struct SDL_Window;


/**
 * 윈도우 옵션 플래그입니다.
 */
enum class EWindowFlags : uint32_t
{
	FULLSCREEN         = 0x00000001,
	OPENGL             = 0x00000002,
	SHOWN              = 0x00000004,
	HIDDEN             = 0x00000008,
	BORDERLESS         = 0x00000010,
	RESIZABLE          = 0x00000020,
	MINIMIZED          = 0x00000040,
	MAXIMIZED          = 0x00000080,
	MOUSE_GRABBED      = 0x00000100,
	INPUT_FOCUS        = 0x00000200,
	MOUSE_FOCUS        = 0x00000400,
	FULLSCREEN_DESKTOP = (FULLSCREEN | 0x00001000),
	FOREIGN            = 0x00000800,
	ALLOW_HIGHDPI      = 0x00002000,
	MOUSE_CAPTURE      = 0x00004000,
	KEYBOARD_GRABBED   = 0x00100000,
	VULKAN             = 0x10000000,
};


/**
 * 윈도우 옵션 플래그의 or 연산을 수행합니다.
 * 
 * @param InLhs - or 연산의 우측 피연산자입니다.
 * @param InRhs - or 연산의 좌측 피연산자입니다.
 * 
 * @return or 연산을 수행한 결과를 반환합니다.
 */
inline EWindowFlags operator|(const EWindowFlags& InLhs, const EWindowFlags& InRhs)
{
	return static_cast<EWindowFlags>(static_cast<uint32_t>(InLhs) | static_cast<uint32_t>(InRhs));
}


/**
 * 윈도우 클래스의 생성자 파라미터입니다.
 */
struct WindowConstructorParam
{
	const std::string& Title;
	int32_t PositionX;
	int32_t PositionY;
	int32_t Width;
	int32_t Height;
	EWindowFlags Flags;
};


/**
 * 윈도우 클래스입니다.
 */
class Window
{
public:
	/**
	 * 윈도우 클래스의 생성자입니다.
	 * 
	 * @param InParam - 윈도우 클래스의 생성 파라미터입니다.
	 * 
	 * @throws 윈도우 생성에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_CreateWindow
	 */
	explicit Window(const WindowConstructorParam& InParam);


	/**
	 * 윈도우 클래스의 생성자입니다.
	 *
	 * @param InTitle - 윈도우의 타이틀입니다.
	 * @param InPositionX - 윈도우 왼쪽 상단의 X좌표입니다.
	 * @param InPositionY - 윈도우 왼쪽 상단의 Y좌표입니다.
	 * @param InWidth - 윈도우의 가로 크기입니다.
	 * @param InHeight - 윈도우의 세로 크기입니다.
	 * @param InFlags - 윈도우 옵션입니다.
	 *
	 * @throws 윈도우 생성에 실패하면 C++ 표준 예외를 던집니다.
	 * 
	 * @see https://wiki.libsdl.org/SDL_CreateWindow
	 */
	explicit Window(
		const std::string& InTitle,
		int32_t InPositionX,
		int32_t InPositionY,
		int32_t InWidth,
		int32_t InHeight,
		const EWindowFlags& InFlags
	);


	/**
	 * 윈도우 클래스의 가상 소멸자입니다
	 */
	virtual ~Window();


	/**
	 * 윈도우 클래스의 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Window);


	/**
	 * 게임 윈도우 위치를 변경합니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param InXPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 X좌표입니다.
	 * @param InYPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 Y좌표입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowPosition
	 */
	void SetPosition(const int32_t& InXPosition, const int32_t& InYPosition);


	/**
	 * 게임 윈도우 위치를 얻습니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param OutXPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 X좌표입니다.
	 * @param OutYPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 Y좌표입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowPosition
	 */
	void GetPosition(int32_t& OutXPosition, int32_t& OutYPosition);


	/**
	 * 게임 윈도우의 크기를 변경합니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param InWidth - 스크린 상의 게임 윈도우의 가로 크기입니다.
	 * @param InHeight - 스크린 상의 게임 윈도우의 세로 크기입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowSize
	 */
	void SetSize(const int32_t& InWidth, const int32_t& InHeight);


	/**
	 * 게임 윈도우의 크기를 얻습니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param InWidth - 스크린 상의 게임 윈도우의 가로 크기입니다.
	 * @param InHeight - 스크린 상의 게임 윈도우의 세로 크기입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowSize
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight);


	/**
	 * 게임 윈도우의 타이틀을 설정합니다.
	 *
	 * @param InTitle - 설정할 게임 윈도우 타이틀입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowTitle
	 */
	void SetTitle(const std::string& InTitle);


	/**
	 * 게임 윈도우의 타이틀을 얻습니다.
	 * 
	 * @return 게임 윈도우 타이틀을 반환합니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowTitle
	 */
	std::string GetTitle();


	/**
	 * 게임 윈도우를 화면에 표시합니다.
	 */
	void Show();


	/**
	 * 게임 윈도우를 화면에서 숨깁니다.
	 */
	void Hide();


	/**
	 * 윈도우의 크기 비율을 얻습니다.
	 * 이때 비율 값은 가로 / 세로 입니다.
	 *
	 * @return 게임 윈도우의 크기 비율을 반환합니다.
	 */
	float GetAspectRatio();


	/**
	 * SDL윈도우의 포인터를 반환합니다.
	 *
	 * @return SDL 윈도우의 포인터를 반환합니다.
	 */
	SDL_Window* GetWindow() { return Window_; }


private:
	/**
	 * SDL 윈도우 포인터입니다.
	 */
	SDL_Window* Window_ = nullptr;
};