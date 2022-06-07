// p.107_11.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "p.107_11.h"

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
			
			_tsetlocale(LC_ALL, _T(""));
			// TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.
			CTime startTime = CTime::GetCurrentTime();
			CTime endTime = startTime.operator+(1000);
			CTimeSpan timeSpan = endTime - startTime;
			CString str1= startTime.Format(_T("%A, %B %d, %Y"));
			str1.Format(_T("%d년 %d월 %d일, %d시 %d분 %d초"),startTime.GetYear(),startTime.GetMonth(),startTime.GetDay(),startTime.GetHour(), startTime.GetMinute(),startTime.GetSecond() );
			CString str2= endTime.Format(_T("%A, %B %d, %Y"));
			str2.Format(_T("%d년 %d월 %d일, %d시 %d분 %d초"),endTime.GetYear(),endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(), endTime.GetMinute(),endTime.GetSecond() );
			_tprintf(_T("%s의 "),str1);
			_tprintf(_T("%d일 후는 "), timeSpan);
			_tprintf(_T("%s입니다\n"),str2);
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
