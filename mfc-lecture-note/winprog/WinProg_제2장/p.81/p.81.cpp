// p.81.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "p.81.h"

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
			
			_tsetlocale(LC_ALL,_T(""));
			// TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.
			CString str1;
			str1 = _T("안녕하세요."); // 문자열을 직접 대입한다
			CString str2(_T("오늘은")); // 문자열을 생성자 인자로 전달한다
			CString str3(str2); // CString 객체를 생성자 인자로 전달한다
			//CString 객체와 문자열을 붙인다
			CString str4 = str1 + _T(" ") + str2 + _T(" 즐거운 날입니다");
			_tprintf(_T("%s\n"),str1);
			_tprintf(_T("%s\n"),str2);
			_tprintf(_T("%s\n"),str3);
			_tprintf(_T("%s\n"),str4);
			str4+= _T(" 하하하");
			_tprintf(_T("%s\n"),str4);
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
