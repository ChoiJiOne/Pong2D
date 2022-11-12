#pragma once

#include "Macro.h"

struct Mix_Chunk;


/**
 * ���� ���� ���� ������ �ε��ϰ� �����ϴ� Ŭ�����Դϴ�.
 * �̶�, ���� ���� ����� ���� ���� �÷��� �� �� �ֽ��ϴ�.
 * ��, ǰ���� Music ���� ������ �� �ֽ��ϴ�.
 */
class Sound
{
public:
	/**
	 * ���� Ŭ������ �������Դϴ�.
	 * 
	 * @param InPath - �ε��� ���� ���ҽ��� ����Դϴ�.
	 * 
	 * @throws ���� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	Sound(const std::string& InPath);


	/**
	 * ���� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Sound();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Sound);


	/**
	 * ������ �÷����մϴ�.
	 */
	void Play();


private:
	/**
	 * SDL ���� ���ҽ��Դϴ�.
	 */
	Mix_Chunk* Sound_ = nullptr;
};