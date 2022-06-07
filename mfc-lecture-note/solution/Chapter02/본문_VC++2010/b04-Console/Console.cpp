// Console.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Console.h"

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

			CMapStringToString mapData;

			mapData[_T("111")]			= _T(" ");
			mapData[_T("1010")]			= _T("A");
			mapData[_T("0010011")]		= _T("B");
			mapData[_T("01001")]		= _T("C");
			mapData[_T("01110")]		= _T("D");
			mapData[_T("110")]			= _T("E");
			mapData[_T("0111100")]		= _T("F");
			mapData[_T("0111110")]		= _T("G");
			mapData[_T("0010010")]		= _T("H");
			mapData[_T("1000")]			= _T("I");
			mapData[_T("011111110")]	= _T("J");
			mapData[_T("011111111001")] = _T("K");
			mapData[_T("0001")]			= _T("L");
			mapData[_T("00101")]		= _T("M");
			mapData[_T("1001")]			= _T("N");
			mapData[_T("0000")]			= _T("O");
			mapData[_T("01000")]		= _T("P");
			mapData[_T("0111101")]		= _T("Q");
			mapData[_T("0101")]			= _T("R");
			mapData[_T("1011")]			= _T("S");
			mapData[_T("0110")]			= _T("T");
			mapData[_T("0011")]			= _T("U");
			mapData[_T("001000")]		= _T("V");
			mapData[_T("011111111000")] = _T("W");
			mapData[_T("01111110")]		= _T("X");
			mapData[_T("0111111111")]	= _T("Y");
			mapData[_T("01111111101")]	= _T("Z");

			_tprintf(_T("영문 또는 기호를 입력하십시오\n"));

			TCHAR szInput[100];
			CString strInput, strOutput;

			_tscanf(_T("%s"), szInput);
			strInput = szInput;
			strInput.MakeUpper();	// 대문자로 변환

			strOutput.Empty();

			// 기호부터 검색
			for ( int i=1; i<=strInput.GetLength(); i++ )
			{
				CString strFraction = strInput.Left(i);
				CString strResult;
				if ( mapData.Lookup(strFraction, strResult) == TRUE )
				{
					strOutput += strResult;
					strInput = strInput.Mid(i);
					i = 0;
				}
			}

			if ( strOutput.IsEmpty() == FALSE )
			{
				_tprintf(_T("\t=> %s\n"), strOutput);
				return nRetCode;
			}

			// 다음 문자 검색
			for ( int j=0; j<strInput.GetLength(); j++ )
			{
				CString strKey, strValue;
				POSITION pos = mapData.GetStartPosition();
				while ( pos != NULL )
				{
					mapData.GetNextAssoc( pos, strKey, strValue );
					if ( strValue == strInput[j] )
					{
						strOutput += strKey;
						break;
					}
				}
			}

			if ( strOutput.IsEmpty() == FALSE )
			{
				_tprintf(_T("\t=> %s\n"), strOutput);
				return nRetCode;
			}
			else
			{
				_tprintf(_T("잘못된 영문 또는 기호를 입력하셨습니다\n"));
				return 2;
			}

#if 0
			CString str;
			str.LoadString(IDS_APP_TITLE);
			_tprintf(_T("Hello from %s!\n"), str);
#endif
#if 0
			CString str1;
			str1 = _T("안녕하세요."); // 문자열을 직접 대입한다.
			CString str2(_T("오늘은")); // 문자열을 생성자 인자로 전달한다.
			CString str3(str2); // CString 객체를 생성자 인자로 전달한다.
			// CString 객체와 문자열을 붙인다.
			CString str4 = str1 + _T(" ") + str2 + _T(" 즐거운 날입니다.");
			_tprintf(_T("%s\n"), str1);
			_tprintf(_T("%s\n"), str2);
			_tprintf(_T("%s\n"), str3);
			_tprintf(_T("%s\n"), str4);
			// + = 연산자를 이용하여 기존 문자열에 새로운 문자열을 덧붙인다.
			str4 += _T(" 하하하");
			_tprintf(_T("%s\n"), str4);
#endif
#if 0
			CString str;
			str.Format(_T("x=%d, y=%d\n"), 100, 200);
			MessageBox(NULL, str, _T("CString::Format() 연습"), MB_OK);
#endif
#if 0
			CString str;
			str.LoadString(IDS_APP_TITLE); // 문자열 리소스를 로드한다.
			str.Insert(0, _T("Hello from ")); // 맨 앞에 문자열을 삽입한다.
			str.Append(_T("!")); // 맨 끝에 문자열을 덧붙인다.
			MessageBox(NULL, str, _T("CString::LoadString() 연습"), MB_OK);
#endif
#if 0
			CPoint pt1(10, 20); // x, y 좌표를 생성자 인자로 전달한다.
			POINT pt = {30, 40};
			CPoint pt2(pt); // POINT 타입 변수를 생성자 인자로 전달한다.
			_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			pt1.Offset(40, 30); // x, y 좌표에 각각 40, 30을 더한다.
			pt2.Offset(20, 10); // x, y 좌표에 각각 20, 10을 더한다.
			_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			if(pt1 == pt2) // 두 객체의 내용이 같은지 확인한다.
				_tprintf(_T("두 점의 좌표가 같습니다.\n"));
			else
				_tprintf(_T("두 점의 좌표가 다릅니다.\n"));
#endif
#if 0
			CRect rect1(0, 0, 200, 100); // 직사각형의 좌표를 생성자의 인자로 전달한다.
			CRect rect2;
			rect2.SetRect(0, 0, 200, 100); // 직사각형의 좌표를 실행 중에 설정한다.
			if(rect1 == rect2) // 두 객체의 내용이 같은지 확인한다.
				_tprintf(_T("두 직사각형의 좌표가 같습니다.\n"));
			else
				_tprintf(_T("두 직사각형의 좌표가 다릅니다.\n"));
			RECT rect = {100, 100, 300, 200};
			CRect rect3(rect); // RECT 타입 변수를 생성자 인자로 전달한다.
			_tprintf(_T("%d, %d\n"), rect3.Width(), rect3.Height());

			CPoint pt(200, 150);
			if(rect3.PtInRect(pt)) // 점이 직사각형 내부에 있는지 판단한다.
				_tprintf(_T("점이 직사각형 내부에 있습니다.\n"));
			else
				_tprintf(_T("점이 직사각형 외부에 있습니다.\n"));
#endif
#if 0
			CSize size1(100, 200); // 폭과 높이를 생성자 인자로 전달한다.
			SIZE size = {100, 200};
			CSize size2(size); // SIZE 타입 변수를 생성자 인자로 전달한다.
			_tprintf(_T("%d, %d\n"), size2.cx, size2.cy);
			if(size1 == size2) // 두 객체의 내용이 같은지 확인한다.
				_tprintf(_T("크기가 같습니다.\n"));
			else
				_tprintf(_T("크기가 다릅니다.\n"));
#endif
#if 0
			// CTime::GetCurrentTime() 함수로 현재 시각을 구한다.
			CTime tm;
			tm = CTime::GetCurrentTime();
			// 여러 형식으로 화면에 출력한다.
			CString str = tm.Format(_T("%A, %B %d, %Y"));
			_tprintf(_T("%s\n"), str);
			str.Format(_T("현재 시각은 %d시 %d분 %d초입니다."),
				tm.GetHour(), tm.GetMinute(), tm.GetSecond());
			_tprintf(_T("%s\n"), str);
#endif
#if 0
			CTime startTime = CTime::GetCurrentTime();
			Sleep(2000); // 2000 밀리초 지연
			CTime endTime = CTime::GetCurrentTime();
			CTimeSpan elapsedTime = endTime - startTime;
			CString str;
			str.Format(_T("%d초 지남!"), elapsedTime.GetTotalSeconds());
			_tprintf(_T("%s\n"), str);
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
