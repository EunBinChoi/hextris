// p.103.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.103.h"
#include <afxtempl.h> // ���ø� Ŭ���� ���Ǹ� ��� �ִ�

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

//CString Ÿ�Կ� �ش��ϴ� �ؽ��Լ��� �����Ƿ� �����Ѵ�.
template<> UINT AFXAPI HashKey(CString &str)
{
	LPCTSTR key = (LPCTSTR)str;
	return HashKey(key); //LPCTSTR Ÿ���� �ؽ� �Լ��� ��ȣ���Ѵ�.
}

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
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			_tsetlocale(LC_ALL, _T(""));

			//��(CString->UINT) ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�
			CMap<CString, CString&, UINT, UINT&>map;
			map[CString(_T("���"))] = 10;
			map[CString(_T("����"))] = 25;
			map[CString(_T("����"))] = 40;
			map[CString(_T("����"))] = 15;
			
			//Ư�� Ű���� ���� �����͸� �˻��Ѵ�
			UINT nCount;
			if(map.Lookup(CString(_T("����")), nCount))
				_tprintf(_T("���� %d���� ���ڰ� �����ֽ��ϴ�\n"),nCount);

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
