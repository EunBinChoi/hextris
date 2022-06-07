// (심화)p.107_3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "(심화)p.107_3.h"

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

			struct People
			{
				People() {};
				People(UINT height, UINT weight )
				{
					uiHeight = height;
					uiWeight = weight;
				};

				UINT	uiHeight;
				UINT	uiWeight;

			};

			People p;
			People *ptr;

			if (argc < 2)
			{
				cout << "명령행 입력이 없습니다" << endl;
				return 0;
			}

			CString strName = argv[1];
			CMapStringToPtr mapData;

			mapData[_T("홍길동")] = new People(172, 72);
			mapData[_T("박철수")] = new People(164, 67);
			mapData[_T("오영희")] = new People(166, 51);
			mapData[_T("구오성")] = new People(182, 80);
			mapData[_T("김순희")] = new People(159, 48);
			mapData[_T("최성주")] = new People(177, 69);
			mapData[_T("신여정")] = new People(172, 51);

			void *pData = NULL;
			if ( mapData.Lookup(strName, pData) == TRUE )
			{
				People* people = (People*)pData;
				_tprintf(_T("%s의 키: %d, 몸무게: %d\n"),
					strName,people->uiHeight, people->uiWeight);
			}
			else
				_tprintf(_T("존재하지 않는 이름입니다\n"));;

			POSITION pos = mapData.GetStartPosition();
			while (pos)
			{
				mapData.GetNextAssoc(pos, strName, pData);
				delete pData;
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
