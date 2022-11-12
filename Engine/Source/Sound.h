#pragma once

#include "Macro.h"

struct Mix_Chunk;


/**
 * 게임 내의 사운드 파일을 로딩하고 관리하는 클래스입니다.
 * 이때, 게임 내의 사운드는 여러 개가 플레이 될 수 있습니다.
 * 단, 품질은 Music 보다 떨어질 수 있습니다.
 */
class Sound
{
public:
	/**
	 * 사운드 클래스의 생성자입니다.
	 * 
	 * @param InPath - 로딩할 사운드 리소스의 경로입니다.
	 * 
	 * @throws 사운드 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	Sound(const std::string& InPath);


	/**
	 * 사운드 클래스의 가상 소멸자입니다.
	 */
	virtual ~Sound();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Sound);


	/**
	 * 사운드을 플레이합니다.
	 */
	void Play();


private:
	/**
	 * SDL 사운드 리소스입니다.
	 */
	Mix_Chunk* Sound_ = nullptr;
};