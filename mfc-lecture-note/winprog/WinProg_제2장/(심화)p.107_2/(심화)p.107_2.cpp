// (��ȭ)p.107_2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "(��ȭ)p.107_2.h"

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
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
		/*CPtrArray pA;
      
         CArray<int, int&> li0;
         li0.SetSize(3);
         li0[0] = 3;
         li0[1] = 3;
         li0[2] = 4;

         CArray<int, int&> li1;
         li1.SetSize(3);
         li1[0] = 1;
         li1[1] = 1;
         li1[2] = 2;

         CArray<int, int&> li2;
         li2.SetSize(3);
         li2[0] = 1;
         li2[1] = 2;
         li2[2] = 3;
      
         pA.Add(&li0);
         pA.Add(&li1);
         pA.Add(&li2);
   
         CArray<int, int&> *tp;            

         for(int i = 0; i<pA.GetSize(); i++){            
            tp = (CArray<int, int&> *)pA.GetAt(i);
            for(int j = 0; j<tp->GetSize(); j++){
               _tprintf(_T("%d "),tp->GetAt(j));
            }
            _tprintf(_T("\n"));
         }
*/
		CPtrArray pA;

         int arr[3][3] = {{3,3,4},{1,1,2},{1,2,3}};

         for(int i = 0; i< 3; i++){
            CArray<int, int&>* li = new CArray<int, int&>();         
            li->SetSize(3);
            for(int j = 0; j<li->GetSize(); j++)
            {
               li->SetAt(j, arr[i][j]);               
            }   
            pA.Add(li);
         }
         CArray<int, int&> *tp;            

         for(int i = 0; i<pA.GetSize(); i++){            
            tp = (CArray<int, int&> *)pA.GetAt(i);
            for(int j = 0; j<tp->GetSize(); j++){
               _tprintf(_T("%d "),tp->GetAt(j));
            }
            _tprintf(_T("\n"));

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
