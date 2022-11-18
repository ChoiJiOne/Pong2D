#pragma once

#include "Component.h"

#include "Misc/MathUtils.h"
#include "Misc/Vector.h"


/**
 * 오브젝트의 바디입니다.
 * 이때, 오브젝트 바디는 AABB 기반으로 회전하지 않습니다.
 */
class RigidBodyComponent : public Component
{
public:
	/**
	 * 오브젝트 바디의 기본 생성자입니다.
	 * 이때, 디폴트 생성자에서 초기화를 수행하지 않으므로, 사용하기 전에 적절한 초기화를 수행해야 합니다.
	 */
	RigidBodyComponent() = default;

	
	/**
	 * 오브젝트 바디의 가상 소멸자입니다.
	 */
	virtual ~RigidBodyComponent();
};