#pragma once

#include <string>
#include <vector>
#include <unordered_map>


/**
 * Ŀ�ǵ� ������ �Ľ��ϰ�, ���ڸ� �����ϴ� Ŭ�����Դϴ�.
 */
class CommandLineManager
{
public:
	/**
	 * CommandLineManager �ν��Ͻ��� ����ϴ�.
	 * 
	 * @return CommandLineManager �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	static CommandLineManager& Get() { return CommandLineManager_; }


	/**
	 * ��ü Ŀ�ǵ� ������ ����ϴ�.
	 * 
	 * @return ��ü Ŀ�ǵ� ���� ���ڿ��� ��ȯ�մϴ�.
	 */
	const std::string& GetCommanLine() { return CommandLine_; }


	/**
	 * �ɼ��� �����ϴ��� Ȯ���մϴ�.
	 * 
	 * @param InOption - �����ϴ��� Ȯ���� �ɼ��Դϴ�.
	 * 
	 * @return �ɼ��� �����ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveOption(const std::string& InOption);


	/**
	 * �ɼǿ� �ش��ϴ� ���� ����ϴ�.
	 * �̶�, �ɼǿ� �����ϴ� ���� �������� �ʴ´ٸ�, �� ���ڿ��� ��ȯ�մϴ�.
	 * 
	 * @param InOption - �ɼ��Դϴ�.
	 * 
	 * @return �ɼǿ� �����ϴ� ���� ��ȯ�մϴ�.
	 */
	std::string GetValue(const std::string& InOption);


private:
	/**
	 * ToyEngine Ŭ������ CommandLine�� private �ʵ忡 ������ �� �ֵ��� �մϴ�.
	 */
	friend class ToyEngine;


	/**
	 * CommandLineManager�� �������Դϴ�.
	 * �̶�, CommanLineManager�� �����ڴ� �ƹ��� ���۵� �������� �ʽ��ϴ�.
	 */
	CommandLineManager() {}


	/**
	 * CommandLineManager�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~CommandLineManager() {}


	/**
	 * �Է¹��� Ŀ�ǵ� ������ �Ľ��ϰ�, �ʱ�ȭ�մϴ�.
	 * �̶�, ToyEngine ���ο��� �ݵ�� ȣ���ؾ� �մϴ�.
	 */
	void Init();


private:
	/**
	 * CommandLineManager �� �ν��Ͻ��Դϴ�.
	 * �� �ν��Ͻ��� �� �ϳ��� �����մϴ�.
	 */
	static CommandLineManager CommandLineManager_;


	/**
	 * ���� ���� �� ���� ���� ��ü Ŀ�ǵ� �����Դϴ�.
	 */
	std::string CommandLine_;
	

	/**
	 * ���� ���� �ÿ� ���� ���� Ŀ�ǵ� ������ �����Դϴ�.
	 */
	std::vector<std::string> Arguments_;


	/**
	 * Ŀ�ǵ� ���� �Է����� ���� �ɼ��Դϴ�.
	 */
	std::unordered_map<std::string, std::string> Options_;
};