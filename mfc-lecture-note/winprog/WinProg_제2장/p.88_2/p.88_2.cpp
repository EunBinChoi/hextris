// p.88_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "p.88_2.h"

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
			CTime startTime = CTime::GetCurrentTime();
			Sleep(2000);
			CTime endTime = CTime::GetCurrentTime();
			CTimeSpan elapsedTime = endTime - startTime;
			CString str;
			str.Format(_T("%d초 지남!"),elapsedTime.GetTotalSeconds());
			_tprintf(_T("%s\n"),str);
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
