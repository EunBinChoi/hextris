// (��ȭ)p.107_3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "(��ȭ)p.107_3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



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
			// �ֿܼ��� �����ڵ� �ѱ� ����� ���� �ʿ��ϴ�.
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
				cout << "����� �Է��� �����ϴ�" << endl;
				return 0;
			}

			CString strName = argv[1];
			CMapStringToPtr mapData;

			mapData[_T("ȫ�浿")] = new People(172, 72);
			mapData[_T("��ö��")] = new People(164, 67);
			mapData[_T("������")] = new People(166, 51);
			mapData[_T("������")] = new People(182, 80);
			mapData[_T("�����")] = new People(159, 48);
			mapData[_T("�ּ���")] = new People(177, 69);
			mapData[_T("�ſ���")] = new People(172, 51);

			void *pData = NULL;
			if ( mapData.Lookup(strName, pData) == TRUE )
			{
				People* people = (People*)pData;
				_tprintf(_T("%s�� Ű: %d, ������: %d\n"),
					strName,people->uiHeight, people->uiWeight);
			}
			else
				_tprintf(_T("�������� �ʴ� �̸��Դϴ�\n"));;

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
		// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
		_tprintf(_T("�ɰ��� ����: GetModuleHandle ����\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
