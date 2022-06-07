// (심화)p.107_4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "(심화)p.107_4.h"

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
         CMapStringToString map;
         CMapStringToString::CPair* pCurVal;
         map[_T(" ")] = _T("111");
         map[_T("A")] = _T("1010");
         map[_T("B")] = _T("0010011");
         map[_T("C")] = _T("01001");
         map[_T("D")] = _T("01110");
         map[_T("E")] = _T("110");
         map[_T("F")] = _T("0111100");
         map[_T("G")] = _T("0111110");
         map[_T("H")] = _T("0010010");
         map[_T("I")] = _T("1000");
         map[_T("J")] = _T("011111110");
         map[_T("K")] = _T("011111111001");
         map[_T("L")] = _T("0001");
         map[_T("M")] = _T("00101");
         map[_T("N")] = _T("1001");
         map[_T("O")] = _T("0000");
         map[_T("P")] = _T("01000");
         map[_T("Q")] = _T("0111101");
         map[_T("R")] = _T("0101");
         map[_T("S")] = _T("1011");
         map[_T("T")] = _T("0110");
         map[_T("U")] = _T("0011");
         map[_T("V")] = _T("001000");
         map[_T("W")] = _T("011111111000");
         map[_T("X")] = _T("01111110");
         map[_T("Y")] = _T("0111111111");
         map[_T("Z")] = _T("01111111101");

         _tprintf(_T("영문을 입력하세요 : "));
         CString str;
         TCHAR tmp[50];
         _tscanf(_T("%s"),tmp);
         str = tmp;
         CString str2;
         CString str3;
         
         CString test;      //숫자 저장용
		 
         str.MakeUpper();   //대문자로 

         for(int i = 0; i < str.GetLength(); i++){
            //_tprintf(_T("%c\n"),str[i]);
            str2 = str[i];
            if(map.Lookup(str2,str3)){
               test+=str3;      //숫자들 누적 저장(나중에 문자로 바꿔볼려고)
               _tprintf(_T("%s"),str3);
            }
         }
         _tprintf(_T("\n"));

         _tprintf(_T("%s\n"),test);   //걍 숫자 출력 해본거야
		 _tprintf(_T("기호를 입력하세요 : "));
		  CString str4;
         TCHAR tmp2[50];
         _tscanf(_T("%s"),tmp2);
         str4 = tmp2;
         CString t1;   //임시 저장소
         while(!str4.IsEmpty()){   //숫자 문자열이 비어 있을때 까지 돌꺼야
            for(int i = 1; i<=str4.GetLength() ; i++){   

               t1 = str4.Left(i);   //왼쪽부터 짤라볼껀데, 첨엔 1개 못찾으면 그담엔 왼쪽부터 두개
                              // 또 못찾으면 왼쪽부터 세개.. 이런식으로 점점 짜르는게 늘어나게 했어

               //이부분은 map을 전체적으로 한번 반복하는 부분이야
               pCurVal = map.PGetFirstAssoc();   //얘가 돌아 다닐 아이구
               while (pCurVal != NULL)
               {
                  // _tprintf_s(_T("Current key value at %s: %s\n"),pCurVal->key, pCurVal->value);
                  if(t1.Compare(pCurVal->value) == 0){   //돌다가 값이 왼쪽부터 짜른거랑 문자열이 같으면
                     _tprintf(_T("%s "),pCurVal->key);   //키값을 출력해주고
                     str4 = str4.Mid(i);               //이제 찾은 왼쪽부분은 없애줘야지
                     break;                        //그리고 다시 왼쪽에서 하나씩 짜를꺼니까 반복문 다시시작
                  }
                  pCurVal= map.PGetNextAssoc(pCurVal); //벨류에서 못찾았으면 다음 map으로 넘어가게..
               }
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
