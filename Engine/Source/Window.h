#pragma once

#include "Macro.h"

#include <string>

struct SDL_Window;


/**
 * ������ �ɼ� �÷����Դϴ�.
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
 * ������ �ɼ� �÷����� or ������ �����մϴ�.
 * 
 * @param InLhs - or ������ ���� �ǿ������Դϴ�.
 * @param InRhs - or ������ ���� �ǿ������Դϴ�.
 * 
 * @return or ������ ������ ����� ��ȯ�մϴ�.
 */
inline EWindowFlags operator|(const EWindowFlags& InLhs, const EWindowFlags& InRhs)
{
	return static_cast<EWindowFlags>(static_cast<uint32_t>(InLhs) | static_cast<uint32_t>(InRhs));
}


/**
 * ������ Ŭ������ ������ �Ķ�����Դϴ�.
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
 * ������ Ŭ�����Դϴ�.
 */
class Window
{
public:
	/**
	 * ������ Ŭ������ �������Դϴ�.
	 * 
	 * @param InParam - ������ Ŭ������ ���� �Ķ�����Դϴ�.
	 * 
	 * @throws ������ ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_CreateWindow
	 */
	explicit Window(const WindowConstructorParam& InParam);


	/**
	 * ������ Ŭ������ �������Դϴ�.
	 *
	 * @param InTitle - �������� Ÿ��Ʋ�Դϴ�.
	 * @param InPositionX - ������ ���� ����� X��ǥ�Դϴ�.
	 * @param InPositionY - ������ ���� ����� Y��ǥ�Դϴ�.
	 * @param InWidth - �������� ���� ũ���Դϴ�.
	 * @param InHeight - �������� ���� ũ���Դϴ�.
	 * @param InFlags - ������ �ɼ��Դϴ�.
	 *
	 * @throws ������ ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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
	 * ������ Ŭ������ ���� �Ҹ����Դϴ�
	 */
	virtual ~Window();


	/**
	 * ������ Ŭ������ ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Window);


	/**
	 * ���� ������ ��ġ�� �����մϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param InXPosition - ��ũ�� ���� ���� ������ ���� ����� X��ǥ�Դϴ�.
	 * @param InYPosition - ��ũ�� ���� ���� ������ ���� ����� Y��ǥ�Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowPosition
	 */
	void SetPosition(const int32_t& InXPosition, const int32_t& InYPosition);


	/**
	 * ���� ������ ��ġ�� ����ϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param OutXPosition - ��ũ�� ���� ���� ������ ���� ����� X��ǥ�Դϴ�.
	 * @param OutYPosition - ��ũ�� ���� ���� ������ ���� ����� Y��ǥ�Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowPosition
	 */
	void GetPosition(int32_t& OutXPosition, int32_t& OutYPosition);


	/**
	 * ���� �������� ũ�⸦ �����մϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param InWidth - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 * @param InHeight - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowSize
	 */
	void SetSize(const int32_t& InWidth, const int32_t& InHeight);


	/**
	 * ���� �������� ũ�⸦ ����ϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param InWidth - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 * @param InHeight - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowSize
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight);


	/**
	 * ���� �������� Ÿ��Ʋ�� �����մϴ�.
	 *
	 * @param InTitle - ������ ���� ������ Ÿ��Ʋ�Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowTitle
	 */
	void SetTitle(const std::string& InTitle);


	/**
	 * ���� �������� Ÿ��Ʋ�� ����ϴ�.
	 * 
	 * @return ���� ������ Ÿ��Ʋ�� ��ȯ�մϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowTitle
	 */
	std::string GetTitle();


	/**
	 * ���� �����츦 ȭ�鿡 ǥ���մϴ�.
	 */
	void Show();


	/**
	 * ���� �����츦 ȭ�鿡�� ����ϴ�.
	 */
	void Hide();


	/**
	 * �������� ũ�� ������ ����ϴ�.
	 * �̶� ���� ���� ���� / ���� �Դϴ�.
	 *
	 * @return ���� �������� ũ�� ������ ��ȯ�մϴ�.
	 */
	float GetAspectRatio();


	/**
	 * SDL�������� �����͸� ��ȯ�մϴ�.
	 *
	 * @return SDL �������� �����͸� ��ȯ�մϴ�.
	 */
	SDL_Window* GetWindow() { return Window_; }


private:
	/**
	 * SDL ������ �������Դϴ�.
	 */
	SDL_Window* Window_ = nullptr;
};