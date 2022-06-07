// ArrayTest2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "ArrayTest2.h"
#include <afxtempl.h> // ���ø� Ŭ���� ���Ǹ� ��� �ִ�.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

// 3���� ��ǥ�� ������ �� �ִ� Ŭ����
// ��� ����� public�� ���� class ��� struct�� ����ϸ� ���� ���ϴ�.
struct Point3DColor {
	int x, y, z;
	COLORREF color;	//<= [a13]
	Point3DColor() {} // ���ø� Ŭ������ ����� ���� �ݵ�� �⺻ �����ڰ� �ʿ��ϴ�.
	Point3DColor(int x0, int y0, int z0, COLORREF c) { x = x0; y = y0; z = z0; color = c; }
};

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
			// Point3DColor ��ü�� ������ �� �ִ� �迭 ��ü�� �����Ѵ�.
			CArray<Point3DColor, Point3DColor&> array;
			array.SetSize(5);
			for(int i=0; i<5; i++){
				Point3DColor pt(i, i*10, i*100, i*1000);
				array[i] = pt;
			}
			for(int i=0; i<5; i++){
				Point3DColor pt = array[i];
				_tprintf(_T("%d, %d, %d, %d\n"), pt.x, pt.y, pt.z, pt.color);
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
