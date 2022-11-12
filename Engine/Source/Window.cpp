#include "Window.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
// @third party code - END

Window::Window(const WindowConstructorParam& InParam)
	: Window(InParam.Title, InParam.PositionX, InParam.PositionY, InParam.Width, InParam.Height, InParam.Flags)
{
}

Window::Window(const std::string& InTitle, int32_t InPositionX, int32_t InPositionY, int32_t InWidth, int32_t InHeight, const EWindowFlags& InFlags)
{
	Window_ = SDL_CreateWindow(InTitle.c_str(), InPositionX, InPositionY, InWidth, InHeight, static_cast<uint32_t>(InFlags));
	CHECK((Window_ != nullptr), "failed to create window");
}

Window::~Window()
{
	if (Window_)
	{
		SDL_DestroyWindow(Window_);
		Window_ = nullptr;
	}
}

void Window::SetPosition(const int32_t& InXPosition, const int32_t& InYPosition)
{
	SDL_SetWindowPosition(Window_, InXPosition, InYPosition);
}

void Window::GetPosition(int32_t& OutXPosition, int32_t& OutYPosition)
{
	SDL_GetWindowPosition(Window_, &OutXPosition, &OutYPosition);
}

void Window::SetSize(const int32_t& InWidth, const int32_t& InHeight)
{
	SDL_SetWindowSize(Window_, InWidth, InHeight);
}

void Window::GetSize(int32_t& OutWidth, int32_t& OutHeight)
{
	SDL_GetWindowSize(Window_, &OutWidth, &OutHeight);
}

void Window::SetTitle(const std::string& InTitle)
{
	SDL_SetWindowTitle(Window_, InTitle.c_str());
}

std::string Window::GetTitle()
{
	return std::string(SDL_GetWindowTitle(Window_));
}

void Window::Show()
{
	SDL_ShowWindow(Window_);
}

void Window::Hide()
{
	SDL_HideWindow(Window_);
}

float Window::GetAspectRatio()
{
	int32_t Width, Height;
	GetSize(Width, Height);

	return static_cast<float>(Width) / static_cast<float>(Height);
}