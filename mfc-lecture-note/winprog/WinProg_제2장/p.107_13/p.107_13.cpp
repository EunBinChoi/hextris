// p.107_13.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

 


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
			_tprintf(_T("�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
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
		// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
		_tprintf(_T("�ɰ��� ����: GetModuleHandle ����\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
