// p..86.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p..86.h"

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
			CRect rect1(0,0,200,100); // ���簢���� ��ǥ�� �������� ���ڷ� �����Ѵ�
			CRect rect2;
			rect2.SetRect(0,0,200,100); // ���簢���� ��ǥ�� ���� �߿� �����Ѵ�

			if(rect1 == rect2)
				_tprintf(_T("�� ���簢���� ��ǥ�� �����ϴ�\n"));
			else
				_tprintf(_T("�� ���簢���� ��ǥ�� �ٸ��ϴ�\n"));

			RECT rect = {100,100,300,200};
			CRect rect3(rect);
			_tprintf(_T("%d %d\n"),rect3.Width(), rect3.Height());

			CPoint pt(200,150);
			if(rect3.PtInRect(pt))
				_tprintf(_T("���� ���簢�� ���ο� �ֽ��ϴ�\n"));
			else
				_tprintf(_T("���� ���簢�� �ܺο� �ֽ��ϴ�\n"));
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
