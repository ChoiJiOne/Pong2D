#include "Input.h"
#include "Macro.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

Input::Input()
	: PrevKeyboardState_(static_cast<int32_t>(EScanCode::CODE_NUM_SCANCODES), 0)
	, CurrKeyboardState_(static_cast<int32_t>(EScanCode::CODE_NUM_SCANCODES), 0)
{
	GetCurrentMouseState(PrevCursorPosition_, PrevButtonState_);
	GetCurrentMouseState(CurrCursorPosition_, CurrButtonState_);
}

Input::Input(Input&& InInstance) noexcept
	: PrevKeyboardState_(InInstance.PrevKeyboardState_)
	, CurrKeyboardState_(InInstance.CurrKeyboardState_)
	, PrevCursorPosition_(InInstance.PrevCursorPosition_)
	, PrevButtonState_(InInstance.PrevButtonState_)
	, CurrCursorPosition_(InInstance.CurrCursorPosition_)
	, CurrButtonState_(InInstance.CurrButtonState_)
{
}

Input::Input(const Input& InInstance) noexcept
	: PrevKeyboardState_(InInstance.PrevKeyboardState_)
	, CurrKeyboardState_(InInstance.CurrKeyboardState_)
	, PrevCursorPosition_(InInstance.PrevCursorPosition_)
	, PrevButtonState_(InInstance.PrevButtonState_)
	, CurrCursorPosition_(InInstance.CurrCursorPosition_)
	, CurrButtonState_(InInstance.CurrButtonState_)
{
}

Input& Input::operator=(Input&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	PrevKeyboardState_ = InInstance.PrevKeyboardState_;
	CurrKeyboardState_ = InInstance.CurrKeyboardState_;
	PrevCursorPosition_ = InInstance.PrevCursorPosition_;
	PrevButtonState_ = InInstance.PrevButtonState_;
	CurrCursorPosition_ = InInstance.CurrCursorPosition_;
	CurrButtonState_ = InInstance.CurrButtonState_;

	return *this;
}

Input& Input::operator=(const Input& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	PrevKeyboardState_ = InInstance.PrevKeyboardState_;
	CurrKeyboardState_ = InInstance.CurrKeyboardState_;
	PrevCursorPosition_ = InInstance.PrevCursorPosition_;
	PrevButtonState_ = InInstance.PrevButtonState_;
	CurrCursorPosition_ = InInstance.CurrCursorPosition_;
	CurrButtonState_ = InInstance.CurrButtonState_;

	return *this;
}

bool Input::Tick()
{
	bool bIsDetectQuitMessage = false;

	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		if (Event.type == SDL_QUIT)
		{
			bIsDetectQuitMessage = true;
		}
	}

	const uint8_t* KeyState = SDL_GetKeyboardState(NULL);

	std::memcpy(
		reinterpret_cast<void*>(&PrevKeyboardState_[0]),
		reinterpret_cast<const void*>(&CurrKeyboardState_[0]),
		static_cast<int32_t>(EScanCode::CODE_NUM_SCANCODES)
	);

	std::memcpy(
		reinterpret_cast<void*>(&CurrKeyboardState_[0]),
		reinterpret_cast<const void*>(&KeyState[0]),
		static_cast<int32_t>(EScanCode::CODE_NUM_SCANCODES)
	);

	PrevCursorPosition_ = CurrCursorPosition_;
	PrevButtonState_ = CurrButtonState_;

	GetCurrentMouseState(CurrCursorPosition_, CurrButtonState_);

	return bIsDetectQuitMessage;
}

EPressState Input::GetKeyPressState(const EScanCode& InScanCode) const
{
	EPressState PressState = EPressState::NONE;

	if (IsPressKey(PrevKeyboardState_, InScanCode))
	{
		if (IsPressKey(CurrKeyboardState_, InScanCode))
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
		if (IsPressKey(CurrKeyboardState_, InScanCode))
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

bool Input::IsPressKey(const std::vector<uint8_t>& InKeyboardState, const EScanCode& InScanCode) const
{
	return InKeyboardState[static_cast<int32_t>(InScanCode)] == 0 ? false : true;;
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
