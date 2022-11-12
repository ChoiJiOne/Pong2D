#pragma once

#include "Macro.h"

typedef struct _Mix_Music Mix_Music;


/**
 * 게임 내의 뮤직 파일을 로딩하고 관리하는 클래스입니다.
 * 이때, 게임 내에 뮤직은 하나만 플레이 될 수 있습니다.
 */
class Music
{
public:
	/**
	 * 뮤직 클래스의 생성자입니다.
	 * 
	 * @param InPath - 로딩할 사운드 리소스의 경로입니다.
	 * 
	 * @throws 뮤직 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	explicit Music(const std::string& InPath);


	/**
	 * 뮤직 클래스의 가상 소멸자입니다.
	 */
	virtual ~Music();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Music);


	/**
	 * 뮤직을 플레이합니다.
	 * 
	 * @param bIsLoop - 반복재생할지 확인합니다.
	 * 
	 * @throws 뮤직 플레이에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void Play(bool bIsLoop = false);


	/**
	 * 뮤직이 플레이 중인지 확인합니다.
	 * 
	 * @return 뮤직이 플레이 중이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsPlay() const;


	/**
	 * 음악 플레이를 중단합니다.
	 */
	void Stop();


	/**
	 * 뮤직이 중지되었는지 확인합니다.
	 * 
	 * @return 뮤직이 중지되었다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsStop() const;


	/**
	 * 플레이 중단된 뮤직을 다시 플레이합니다.
	 */
	void Resume();


private:
	/**
	 * SDL 뮤직 리소스입니다.
	 */
	Mix_Music* Music_ = nullptr;
};