// (��ȭ)p.107_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "(��ȭ)p.107_1.h"

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

			if ( argc < 2 ) // 0��° �迭���� exe �̸�, 1��° �迭�� �����
			{
				_tprintf(_T("����� �Է��� �����ϴ�\n"));
				return 0;
			}

			CString strArg;
			for ( int i=1; i<argc; ++i )
			{
				strArg += argv[i];
			}

			strArg.Replace( _T(" "), _T("") );	// ���� ����
			strArg.Replace( _T("'"), _T("") );	// ' ����

			int iPos = strArg.FindOneOf( _T("+-*/") );
			if ( iPos == -1 )
			{
				_tprintf(_T("��Ģ ������ �Է��ϼ���\n"));
				return 0;
			}

			CString strFrontEnd = strArg.Left(iPos);
			CString strBackEnd = strArg.Mid(iPos + 1);
			CString strOperator = strArg.Mid(iPos, 1);

			int iFrontEnd = _tstoi(strFrontEnd);
			int iBackEnd = _tstoi(strBackEnd);
			int iResult = 0;
			double lfResult = 0.0;

			if ( strOperator == _T("+") )
				iResult = iFrontEnd + iBackEnd;
			else if ( strOperator == _T("-") )
				iResult = iFrontEnd - iBackEnd;
			else if ( strOperator == _T("*") )
				iResult = iFrontEnd * iBackEnd;
			else if ( strOperator == _T("/") )
			{
				if ( iBackEnd == 0 )
				{
					_tprintf(_T("0���� ���� �� �����ϴ�\n"));
					return 0;
				}
				lfResult = (double)iFrontEnd / iBackEnd;
			}

			// ��� ���
			if ( strOperator != _T("/") )
				_tprintf(_T("%s=%d\n"), strArg, iResult);
			else
				_tprintf(_T("%s=%lf\n"), strArg, lfResult);

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
