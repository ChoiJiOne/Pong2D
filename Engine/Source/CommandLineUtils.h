#pragma once

#include <unordered_map>

#include "Text.h"


/**
 * Ŀ�ǵ� ������ �Ľ��ϰ�, Ŀ�ǵ� ���� ���ڸ� �����ϴ� Ŭ�����Դϴ�.
 */
class CommandLineUtils
{
public:
	/**
	 * �Է¹��� Ŀ�ǵ� ������ �Ľ��ϰ�, �ʱ�ȭ�մϴ�.
	 */
	static void Init();


	/**
	 * ��ü Ŀ�ǵ� ������ ����ϴ�.
	 * 
	 * @return ��ü Ŀ�ǵ� ���� ���ڿ��� ��ȯ�մϴ�.
	 */
	static std::string GetCommanLine() { return CommandLine_; }


	/**
	 * �ɼ��� �����ϴ��� Ȯ���մϴ�.
	 * 
	 * @param InOption - �����ϴ��� Ȯ���� �ɼ��Դϴ�.
	 * 
	 * @return �ɼ��� �����ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveOption(const std::string& InOption);


	/**
	 * �ɼǿ� �ش��ϴ� ���� ����ϴ�.
	 * �̶�, �ɼǿ� �����ϴ� ���� �������� �ʴ´ٸ�, �� ���ڿ��� ��ȯ�մϴ�.
	 * 
	 * @param InOption - �ɼ��Դϴ�.
	 * 
	 * @return �ɼǿ� �����ϴ� ���� ��ȯ�մϴ�.
	 */
	static std::string GetValue(const std::string& InOption);


private:
	/**
	 * ���� ���� �� ���� ���� ��ü Ŀ�ǵ� �����Դϴ�.
	 */
	static std::string CommandLine_;
	

	/**
	 * ���� ���� �ÿ� ���� ���� Ŀ�ǵ� ������ �����Դϴ�.
	 */
	static std::vector<std::string> Arguments_;


	/**
	 * Ŀ�ǵ� ���� �Է����� ���� �ɼ��Դϴ�.
	 */
	static std::unordered_map<std::string, std::string> Options_;
};