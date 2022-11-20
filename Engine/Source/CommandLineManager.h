#pragma once

#include <string>
#include <vector>
#include <unordered_map>


/**
 * 커맨드 라인을 파싱하고, 인자를 관리하는 클래스입니다.
 */
class CommandLineManager
{
public:
	/**
	 * CommandLineManager 인스턴스를 얻습니다.
	 * 
	 * @return CommandLineManager 인스턴스의 참조자를 반환합니다.
	 */
	static CommandLineManager& Get() { return CommandLineManager_; }


	/**
	 * 전체 커맨드 라인을 얻습니다.
	 * 
	 * @return 전체 커맨드 라인 문자열을 반환합니다.
	 */
	const std::string& GetCommanLine() { return CommandLine_; }


	/**
	 * 옵션이 존재하는지 확인합니다.
	 * 
	 * @param InOption - 존재하는지 확인할 옵션입니다.
	 * 
	 * @return 옵션이 존재하면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool HaveOption(const std::string& InOption);


	/**
	 * 옵션에 해당하는 값을 얻습니다.
	 * 이때, 옵션에 대응하는 값이 존재하지 않는다면, 빈 문자열을 반환합니다.
	 * 
	 * @param InOption - 옵션입니다.
	 * 
	 * @return 옵션에 대응하는 값을 반환합니다.
	 */
	std::string GetValue(const std::string& InOption);


private:
	/**
	 * ToyEngine 클래스는 CommandLine의 private 필드에 접근할 수 있도록 합니다.
	 */
	friend class ToyEngine;


	/**
	 * CommandLineManager의 생성자입니다.
	 * 이때, CommanLineManager의 생성자는 아무런 동작도 수행하지 않습니다.
	 */
	CommandLineManager() {}


	/**
	 * CommandLineManager의 가상 소멸자입니다.
	 */
	virtual ~CommandLineManager() {}


	/**
	 * 입력받은 커맨드 라인을 파싱하고, 초기화합니다.
	 * 이때, ToyEngine 내부에서 반드시 호출해야 합니다.
	 */
	void Init();


private:
	/**
	 * CommandLineManager 의 인스턴스입니다.
	 * 이 인스턴스는 단 하나만 존재합니다.
	 */
	static CommandLineManager CommandLineManager_;


	/**
	 * 게임 실행 시 전달 받은 전체 커맨드 라인입니다.
	 */
	std::string CommandLine_;
	

	/**
	 * 게임 실행 시에 전달 받은 커맨드 라인의 인자입니다.
	 */
	std::vector<std::string> Arguments_;


	/**
	 * 커맨드 라인 입력으로 받은 옵션입니다.
	 */
	std::unordered_map<std::string, std::string> Options_;
};