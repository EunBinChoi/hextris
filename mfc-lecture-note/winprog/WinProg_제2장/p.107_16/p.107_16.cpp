// p.107_16.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.107_16.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CString Ÿ�Կ� �ش��ϴ� �ؽ� �Լ��� �����Ƿ� �����Ѵ�
template<> UINT AFXAPI HashKey(CString& str){
	LPCTSTR key = (LPCTSTR)str;
	return HashKey(key);
}

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
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			_tsetlocale(LC_ALL,_T(""));
			CMap<CString, CString&, UINT, UINT&>map;
			map[CString(_T("ȫ�浿"))] = 172;
			map[CString(_T("��ö��"))] = 164;
			map[CString(_T("������"))] = 166;
			map[CString(_T("������"))] = 182;
			map[CString(_T("�����"))] = 159;
			map[CString(_T("�ּ���"))] = 177;
			map[CString(_T("�ſ���"))] = 172;

			CString str;
			_tprintf(_T("�̸��� �Է��ϼ��� : "));
			_tscanf(_T("%s"), str);
			UINT height;

			if(map.Lookup(str,height)){
				_tprintf(_T("%s�� Ű�� %d�Դϴ�\n"),str,height);
			}

			_tprintf(_T("Ű�� �Է��ϼ��� : "));
			_tscanf(_T("%d"), &height);
			UINT height2;
			CString str2;
			POSITION pos = map.GetStartPosition();
			for(int i = 0 ; i < map.GetSize() ; i ++){
				map.GetNextAssoc(pos,str2,height2);
				if(height == height2)
				{
					_tprintf(_T("Ű�� %d�� ���� ����� %s �Դϴ�\n"),height2,str2);
				}
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
