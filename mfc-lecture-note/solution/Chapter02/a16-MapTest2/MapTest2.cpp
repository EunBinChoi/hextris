// MapTest2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MapTest2.h"
#include <afxtempl.h> // ���ø� Ŭ���� ���Ǹ� ��� �ִ�.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

// CString Ÿ�Կ� �ش��ϴ� �ؽ� �Լ��� �����Ƿ� �����Ѵ�.
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
		// MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
			_tprintf(_T("�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n"));
			nRetCode = 1;
		}
		else
		{
			// �ֿܼ��� �����ڵ� �ѱ� ����� ���� �ʿ��ϴ�.
			_tsetlocale(LC_ALL, _T(""));

			CMap<CString, CString&, UINT, UINT&> mapData;	//<= [a16]

			mapData[CString("ȫ�浿")] = 172;
			mapData[CString("��ö��")] = 164;
			mapData[CString("������")] = 166;
			mapData[CString("������")] = 182;
			mapData[CString("�����")] = 159;
			mapData[CString("�ּ���")] = 177;
			mapData[CString("�ſ���")] = 172;

			_tprintf(_T("�̸��̳� Ű�� �Է��Ͻʽÿ�\n"));

			TCHAR szName[100];
			CString strName;
			UINT uiHeight;

			_tscanf(_T("%s"), szName);
			strName = szName;

			if ( mapData.Lookup(strName, uiHeight) == TRUE )
			{
				_tprintf(_T("%s�� Ű: %d\n"), strName, uiHeight);
				return nRetCode;
			}
			else
			{
				_tprintf(_T("�������� �ʴ� �̸��Դϴ�. Ű�� �˻��մϴ�\n"));
			}

			POSITION pos = mapData.GetStartPosition();
			UINT uiInput = _tstoi(strName);
			UINT nCount = 0;

			while ( pos != NULL )
			{
				mapData.GetNextAssoc(pos, strName, uiHeight);
				if ( uiInput == uiHeight )
				{
					_tprintf(_T("%d�� Ű: %s\n"), uiInput, strName );
					++ nCount;
				}
			}
			if ( nCount == 0 )
				_tprintf(_T("�������� �ʴ� Ű�Դϴ�.\n"));

#if 0
			// ��(CString -> UINT) ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�.
			CMap<CString, CString&, UINT, UINT&> map;
			map[CString(_T("���"))] = 10;
			map[CString(_T("����"))] = 25;
			map[CString(_T("����"))] = 40;
			map[CString(_T("����"))] = 15;

			// Ư�� Ű ���� ���� �����͸� �˻��Ѵ�.
			UINT nCount;
			if(map.Lookup(CString(_T("����")), nCount))
				_tprintf(_T("���� %d���ڰ� ���� �ֽ��ϴ�.\n"), nCount);
#endif
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
