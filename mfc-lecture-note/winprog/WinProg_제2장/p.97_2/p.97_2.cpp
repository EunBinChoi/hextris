// p.97_2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.97_2.h"
#include <afxtempl.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//3���� ��ǥ�� ������ �� �ִ� Ŭ����
struct string3D{
	CString x;
	CString y;
	CString z;
	string3D(){}
	string3D(CString x0, CString y0, CString z0){x = x0, y = y0, z = z0;}
};

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
			CList<string3D,string3D&> list;

			for(int i = 0 ; i < 5 ; i ++ ){
				list.AddTail(string3D(_T("dd"), _T("dddd"), _T("dddd")));
			}
	
			POSITION pos = list.GetHeadPosition();
			for(int i = 0 ; i < list.GetSize(); i++)
			{
				string3D pt= list.GetNext(pos);
				_tprintf(_T("%s %s %s\n"),pt.x, pt.y, pt.z);
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
