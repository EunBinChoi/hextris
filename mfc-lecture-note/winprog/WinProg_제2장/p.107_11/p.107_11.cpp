// p.107_11.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.107_11.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
			_tprintf(_T("�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n"));
			nRetCode = 1;
		}
		else
		{
			
			_tsetlocale(LC_ALL, _T(""));
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			CTime startTime = CTime::GetCurrentTime();
			CTime endTime = startTime.operator+(1000);
			CTimeSpan timeSpan = endTime - startTime;
			CString str1= startTime.Format(_T("%A, %B %d, %Y"));
			str1.Format(_T("%d�� %d�� %d��, %d�� %d�� %d��"),startTime.GetYear(),startTime.GetMonth(),startTime.GetDay(),startTime.GetHour(), startTime.GetMinute(),startTime.GetSecond() );
			CString str2= endTime.Format(_T("%A, %B %d, %Y"));
			str2.Format(_T("%d�� %d�� %d��, %d�� %d�� %d��"),endTime.GetYear(),endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(), endTime.GetMinute(),endTime.GetSecond() );
			_tprintf(_T("%s�� "),str1);
			_tprintf(_T("%d�� �Ĵ� "), timeSpan);
			_tprintf(_T("%s�Դϴ�\n"),str2);
		}
	}
	else
	{
		// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
		_tprintf(_T("�ɰ��� ����: GetModuleHandle ����\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
