// p.81.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.81.h"

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
			
			_tsetlocale(LC_ALL,_T(""));
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			CString str1;
			str1 = _T("�ȳ��ϼ���."); // ���ڿ��� ���� �����Ѵ�
			CString str2(_T("������")); // ���ڿ��� ������ ���ڷ� �����Ѵ�
			CString str3(str2); // CString ��ü�� ������ ���ڷ� �����Ѵ�
			//CString ��ü�� ���ڿ��� ���δ�
			CString str4 = str1 + _T(" ") + str2 + _T(" ��ſ� ���Դϴ�");
			_tprintf(_T("%s\n"),str1);
			_tprintf(_T("%s\n"),str2);
			_tprintf(_T("%s\n"),str3);
			_tprintf(_T("%s\n"),str4);
			str4+= _T(" ������");
			_tprintf(_T("%s\n"),str4);
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
