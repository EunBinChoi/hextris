// (심화)p.107_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "(심화)p.107_2.h"

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
		// TODO: 오류 코드를 필요에 따라 수정합니다.
		_tprintf(_T("심각한 오류: GetModuleHandle 실패\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
