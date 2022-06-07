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
	return HashKey(key);
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

			CMap<CString, CString&, UINT, UINT&> mapData;	//<= [a16]

			mapData[CString("홍길동")] = 172;
			mapData[CString("박철수")] = 164;
			mapData[CString("오영희")] = 166;
			mapData[CString("구오성")] = 182;
			mapData[CString("김순희")] = 159;
			mapData[CString("최성주")] = 177;
			mapData[CString("신여정")] = 172;

			_tprintf(_T("이름이나 키를 입력하십시오\n"));

			TCHAR szName[100];
			CString strName;
			UINT uiHeight;

			_tscanf(_T("%s"), szName);
			strName = szName;

			if ( mapData.Lookup(strName, uiHeight) == TRUE )
			{
				_tprintf(_T("%s의 키: %d\n"), strName, uiHeight);
				return nRetCode;
			}
			else
			{
				_tprintf(_T("존재하지 않는 이름입니다. 키를 검색합니다\n"));
			}

			POSITION pos = mapData.GetStartPosition();
			UINT uiInput = _tstoi(strName);
			UINT nCount = 0;

			while ( pos != NULL )
			{
				mapData.GetNextAssoc(pos, strName, uiHeight);
				if ( uiInput == uiHeight )
				{
					_tprintf(_T("%d의 키: %s\n"), uiInput, strName );
					++ nCount;
				}
			}
			if ( nCount == 0 )
				_tprintf(_T("존재하지 않는 키입니다.\n"));

#if 0
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
#endif
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
