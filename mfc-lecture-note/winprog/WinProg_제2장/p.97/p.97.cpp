// p.97.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "p.97.h"

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
			TCHAR *szFruits[]={_T("���"),_T("����"),_T("����"),_T("������"),_T("�ڵ�")};
			CStringList list;

			for(int i = 0 ; i < 5; i ++){
				list.AddTail(szFruits[i]);
			}

			POSITION pos = list.GetHeadPosition();
			while(pos!=NULL){
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));

			pos = list.GetTailPosition();
			while(pos!=NULL){
				CString str = list.GetPrev(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));

			pos = list.Find(_T("����")); // �������� ��ġ�� ��´�
			list.InsertBefore(pos,_T("�챸")); // ���ʿ� �����͸� �����Ѵ�
			list.InsertAfter(pos,_T("�ٳ���")); // ���ʿ� �����͸� �����Ѵ�
			list.RemoveAt(pos);

			//�����͸� �� �տ��� ��ȯ�ϸ鼭 ����Ѵ�
			pos = list.GetHeadPosition();
			while(pos!=NULL){
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));
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
