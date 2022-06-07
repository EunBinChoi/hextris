// MapTest2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MapTest2.h"
#include <afxtempl.h> // 템플릿 클래스 정의를 담고 있다.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

// CString 타입에 해당하는 해시 함수가 없으므로 정의한다.
template <> UINT AFXAPI HashKey(CString& str)
{
	LPCTSTR key = (LPCTSTR)str;
	return HashKey(key); // LPCTSTR 타입의 해시 함수를 재호출한다.
}

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

			// 맵(CString -> UINT) 객체를 생성하고 초기화한다.
			CMap<CString, CString&, UINT, UINT&> map;
			map[CString(_T("사과"))] = 10;
			map[CString(_T("딸기"))] = 25;
			map[CString(_T("포도"))] = 40;
			map[CString(_T("수박"))] = 15;

			// 특정 키 값을 가진 데이터를 검색한다.
			UINT nCount;
			if(map.Lookup(CString(_T("수박")), nCount))
				_tprintf(_T("수박 %d상자가 남아 있습니다.\n"), nCount);
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
