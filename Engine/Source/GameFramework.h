#pragma once

#include "Macro.h"

class World;
class Window;
class Input;
class Graphics;


/**
 * ���� �����ӿ�ũ Ŭ�����Դϴ�.
 * �� ������ �̿��ؼ� ������ �����ϱ� ���ؼ��� �ݵ�� �� Ŭ������ ��ӹ޾ƾ� �մϴ�.
 */
class GameFramework
{
public:
	/**
	 * ���� �����ӿ�ũ�� �������Դϴ�.
	 * �̶�, �����ڴ� �ƹ��� ������ ���� �����Ƿ� �ݵ�� Init �޼��带 ȣ���ؾ� �մϴ�.
	 */
	GameFramework() = default;


	/**
	 * ���� �����ӿ�ũ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GameFramework();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� ����
	 */
	DISALLOW_COPY_AND_ASSIGN(GameFramework);


	/**
	 * ToyEngine2D �� ���� �����ӿ�ũ�� �ʱ�ȭ�մϴ�.
	 *
	 * @throws
	 * - ���� ���� �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * - ���� �����ӿ�ũ �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Init();


	/**
	 * ������ �����մϴ�.
	 *
	 * @throws ���� ���࿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Run() = 0;


	/**
	 * ������ ������Ʈ�մϴ�.
	 *
	 * @throws ���� ������Ʈ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Update() = 0;


	/**
	 * ������ ȭ�鿡 �������մϴ�.
	 *
	 * @throws ���� �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Render() = 0;


protected:
	/**
	 * ������ ���� �����Դϴ�.
	 */
	bool bIsDone_ = false;


	/**
	 * 2D ���� �����Դϴ�.
	 */
	std::unique_ptr<World> World_ = nullptr;


	/**
	 * ���� ������ â�Դϴ�.
	 */
	std::unique_ptr<Window> Window_ = nullptr;


	/**
	 * ���� ���� �Է� ó���� �����մϴ�.
	 */
	std::unique_ptr<Input> Input_ = nullptr;


	/**
	 * ���� ���� �׷��� ó���� �����մϴ�.
	 */
	std::unique_ptr<Graphics> Graphics_ = nullptr;
};