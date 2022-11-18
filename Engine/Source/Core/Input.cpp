#include "Core/Input.h"

#include "Misc/MacroUtils.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

Input::Input()
	: PrevKeyboardState_(static_cast<int32_t>(EKeyCode::CODE_NUM_SCANCODES), 0)
	, CurrKeyboardState_(static_cast<int32_t>(EKeyCode::CODE_NUM_SCANCODES), 0)
{
	GetCurrentMouseState(PrevCursorPosition_, PrevButtonState_);
	GetCurrentMouseState(CurrCursorPosition_, CurrButtonState_);
}

void Input::Tick()
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.window.event)
		{
		case SDL_WINDOWEVENT_ENTER:
			bHaveMouseFocus_ = true;
			break;

		case SDL_WINDOWEVENT_LEAVE:
			bHaveMouseFocus_ = false;
			break;

		case SDL_WINDOWEVENT_FOCUS_GAINED:
			bHaveKeyboardFocus_ = true;
			break;

		case SDL_WINDOWEVENT_FOCUS_LOST:
			bHaveKeyboardFocus_ = false;
			break;

		case SDL_WINDOWEVENT_MINIMIZED:
			bIsMinimized_ = true;
			bIsMaximized_ = false;
			break;

		case SDL_WINDOWEVENT_MAXIMIZED:
			bIsMinimized_ = false;
			bIsMaximized_ = true;
			break;

		case SDL_WINDOWEVENT_RESTORED:
			bIsMinimized_ = false;
			bIsMaximized_ = false;
			break;
		}

		HandleWindowEvent(static_cast<EWindowEvent>(Event.window.event));
	}

	const uint8_t* KeyState = SDL_GetKeyboardState(NULL);

	std::memcpy(
		reinterpret_cast<void*>(&PrevKeyboardState_[0]),
		reinterpret_cast<const void*>(&CurrKeyboardState_[0]),
		static_cast<int32_t>(EKeyCode::CODE_NUM_SCANCODES)
	);

	std::memcpy(
		reinterpret_cast<void*>(&CurrKeyboardState_[0]),
		reinterpret_cast<const void*>(&KeyState[0]),
		static_cast<int32_t>(EKeyCode::CODE_NUM_SCANCODES)
	);

	PrevCursorPosition_ = CurrCursorPosition_;
	PrevButtonState_ = CurrButtonState_;

	GetCurrentMouseState(CurrCursorPosition_, CurrButtonState_);
}

void Input::RegisterWindowEvent(const EWindowEvent& InWindowEvent, const std::function<void()>& InCallback)
{
	CHECK((WindowEvents_.find(InWindowEvent) == WindowEvents_.end()), "collision window event key");

	WindowEvents_.insert({ InWindowEvent, InCallback } );
}

void Input::UnregisterWindowEvent(const EWindowEvent& InWindowEvent)
{
	if (WindowEvents_.find(InWindowEvent) != WindowEvents_.end())
	{
		WindowEvents_.erase(InWindowEvent);
	}
}

EPressState Input::GetKeyPressState(const EKeyCode& InEKeyCode) const
{
	EPressState PressState = EPressState::NONE;

	if (IsPressKey(PrevKeyboardState_, InEKeyCode))
	{
		if (IsPressKey(CurrKeyboardState_, InEKeyCode))
		{
			PressState = EPressState::HELD;
		}
		else
		{
			PressState = EPressState::RELEASED;
		}
	}
	else
	{
		if (IsPressKey(CurrKeyboardState_, InEKeyCode))
		{
			PressState = EPressState::PRESSED;
		}
		else
		{
			PressState = EPressState::NONE;
		}
	}

	return PressState;
}

bool Input::IsPressKey(const std::vector<uint8_t>& InKeyboardState, const EKeyCode& InEKeyCode) const
{
	return InKeyboardState[static_cast<int32_t>(InEKeyCode)] == 0 ? false : true;;
}

EPressState Input::GetMousePressState(const EMouseButton& InMouseButton) const
{
	EPressState PressState = EPressState::NONE;

	if (IsPressButton(PrevButtonState_, InMouseButton))
	{
		if (IsPressButton(CurrButtonState_, InMouseButton))
		{
			PressState = EPressState::HELD;
		}
		else
		{
			PressState = EPressState::RELEASED;
		}
	}
	else
	{
		if (IsPressButton(CurrButtonState_, InMouseButton))
		{
			PressState = EPressState::PRESSED;
		}
		else
		{
			PressState = EPressState::NONE;
		}
	}

	return PressState;
}

Vec2f Input::GetPrevCursorPosition() const
{
	return Vec2f(
		static_cast<float>(PrevCursorPosition_.x),
		static_cast<float>(PrevCursorPosition_.y)
	);
}

Vec2f Input::GetCurrCursorPosition() const
{
	return Vec2f(
		static_cast<float>(CurrCursorPosition_.x),
		static_cast<float>(CurrCursorPosition_.y)
	);
}

void Input::GetCurrentMouseState(Vec2i& OutCursorPosition, uint32_t& OutButtonState)
{
	OutButtonState = SDL_GetMouseState(&OutCursorPosition.x, &OutCursorPosition.y);
}

bool Input::IsPressButton(const uint32_t& InButtonState, const EMouseButton& InMouseButton) const
{
	uint32_t Mask = 0;

	switch (InMouseButton)
	{
	case EMouseButton::LEFT:
		Mask = SDL_BUTTON_LMASK;
		break;

	case EMouseButton::RIGHT:
		Mask = SDL_BUTTON_RMASK;
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefined mouse button type");
		break;
	}

	return (InButtonState & Mask) == 0 ? false : true;
}

void Input::HandleWindowEvent(const EWindowEvent& InWindowEvent)
{
	if (WindowEvents_.find(InWindowEvent) != WindowEvents_.end())
	{
		WindowEvents_.at(InWindowEvent)();
	}
}
