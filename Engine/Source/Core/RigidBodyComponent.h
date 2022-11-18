#pragma once

#include "Component.h"

#include "Misc/MathUtils.h"
#include "Misc/Vector.h"


/**
 * ������Ʈ�� �ٵ��Դϴ�.
 * �̶�, ������Ʈ �ٵ�� AABB ������� ȸ������ �ʽ��ϴ�.
 */
class RigidBodyComponent : public Component
{
public:
	/**
	 * ������Ʈ �ٵ��� �⺻ �������Դϴ�.
	 * �̶�, ����Ʈ �����ڿ��� �ʱ�ȭ�� �������� �����Ƿ�, ����ϱ� ���� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	RigidBodyComponent() = default;

	
	/**
	 * ������Ʈ �ٵ��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~RigidBodyComponent();
};