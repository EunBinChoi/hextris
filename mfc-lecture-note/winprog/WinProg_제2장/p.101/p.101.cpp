// p.101.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.101.h"

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
			CMapStringToString map;
			map[_T("���")] = _T("Apple");
			map[_T("����")] = _T("Strawberry");
			map[_T("����")] = _T("Grape");
			map[_T("����")] = _T("Milk");

			//Ư�� Ű�� ���� �����͸� �˻��Ѵ�
			CString str;
			if(map.Lookup(_T("����"),str))
				_tprintf(_T("���� -> %s\n\n\n"),str);

			POSITION pos = map.GetStartPosition();
			while(pos!=NULL)
			{
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s->%s\n"), strKey, strValue);
			}
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
