// HighScore.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tetris.h"
#include "HighScore.h"
#include "afxdialogex.h"


// CHighScore ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHighScore, CDialogEx)

CHighScore::CHighScore(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHighScore::IDD, pParent)
{

}

CHighScore::~CHighScore()
{
}

void CHighScore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHighScore, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CHighScore �޽��� ó�����Դϴ�.


void CHighScore::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	//��Ʈ ����
	CFont fnt;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 18;
	lf.lfWeight = FW_BOLD;
	::lstrcpy(lf.lfFaceName, (LPCWSTR)"Tahoma");
	fnt.CreateFontIndirect(&lf);
	GetDlgItem(IDC_STATIC)->SetFont(&fnt);
	fnt.Detach();
	
	CString str;	
	CStdioFile f;
	CString tmp_str;
	//���� ���� ���� ����
	if(f.Open(_T("score.txt"),CFile::typeText|CFile::modeRead)){
		//���Ͽ��� ���� �о�ͼ� str�� �ӽ� ����
		while(f.ReadString(tmp_str)){
			str+= tmp_str;
			str+="\n";
		}		
		f.Close();
	}else{
		this->MessageBox(_T("���� ������ �� �� �����ϴ�."));
	}
	//���Ͽ��� �о�� ���� ���� ���̾�α��� ����ƽ ���ڿ� ���
	SetDlgItemText(IDC_STATIC,str);
}
