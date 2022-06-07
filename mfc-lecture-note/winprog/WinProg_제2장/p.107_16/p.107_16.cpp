// p.107_16.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "p.107_16.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CString 타입에 해당하는 해시 함수가 없으므로 정의한다
template<> UINT AFXAPI HashKey(CString& str){
	LPCTSTR key = (LPCTSTR)str;
	return HashKey(key);
}

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
			// TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.
			_tsetlocale(LC_ALL,_T(""));
			CMap<CString, CString&, UINT, UINT&>map;
			map[CString(_T("홍길동"))] = 172;
			map[CString(_T("박철수"))] = 164;
			map[CString(_T("오영희"))] = 166;
			map[CString(_T("구오성"))] = 182;
			map[CString(_T("김순희"))] = 159;
			map[CString(_T("최성주"))] = 177;
			map[CString(_T("신여정"))] = 172;

			CString str;
			_tprintf(_T("이름을 입력하세요 : "));
			_tscanf(_T("%s"), str);
			UINT height;

			if(map.Lookup(str,height)){
				_tprintf(_T("%s의 키는 %d입니다\n"),str,height);
			}

			_tprintf(_T("키를 입력하세요 : "));
			_tscanf(_T("%d"), &height);
			UINT height2;
			CString str2;
			POSITION pos = map.GetStartPosition();
			for(int i = 0 ; i < map.GetSize() ; i ++){
				map.GetNextAssoc(pos,str2,height2);
				if(height == height2)
				{
					_tprintf(_T("키는 %d를 갖는 사람은 %s 입니다\n"),height2,str2);
				}
			}

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
