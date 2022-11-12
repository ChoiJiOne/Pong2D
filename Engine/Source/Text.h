#pragma once

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>


/**
 * ���ڿ� ���� ����� �����ϴ� Ŭ�����Դϴ�.
 * �̶� �� Ŭ������ ���� Ŭ������ ��� ���� �ϸ�
 * �ν��Ͻ� ���� ���� �ٷ� ����� �� �ֽ��ϴ�.
 */
class Text
{
public:
	/**
	 * ����ȭ�� ���ڿ��� ��ȯ�մϴ�.
	 * �� �޼���� snprintf�� ��ü�ϱ� ���� �޼����Դϴ�.
	 *
	 * @param InFormat - ���� ���ڿ��Դϴ�.
	 * @param ... InArgs - �������� ������ �����͸� �����ϴ� �μ��Դϴ�.
	 *
	 * @return �������� �Ϸ�� ���ڿ��� ��ȯ�մϴ�.
	 *
	 * @see https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
	 */
	template<typename ... Args>
	static inline std::string Format(const std::string& InFormat, Args ... InArgs_)
	{
		size_t Size = static_cast<size_t>(std::snprintf(nullptr, 0, InFormat.c_str(), InArgs_ ...)) + 1;

		auto Buffer = std::make_unique<char[]>(Size);
		std::snprintf(Buffer.get(), Size, InFormat.c_str(), InArgs_ ...);

		return std::string(Buffer.get(), Buffer.get() + Size - 1);
	}


	/**
	 * ����ȭ�� ���ڿ��� ��ȯ�մϴ�.
	 * �� �޼���� swprintf�� ��ü�ϱ� ���� �޼����Դϴ�.
	 *
	 * @param InFormat - ���� ���ڿ��Դϴ�.
	 * @param ... InArgs - �������� ������ �����͸� �����ϴ� �μ��Դϴ�.
	 *
	 * @return �������� �Ϸ�� ���ڿ��� ��ȯ�մϴ�.
	 *
	 * @see https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
	 */
	template<typename ... Args>
	static inline std::wstring Format(const std::wstring& InFormat, Args ... InArgs_)
	{
		size_t Size = static_cast<size_t>(std::swprintf(nullptr, 0, InFormat.c_str(), InArgs_ ...)) + 1;

		auto Buffer = std::make_unique<wchar_t[]>(Size);
		std::swprintf(Buffer.get(), Size, InFormat.c_str(), InArgs_ ...);

		return std::wstring(Buffer.get(), Buffer.get() + Size - 1);
	}


	/**
	 * ���ڿ��� Hash ���� ��ȯ�մϴ�.
	 *
	 * @param InText - Hash ������ ��ȯ�� ���ڿ��Դϴ�.
	 *
	 * @return �Է� ���� ���ڿ��� Hash ���Դϴ�.
	 */
	static inline std::size_t GetHash(const std::string& InText)
	{
		return std::hash<std::string>{}(InText);
	}


	/**
	 * ���ڿ��� Hash ���� ����ϴ�.
	 *
	 * @param InText - Hash ������ ��ȯ�� ���ڿ��Դϴ�.
	 *
	 * @return �Է� ���� ���ڿ��� Hash ���Դϴ�.
	 */
	static inline std::size_t GetHash(const std::wstring& InText)
	{
		return std::hash<std::wstring>{}(InText);
	}


	/**
	 * ���ڿ��� Ư�� �������� ����� ���ͷ� ����ϴ�.
	 *
	 * @param InText - Ư�� �������� ����� ���ͷ� ���� ���ڿ��Դϴ�.
	 * @param InDelimiter - ���ڿ��� ���� �����Դϴ�.
	 *
	 * @return �������� ���ڿ��� ���͸� ��ȯ�մϴ�.
	 */
	static inline std::vector<std::string> Split(std::string InText, const std::string& InDelimiter)
	{
		std::vector<std::string> Tokens;
		std::size_t Position = 0;

		while ((Position = InText.find(InDelimiter)) != std::string::npos)
		{
			Tokens.push_back(InText.substr(0, Position));
			InText.erase(0, Position + InDelimiter.length());
		}

		Tokens.push_back(InText);
		return Tokens;
	}


	/**
	 * ���ڿ��� Ư�� �������� ����� ���ͷ� ����ϴ�.
	 *
	 * @param InText - Ư�� �������� ����� ���ͷ� ���� ���ڿ��Դϴ�.
	 * @param InDelimiter - ���ڿ��� ���� �����Դϴ�.
	 *
	 * @return �������� ���ڿ��� ���͸� ��ȯ�մϴ�.
	 */
	static inline std::vector<std::wstring> Split(std::wstring InText, const std::wstring& InDelimiter)
	{
		std::vector<std::wstring> Tokens;
		std::size_t Position = 0;

		while ((Position = InText.find(InDelimiter)) != std::wstring::npos)
		{
			Tokens.push_back(InText.substr(0, Position));
			InText.erase(0, Position + InDelimiter.length());
		}

		Tokens.push_back(InText);
		return Tokens;
	}
};