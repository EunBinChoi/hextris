// p.85.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// 

#include "stdafx.h"
#include "p.85.h"

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
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�
			CPoint pt1(10,20); // x,y��ǥ�� ������ ���ڷ� �����Ѵ�
			POINT pt = {30,40}; 
			CPoint pt2(pt); // POINT Ÿ�� ������ ������ ���ڷ� �����Ѵ�
			_tprintf(_T("%d, %d\n"),pt1.x, pt1.y);
			_tprintf(_T("%d, %d\n"),pt2.x, pt2.y);
			pt1.Offset(40,30); // x,y��ǥ�� ���� 40,30�� ���Ѵ�
			pt2.Offset(20,10);
			_tprintf(_T("%d, %d\n"),pt1.x, pt1.y);
			_tprintf(_T("%d, %d\n"),pt2.x, pt2.y);
			_tsetlocale(LC_ALL,_T(""));
			if(pt1==pt2) // �� ��ü�� ������ ������ Ȯ���Ѵ�
				_tprintf(_T("�� ���� ��ǥ�� �����ϴ�\n"));
			else
				_tprintf(_T("�� ���� ��ǥ�� �ٸ��ϴ�\n"));
			
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
