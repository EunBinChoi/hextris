// P.107_14.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "P.107_14.h"
#include <afxtempl.h> // 템플릿 클래스 정의를 담고있다
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
			// TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.
			_tsetlocale(LC_ALL, _T(""));
			TCHAR *szFruits[]={_T("사과"),_T("딸기"),_T("포도"),_T("오렌지"),_T("자두")};
			CList<CString, LPCTSTR> list;

			for(int i = 0 ; i < 5; i ++){
				list.AddTail(szFruits[i]);
			}
			
			POSITION pos = list.GetHeadPosition();
			while(pos != NULL){
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));

			pos = list.GetTailPosition();
			while(pos != NULL){
				CString str = list.GetPrev(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));
			pos = list.Find(CString(_T("포도")));
			list.InsertBefore(pos,CString(_T("살구")));
			list.InsertAfter(pos,CString(_T("바나나")));
			list.RemoveAt(pos);

			pos = list.GetHeadPosition();
			while(pos != NULL){
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));




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
