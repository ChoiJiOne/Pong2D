#pragma once

#include "Macro.h"

typedef struct _Mix_Music Mix_Music;


/**
 * ���� ���� ���� ������ �ε��ϰ� �����ϴ� Ŭ�����Դϴ�.
 * �̶�, ���� ���� ������ �ϳ��� �÷��� �� �� �ֽ��ϴ�.
 */
class Music
{
public:
	/**
	 * ���� Ŭ������ �������Դϴ�.
	 * 
	 * @param InPath - �ε��� ���� ���ҽ��� ����Դϴ�.
	 * 
	 * @throws ���� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Music(const std::string& InPath);


	/**
	 * ���� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Music();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Music);


	/**
	 * ������ �÷����մϴ�.
	 * 
	 * @param bIsLoop - �ݺ�������� Ȯ���մϴ�.
	 * 
	 * @throws ���� �÷��̿� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Play(bool bIsLoop = false);


	/**
	 * ������ �÷��� ������ Ȯ���մϴ�.
	 * 
	 * @return ������ �÷��� ���̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPlay() const;


	/**
	 * ���� �÷��̸� �ߴ��մϴ�.
	 */
	void Stop();


	/**
	 * ������ �����Ǿ����� Ȯ���մϴ�.
	 * 
	 * @return ������ �����Ǿ��ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsStop() const;


	/**
	 * �÷��� �ߴܵ� ������ �ٽ� �÷����մϴ�.
	 */
	void Resume();


private:
	/**
	 * SDL ���� ���ҽ��Դϴ�.
	 */
	Mix_Music* Music_ = nullptr;
};