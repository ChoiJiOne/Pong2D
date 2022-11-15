#pragma once

#include "GameObject.h"


/**
 * Pong2D ���� �÷��̾� Ŭ�����Դϴ�.
 */
class Player : public GameObject
{
public:
	/**
	 * Pong2D ���� �÷��̾��� �������Դϴ�.
	 * 
	 * @param InWorld - ���� �÷��̾ ��ġ�� �����Դϴ�.
	 */
	explicit Player(World* InWorld);


	/**
	 * Pong2D ���� �÷��̾��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Player();


	/**
	 * ���� �÷��̾��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Player);


	/**
	 * ���� �÷��̾ ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó�� �ν��Ͻ��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * ���� �÷��̾ ȭ�鿡 �׸��ϴ�.
	 *
	 * @param InGraphics - ������ ������ ó�� �ν��Ͻ��Դϴ�.
	 */
	virtual void Render(Graphics& InGraphics) override;
};