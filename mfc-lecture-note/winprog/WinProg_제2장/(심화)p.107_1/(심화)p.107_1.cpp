// (심화)p.107_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "(심화)p.107_1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 오류 코드를 필요에 따라 수정합니다.
			_tprintf(_T("심각한 오류: MFC를 초기화하지 못했습니다.\n"));
			nRetCode = 1;
		}
		else
		{
			// 콘솔에서 유니코드 한글 출력을 위해 필요하다.
			_tsetlocale(LC_ALL, _T(""));

			if ( argc < 2 ) // 0번째 배열에는 exe 이름, 1번째 배열은 명령행
			{
				_tprintf(_T("명령행 입력이 없습니다\n"));
				return 0;
			}

			CString strArg;
			for ( int i=1; i<argc; ++i )
			{
				strArg += argv[i];
			}

			strArg.Replace( _T(" "), _T("") );	// 공백 제거
			strArg.Replace( _T("'"), _T("") );	// ' 제거

			int iPos = strArg.FindOneOf( _T("+-*/") );
			if ( iPos == -1 )
			{
				_tprintf(_T("사칙 연산을 입력하세요\n"));
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
					_tprintf(_T("0으로 나눌 수 없습니다\n"));
					return 0;
				}
				lfResult = (double)iFrontEnd / iBackEnd;
			}

			// 결과 출력
			if ( strOperator != _T("/") )
				_tprintf(_T("%s=%d\n"), strArg, iResult);
			else
				_tprintf(_T("%s=%lf\n"), strArg, lfResult);

		}
	}
	else
	{
		// TODO: 오류 코드를 필요에 따라 수정합니다.
		_tprintf(_T("심각한 오류: GetModuleHandle 실패\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
