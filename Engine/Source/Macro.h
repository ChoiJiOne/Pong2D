#pragma once

#include "Text.h"


/**
 * �򰡽��� �˻��մϴ�.
 * �̶�, �򰡽��� �������� �򰡵Ǹ� C++ ǥ�� ���ܸ� �����ϴ�.
 *
 * @param EXPRESSION - �˻��� �򰡽��Դϴ�.
 * @param MESSAGE - �򰡽��� �������� �򰡵� ����� �޽����Դϴ�.
 *
 * @throws �򰡽��� �������� �򰡵� ���, C++ ǥ�� ���ܸ� �����ϴ�.
 */
#ifndef CHECK
#define CHECK(EXPRESSION, MESSAGE)\
{\
	if(!EXPRESSION)\
	{\
		throw std::exception(\
			Text::Format(\
			"file : %s, line : %d, function : %s, message : %s",\
				__FILE__, __LINE__, __FUNCTION__, MESSAGE).c_str()\
		);\
	}\
}
#endif


/**
 * ������ C++ ǥ�� ���ܸ� �����ϴ�.
 *
 * @param MESSAGE - ���ܰ� �߻����� ���� �޽����Դϴ�.
 *
 * @throws C++ ǥ�� ���ܸ� �����ϴ�.
 */
#ifndef ENFORCE_THROW_EXCEPTION
#define ENFORCE_THROW_EXCEPTION(MESSAGE)\
{\
	throw std::exception(\
		Text::Format(\
		"file : %s, line : %d, function : %s, message : %s",\
			__FILE__, __LINE__, __FUNCTION__, MESSAGE).c_str()\
	);\
}
#endif


/**
 * Ŭ������ ���� ������ �� ���� �����ڸ� ������� ���ϵ��� �����մϴ�.
 * �� ��ũ�θ� ������� �ʴ� Ŭ������ �ݵ�� ��������� ���� �����ڿ� ���� �����ڸ� �����ؾ� �մϴ�.
 *
 * @param CLASS - ���� ������ �� ���� �����ڸ� ������ Ŭ�����Դϴ�.
 */
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(CLASS)\
CLASS(CLASS&&) = delete;\
CLASS(const CLASS&) = delete;\
CLASS& operator=(CLASS&&) = delete;\
CLASS& operator=(const CLASS&) = delete;
#endif