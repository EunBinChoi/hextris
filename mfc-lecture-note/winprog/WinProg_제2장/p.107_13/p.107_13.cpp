// p.107_13.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#define WINVER      0x501
#include "stdafx.h"
#include "p.107_13.h"
#include <afxtempl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct Point3DColor

{

    int x, y, z;
	COLORREF color;

	Point3DColor(){}
    Point3DColor(int x0, int y0, int z0, COLORREF color0)
	{ 
		x = x0; 
		y = y0; 
		z = z0; 
		color = color0;
	}

	COLORREF GetColor() {return color;}
	void SetColor(COLORREF color0){color=color0;}

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
			CArray<Point3DColor, Point3DColor&> arr;
			arr.SetSize(5);
			
			for(int i = 0 ; i < 5; i ++)
			{
				Point3DColor pt(i,i*10, i*100, RGB(rand()%256,rand()%256,rand()%256));
				arr[i] = pt;
			}
			for(int i = 0 ; i < 5; i ++)
			{
				_tprintf(_T("%d %d %d "),arr[i].x,arr[i].y,arr[i].z);
				
				_tprintf(_T("R : %d ,"),GetRValue(arr[i].GetColor()));
				_tprintf(_T("G : %d ,"),GetGValue(arr[i].GetColor()));
				_tprintf(_T("B : %d\n"),GetBValue(arr[i].GetColor()));

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
