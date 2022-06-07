// HowToPaly.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tetris.h"
#include "HowToPaly.h"
#include "afxdialogex.h"


// CHowToPaly 대화 상자입니다.

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


// CHowToPaly 메시지 처리기입니다.


int CHowToPaly::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;


	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CHowToPaly::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString str;
	CString str2;


	//폰트 변경
	CFont fnt;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 18;
	lf.lfWeight = FW_BOLD;
	::lstrcpy(lf.lfFaceName, (LPCWSTR)"Tahoma");
	fnt.CreateFontIndirect(&lf);
	GetDlgItem(IDC_STATIC)->SetFont(&fnt);
	fnt.Detach();


	//출력할 글 저장
	str = "← (a) : Move to the left\n→ (d) : Move to the right\n↓ (s) : Move to the down\n↑ (w) : Rotate clockwise\nSpace Bar : Drop the pattern to the bottom of the frame\np : Pause/Restart the game";
	str += "\nn : New game";
	str += "\nCTRL + c : stop the game with conformation prompt";
	//글 갱신
	SetDlgItemText(IDC_STATIC,str);

}
