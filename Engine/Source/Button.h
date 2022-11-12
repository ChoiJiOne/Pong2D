#pragma once

#include <array>
#include <string>
#include <functional>

#include "Vector.h"
#include "ColorUtils.h"

class Input;
class Graphics;


/**
 * 게임 내의 버튼입니다.
 */
class Button
{
public:
	/**
	 * 게임 내 버튼의 생성자입니다.
	 * 
	 * @param InCenter - 버튼의 중심 좌표입니다.
	 * @param InWidth - 버튼의 가로 크기입니다.
	 * @param InHeight - 버튼의 세로 크기입니다.
	 * @param InText - 버튼에 표시될 텍스트입니다.
	 * @param InFontKey - 버튼에 표시될 텍스트의 폰트 키 값입니다.
	 * @param InEnableColor - 버튼이 활성화 되었을 때의 색상입니다.
	 * @param InUnableColor - 버튼이 비활성화 되었을 때의 색상입니다.
	 * @param InClickEvent - 버튼을 클릭했을 때 실행할 함수입니다.
	 * @param InReduceRate - 버튼을 클릭했을 때 줄어들 버튼의 크기 비율입니다.
	 */
	explicit Button(
		const Vec2f& InCenter,
		const float& InWidth,
		const float& InHeight,
		const std::wstring& InText,
		const std::size_t& InFontKey,
		const LinearColor& InEnableColor,
		const LinearColor& InUnableColor,
		const std::function<void()>& InClickEvent,
		const float& InReduceRate
	);


	/**
	 * 버튼의 복사 생성자입니다.
	 * 
	 * @param InInstance - 복사할 객체입니다.
	 */
	Button(Button&& InInstance) noexcept;


	/**
	 * 버튼의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	Button(const Button& InInstance) noexcept;


	/**
	 * 버튼의 가상 소멸자입니다.
	 */
	virtual ~Button() {}


	/**
	 * 버튼의 대입 연산자입니다.
	 * 
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Button& operator=(Button&& InInstance) noexcept;


	/**
	 * 버튼의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Button& operator=(const Button& InInstance) noexcept;


	/**
	 * 버튼의 상태를 업데이트합니다.
	 * 
	 * @param InInput - 버튼을 업데이트할 때 참조할 입력 처리 인스턴스입니다.
	 */
	void Update(Input& InInput);


	/**
	 * 버튼을 화면에 그립니다.
	 * 
	 * @param InGraphics - 버튼을 화면에 그릴 때 참조할 그래픽스 인스턴스입니다.
	 */
	void Render(Graphics& InGraphics);


private:
	/**
	 * 마우스 커서가 버튼 영역 내에 감지되는지 확인합니다. 
	 * 
	 * @param InInput - 마우스 커서의 위치를 알기 위해 사용할 입력 처리 인스턴스입니다.
	 * 
	 * @return 마우스 커서가 버튼 영역 내에 감지되면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsDetectMouseCursor(const Input& InInput);


private:
	/**
	 * 버튼의 중심 좌표입니다.
	 */
	Vec2f Center_;


	/**
	 * 버튼의 가로 크기입니다.
	 */
	float Width_ = 0.0f;


	/**
	 * 버튼의 세로 크기입니다.
	 */
	float Height_ = 0.0f;


	/**
	 * 버튼에 표시될 텍스트입니다.
	 */
	std::wstring Text_;


	/**
	 * 버튼에 표시될 텍스트의 폰트 키 값입니다.
	 */
	std::size_t FontKey_;

	
	/**
	 * 버튼 활성화 여부입니다.
	 */
	bool bIsEnable_ = false;


	/**
	 * 버튼이 눌렸는지 확인합니다.
	 */
	bool bIsPressed_ = false;


	/**
	 * 버튼을 사용하게 될 수 있들 때의 색상입니다.
	 */
	LinearColor EnableColor_;


	/**
	 * 버튼을 사용하게 될 수 없을 때의 색상입니다.
	 */
	LinearColor UnableColor_;


	/**
	 * 버튼을 클릭했을 때의 이벤트입니다.
	 */
	std::function<void()> ClickEvent_ = nullptr;


	/**
	 * 버튼이 클릭되었을 때 줄어드는 크기 비율입니다.
	 * 이때, 이 비율 값의 범위는 0.0 ~ 1.0 입니다.
	 */
	float ReduceRate_ = 1.0f;


	/**
	 * 버튼의 직사각형 영역입니다.
	 */
	std::array<Vec2f, 4> BoundingPositions_;
};
