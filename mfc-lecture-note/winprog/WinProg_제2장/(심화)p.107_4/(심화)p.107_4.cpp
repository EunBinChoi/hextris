// (��ȭ)p.107_4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "(��ȭ)p.107_4.h"

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

         _tprintf(_T("������ �Է��ϼ��� : "));
         CString str;
         TCHAR tmp[50];
         _tscanf(_T("%s"),tmp);
         str = tmp;
         CString str2;
         CString str3;
         
         CString test;      //���� �����
		 
         str.MakeUpper();   //�빮�ڷ� 

         for(int i = 0; i < str.GetLength(); i++){
            //_tprintf(_T("%c\n"),str[i]);
            str2 = str[i];
            if(map.Lookup(str2,str3)){
               test+=str3;      //���ڵ� ���� ����(���߿� ���ڷ� �ٲ㺼����)
               _tprintf(_T("%s"),str3);
            }
         }
         _tprintf(_T("\n"));

         _tprintf(_T("%s\n"),test);   //�� ���� ��� �غ��ž�
		 _tprintf(_T("��ȣ�� �Է��ϼ��� : "));
		  CString str4;
         TCHAR tmp2[50];
         _tscanf(_T("%s"),tmp2);
         str4 = tmp2;
         CString t1;   //�ӽ� �����
         while(!str4.IsEmpty()){   //���� ���ڿ��� ��� ������ ���� ������
            for(int i = 1; i<=str4.GetLength() ; i++){   

               t1 = str4.Left(i);   //���ʺ��� ©�󺼲���, ÷�� 1�� ��ã���� �״㿣 ���ʺ��� �ΰ�
                              // �� ��ã���� ���ʺ��� ����.. �̷������� ���� ¥���°� �þ�� �߾�

               //�̺κ��� map�� ��ü������ �ѹ� �ݺ��ϴ� �κ��̾�
               pCurVal = map.PGetFirstAssoc();   //�갡 ���� �ٴ� ���̱�
               while (pCurVal != NULL)
               {
                  // _tprintf_s(_T("Current key value at %s: %s\n"),pCurVal->key, pCurVal->value);
                  if(t1.Compare(pCurVal->value) == 0){   //���ٰ� ���� ���ʺ��� ¥���Ŷ� ���ڿ��� ������
                     _tprintf(_T("%s "),pCurVal->key);   //Ű���� ������ְ�
                     str4 = str4.Mid(i);               //���� ã�� ���ʺκ��� ���������
                     break;                        //�׸��� �ٽ� ���ʿ��� �ϳ��� ¥�����ϱ� �ݺ��� �ٽý���
                  }
                  pCurVal= map.PGetNextAssoc(pCurVal); //�������� ��ã������ ���� map���� �Ѿ��..
               }
            }
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
