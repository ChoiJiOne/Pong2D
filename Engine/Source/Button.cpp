#include <Button.h>
#include <ContentManager.h>
#include <Renderer.h>
#include <Input.h>

Button::Button(
	const Vec2f& InCenter, 
	const float& InWidth, 
	const float& InHeight, 
	const std::wstring& InText, 
	const std::size_t& InFontKey, 
	const LinearColor& InEnableColor, 
	const LinearColor& InUnableColor, 
	const std::function<void()>& InClickEvent,
	const float& InReduceRate
)
{
	Center_ = InCenter;
	Width_ = InWidth;
	Height_ = InHeight;
	Text_ = InText;
	FontKey_ = InFontKey;
	EnableColor_ = InEnableColor;
	UnableColor_ = InUnableColor;
	ClickEvent_ = InClickEvent;
	ReduceRate_ = InReduceRate;
	BoundingBox_ = Math::CalculateBoundingBox(Center_, Width_, Height_);
}

Button::Button(Button&& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Text_ = InInstance.Text_;
	FontKey_ = InInstance.FontKey_;
	bIsEnable_ = InInstance.bIsEnable_;
	bIsPressed_ = InInstance.bIsPressed_;
	EnableColor_ = InInstance.EnableColor_;
	UnableColor_ = InInstance.UnableColor_;
	ClickEvent_ = InInstance.ClickEvent_;
	ReduceRate_ = InInstance.ReduceRate_;
	BoundingBox_ = InInstance.BoundingBox_;
}

Button::Button(const Button& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Text_ = InInstance.Text_;
	FontKey_ = InInstance.FontKey_;
	bIsEnable_ = InInstance.bIsEnable_;
	bIsPressed_ = InInstance.bIsPressed_;
	EnableColor_ = InInstance.EnableColor_;
	UnableColor_ = InInstance.UnableColor_;
	ClickEvent_ = InInstance.ClickEvent_;
	ReduceRate_ = InInstance.ReduceRate_;
	BoundingBox_ = InInstance.BoundingBox_;
}

Button& Button::operator=(Button&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Text_ = InInstance.Text_;
	FontKey_ = InInstance.FontKey_;
	bIsEnable_ = InInstance.bIsEnable_;
	bIsPressed_ = InInstance.bIsPressed_;
	EnableColor_ = InInstance.EnableColor_;
	UnableColor_ = InInstance.UnableColor_;
	ClickEvent_ = InInstance.ClickEvent_;
	ReduceRate_ = InInstance.ReduceRate_;
	BoundingBox_ = InInstance.BoundingBox_;

	return *this;
}

Button& Button::operator=(const Button& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Text_ = InInstance.Text_;
	FontKey_ = InInstance.FontKey_;
	bIsEnable_ = InInstance.bIsEnable_;
	bIsPressed_ = InInstance.bIsPressed_;
	EnableColor_ = InInstance.EnableColor_;
	UnableColor_ = InInstance.UnableColor_;
	ClickEvent_ = InInstance.ClickEvent_;
	ReduceRate_ = InInstance.ReduceRate_;
	BoundingBox_ = InInstance.BoundingBox_;

	return *this;
}

void Button::Update(Input& InInput)
{
	bIsEnable_ = IsDetectMouseCursor(InInput);

	if (!bIsEnable_) return;

	EPressState CurrentPressState = InInput.GetMousePressState(EMouseButton::LEFT);
	if (CurrentPressState == EPressState::PRESSED || CurrentPressState == EPressState::HELD)
	{
		bIsPressed_ = true;
	}
	else
	{
		if (CurrentPressState == EPressState::RELEASED)
		{
			ClickEvent_();
		}

		bIsPressed_ = false;
	}
}

void Button::Render(Renderer& InRenderer)
{
	LinearColor CurrentColor = bIsEnable_ ? EnableColor_ : UnableColor_;

	int32_t Width = 0, Height = 0;
	Vec2i Position(static_cast<int32_t>(Center_.x), static_cast<int32_t>(Center_.y));

	if (bIsPressed_)
	{
		Width = static_cast<int32_t>(Width_ * ReduceRate_);
		Height = static_cast<int32_t>(Height_ * ReduceRate_);
	}
	else
	{
		Width = static_cast<int32_t>(Width_);
		Height = static_cast<int32_t>(Height_);
	}

	InRenderer.DrawRect2D(Position, Width, Height, CurrentColor);
	InRenderer.DrawText2D(ContentManager::Get().GetFont(FontKey_), Text_, Position, CurrentColor);
}

bool Button::IsDetectMouseCursor(const Input& InInput)
{
	Vec2f CurrentMousePosition = InInput.GetCurrCursorPosition();

	return Math::IsPositionInsideBoundingBox(CurrentMousePosition, BoundingBox_);
}