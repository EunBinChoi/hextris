// HowToPaly.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tetris.h"
#include "HowToPaly.h"
#include "afxdialogex.h"


// CHowToPaly ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHowToPaly, CDialogEx)

	CHowToPaly::CHowToPaly(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHowToPaly::IDD, pParent)
{

}

CHowToPaly::~CHowToPaly()
{
}

void CHowToPaly::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHowToPaly, CDialogEx)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CHowToPaly �޽��� ó�����Դϴ�.


int CHowToPaly::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;


	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void CHowToPaly::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString str;
	CString str2;


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


	//����� �� ����
	str = "�� (a) : Move to the left\n�� (d) : Move to the right\n�� (s) : Move to the down\n�� (w) : Rotate clockwise\nSpace Bar : Drop the pattern to the bottom of the frame\np : Pause/Restart the game";
	str += "\nn : New game";
	str += "\nCTRL + c : stop the game with conformation prompt";
	//�� ����
	SetDlgItemText(IDC_STATIC,str);

}
