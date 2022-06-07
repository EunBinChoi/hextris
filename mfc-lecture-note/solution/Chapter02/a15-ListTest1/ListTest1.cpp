// ListTest1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "ListTest1.h"

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
			// �ֿܼ��� �����ڵ� �ѱ� ����� ���� �ʿ��ϴ�.
			_tsetlocale(LC_ALL, _T(""));

			CList<UINT, UINT&> list;		//<= [a15]
			for ( UINT i=1; i<=100; i++ )
				list.AddTail( i );

			int nItem = 0;
			_tscanf(_T("%d"), &nItem);

			POSITION pos = list.GetHeadPosition(), posTemp;
			while ( pos )
			{
				posTemp = pos;
				int nValue = list.GetNext( pos );
				if ( nValue == nItem )
				{
					list.RemoveAt( posTemp );
					break;				
				}
			}

			pos = list.GetHeadPosition();
			while ( pos )
			{
				int nValue = list.GetNext( pos );
				_tprintf(_T("%d "), nValue);
			}
			_tprintf(_T("\n"));

#if 0
			/*** �ǽ� 1 ***/
			// CString ��ü�� �����̰� �Ϲ� ���ڿ��� ����Ʈ�� �߰��� �� �ִ�.
			TCHAR *szFruits[] = {
				_T("���"), _T("����"), _T("����"), _T("������"), _T("�ڵ�")
			};
			CStringList list; // ����Ʈ ��ü�� �����Ѵ�.
			for(int i=0; i<5; i++)
				list.AddTail(szFruits[i]); // ����Ʈ ���� �����͸� �߰��Ѵ�.

			/*** �ǽ� 2 ***/
			// ����Ʈ �� �տ������� ��ȯ�ϸ鼭 �����͸� ����Ѵ�.
			POSITION pos = list.GetHeadPosition();
			while(pos != NULL){
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));
			// ����Ʈ �� �ڿ������� ��ȯ�ϸ鼭 �����͸� ����Ѵ�.
			pos = list.GetTailPosition();
			while(pos != NULL){
				CString str = list.GetPrev(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));

			/*** �ǽ� 3 ***/
			pos = list.Find(_T("����")); // �������� ��ġ�� ��´�.
			list.InsertBefore(pos, _T("�챸")); // ���ʿ� �����͸� �����Ѵ�.
			list.InsertAfter(pos, _T("�ٳ���")); // ���ʿ� �����͸� �����Ѵ�.
			list.RemoveAt(pos); // �����͸� �����Ѵ�.

			// ����Ʈ �� �տ������� ��ȯ�ϸ鼭 �����͸� ����Ѵ�.
			pos = list.GetHeadPosition();
			while(pos != NULL){
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));
#endif
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
