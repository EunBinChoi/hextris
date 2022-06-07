// p.97_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "p.97_2.h"
#include <afxtempl.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//3차원 좌표를 저장할 수 있는 클래스
struct string3D{
	CString x;
	CString y;
	CString z;
	string3D(){}
	string3D(CString x0, CString y0, CString z0){x = x0, y = y0, z = z0;}
};

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
			CList<string3D,string3D&> list;

			for(int i = 0 ; i < 5 ; i ++ ){
				list.AddTail(string3D(_T("dd"), _T("dddd"), _T("dddd")));
			}
	
			POSITION pos = list.GetHeadPosition();
			for(int i = 0 ; i < list.GetSize(); i++)
			{
				string3D pt= list.GetNext(pos);
				_tprintf(_T("%s %s %s\n"),pt.x, pt.y, pt.z);
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
