#pragma once

#include "Vector.h"
#include "Macro.h"

#include <memory>

class World;
class Body;
class Input;
class Graphics;
class InputComponent;
class BodyComponent;
class PhysicComponent;
class GraphicsComponent;
class SoundComponent;


/**
 * ���� ������Ʈ Ŭ�����Դϴ�.
 * ���� ���� ������Ʈ�� �� Ŭ������ ��ӹ޾ƾ� �մϴ�.
 */
class GameObject
{
public:
	/**
	 * ���� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InWorld - ���� ������Ʈ�� ��ġ�� �����Դϴ�.
	 */
	explicit GameObject(World* InWorld);


	/**
	 * ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GameObject();

	
	/**
	 * ���� ������Ʈ�� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GameObject);


	/**
	 * ���� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó�� �ν��Ͻ��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) = 0;


	/**
	 * ���� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param InGraphics - ������ ������ ó�� �ν��Ͻ��Դϴ�.
	 */
	virtual void Render(Graphics& InGraphics) = 0;


	/**
	 * ���� ������Ʈ�� �ٵ� ����ϴ�.
	 * 
	 * @return ���� ������Ʈ �ٵ��� ���� �Ұ����� �����ڸ� ��ȯ�մϴ�.
	 */
	const Body& GetBody() const { return *Body_.get(); }


	/**
	 * ���� ������Ʈ�� �ٵ� ����ϴ�.
	 * 
	 * @return ���� ������Ʈ �ٵ��� ���� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Body& GetBody() { return *Body_.get(); }


protected:
	/**
	 * ���� ������Ʈ�� ��ġ�� �����Դϴ�.
	 */
	World* World_ = nullptr;


	/**
	 * ���� ������Ʈ�� �ٵ��Դϴ�.
	 */
	std::unique_ptr<Body> Body_ = nullptr;


	/**
	 * ���� ������Ʈ�� �Է� ó�� ������Ʈ�Դϴ�.
	 */
	std::unique_ptr<InputComponent> Input_ = nullptr;


	/**
	 * ���� ������Ʈ�� ���� ó�� ������Ʈ�Դϴ�.
	 */
	std::unique_ptr<PhysicComponent> Physic_ = nullptr;


	/**
	 * ���� ������Ʈ�� ������ ó�� ������Ʈ�Դϴ�.
	 */
	std::unique_ptr<GraphicsComponent> Graphics_ = nullptr;


	/**
	 * ���� ������Ʈ�� ���� ó�� ������Ʈ�Դϴ�.
	 */
	std::unique_ptr<SoundComponent> Sound_ = nullptr;
};