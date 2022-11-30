#pragma once

#include <array>
#include <string>
#include <functional>

#include <Vector.hpp>
#include <Math.hpp>
#include <Color.h>

class Input;
class Renderer;


/**
 * ���� ���� ��ư�Դϴ�.
 */
class UIButton
{
public:
	/**
	 * ���� �� ��ư�� �������Դϴ�.
	 * 
	 * @param InCenter - ��ư�� �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ��ư�� ���� ũ���Դϴ�.
	 * @param InHeight - ��ư�� ���� ũ���Դϴ�.
	 * @param InText - ��ư�� ǥ�õ� �ؽ�Ʈ�Դϴ�.
	 * @param InFontKey - ��ư�� ǥ�õ� �ؽ�Ʈ�� ��Ʈ Ű ���Դϴ�.
	 * @param InEnableColor - ��ư�� Ȱ��ȭ �Ǿ��� ���� �����Դϴ�.
	 * @param InUnableColor - ��ư�� ��Ȱ��ȭ �Ǿ��� ���� �����Դϴ�.
	 * @param InClickEvent - ��ư�� Ŭ������ �� ������ �Լ��Դϴ�.
	 * @param InReduceRate - ��ư�� Ŭ������ �� �پ�� ��ư�� ũ�� �����Դϴ�.
	 */
	explicit UIButton(
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
	 * ��ư�� ���� �������Դϴ�.
	 * 
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	UIButton(UIButton&& InInstance) noexcept;


	/**
	 * ��ư�� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	UIButton(const UIButton& InInstance) noexcept;


	/**
	 * ��ư�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~UIButton() {}


	/**
	 * ��ư�� ���� �������Դϴ�.
	 * 
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	UIButton& operator=(UIButton&& InInstance) noexcept;


	/**
	 * ��ư�� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	UIButton& operator=(const UIButton& InInstance) noexcept;


	/**
	 * ��ư�� ���¸� ������Ʈ�մϴ�.
	 * 
	 * @param InInput - ��ư�� ������Ʈ�� �� ������ �Է� ó�� �ν��Ͻ��Դϴ�.
	 */
	void Update(Input& InInput);


	/**
	 * ��ư�� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param InRenderer - ��ư�� ȭ�鿡 �׸� �� ������ �������Դϴ�.
	 */
	void Render(Renderer& InRenderer);


	/**
	 * ��ư�� ��ġ�� �����մϴ�.
	 * 
	 * @param InPosition - ������ ��ư�� ��ġ�Դϴ�.
	 */
	void SetPosition(const Vec2f& InPosition);


private:
	/**
	 * ���콺 Ŀ���� ��ư ���� ���� �����Ǵ��� Ȯ���մϴ�. 
	 * 
	 * @param InInput - ���콺 Ŀ���� ��ġ�� �˱� ���� ����� �Է� ó�� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ���콺 Ŀ���� ��ư ���� ���� �����Ǹ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsDetectMouseCursor(const Input& InInput);


private:
	/**
	 * ��ư�� �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Center_;


	/**
	 * ��ư�� ���� ũ���Դϴ�.
	 */
	float Width_ = 0.0f;


	/**
	 * ��ư�� ���� ũ���Դϴ�.
	 */
	float Height_ = 0.0f;


	/**
	 * ��ư�� ǥ�õ� �ؽ�Ʈ�Դϴ�.
	 */
	std::wstring Text_;


	/**
	 * ��ư�� ǥ�õ� �ؽ�Ʈ�� ��Ʈ Ű ���Դϴ�.
	 */
	std::size_t FontKey_;

	
	/**
	 * ��ư Ȱ��ȭ �����Դϴ�.
	 */
	bool bIsEnable_ = false;


	/**
	 * ��ư�� ���ȴ��� Ȯ���մϴ�.
	 */
	bool bIsPressed_ = false;


	/**
	 * ��ư�� ����ϰ� �� �� �ֵ� ���� �����Դϴ�.
	 */
	LinearColor EnableColor_;


	/**
	 * ��ư�� ����ϰ� �� �� ���� ���� �����Դϴ�.
	 */
	LinearColor UnableColor_;


	/**
	 * ��ư�� Ŭ������ ���� �̺�Ʈ�Դϴ�.
	 */
	std::function<void()> ClickEvent_ = nullptr;


	/**
	 * ��ư�� Ŭ���Ǿ��� �� �پ��� ũ�� �����Դϴ�.
	 * �̶�, �� ���� ���� ������ 0.0 ~ 1.0 �Դϴ�.
	 */
	float ReduceRate_ = 1.0f;


	/**
	 * ��ư�� ��� �����Դϴ�.
	 */
	BoundingBox BoundingBox_;
};
