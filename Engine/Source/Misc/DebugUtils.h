#pragma once

#include <Windows.h>
#include <Dbghelp.h>
#include <minidumpapiset.h>

#include <string>
#include <queue>


/**
 * ���� ���� ���׸� Ž���ϰ� �����ϴ� Ŭ�����Դϴ�.
 */
class DebugUtils
{
public:
	/**
	 * �ʱ�ȭ�մϴ�.
	 */
	static void Init();


	/**
	 * ����ȭ ���� ���� ���ܸ� ó���մϴ�.
	 * 
	 * @param InExceptionInfo - ���ܰ� �߻��� ������ ���õ� �����Դϴ�.
	 * 
	 * @return EXCEPTION_CONTINUE_SEARCH �⺻ ���� ��ȯ�մϴ�.
	 */
	static LONG WINAPI UnhandledExceptionHandler(struct _EXCEPTION_POINTERS* InExceptionInfo);


	/**
	 * ũ���� ���� ������ �����մϴ�.
	 * �̶�, ���� ���� �̸��� YYYY-MM-DD-HH-MM-SS.dmp ���� �Դϴ�.
	 * 
	 * @param InExceptionInfo - ���ܰ� �߻��� ������ ���õ� �����Դϴ�.
	 */
	static void CreateDumpFile(struct _EXCEPTION_POINTERS* InExceptionInfo);
};