// p.107_15.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.107_15.h"

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
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			_tsetlocale(LC_ALL,_T(""));
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			
			CList<UINT, UINT&> list;
			//int szFruits[100];
			   
			
			for(UINT i = 1 ; i <= 100; i ++){
				list.AddTail(i);
			}

			UINT d;
			_tprintf(_T("1~100������ ���� �Է��ϼ��� : "));
			_tscanf(_T("%d"),&d);

			POSITION pos = list.GetHeadPosition();
			while(pos!=NULL){
				
				UINT d2 = list.GetAt(pos);
				if(d == d2){
					list.RemoveAt(pos);		
				}
				list.GetNext(pos);

				
			}


			pos = list.GetHeadPosition();
			while(pos!=NULL){
				UINT d2 = list.GetNext(pos);
				_tprintf(_T("%d\n"),d2);
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
