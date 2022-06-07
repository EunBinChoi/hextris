
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.210_15.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	Button = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	CBitmap bitmap;
	//CRect rect;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP info;
	bitmap.GetBitmap(&info);
	//GetClientRect(&rect);

	// �޸� DC�� ������ ��Ʈ���� ������ �ִ´�
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// ��Ʈ���� ȭ�鿡 ����Ѵ�
	dc.BitBlt(10,10,info.bmWidth, info.bmHeight,&dcmem, 0,0,SRCCOPY);
	dc.StretchBlt(10,100,info.bmWidth*4, info.bmHeight*2,&dcmem, 0,0,info.bmWidth, info.bmHeight, SRCCOPY);
	

	// �޸� DC�� �׸��� �׸� �� �ٽ� ȭ�鿡 ����Ѵ�
	if(Button == FALSE)
		dc.BitBlt(350,10,info.bmWidth, info.bmHeight,&dcmem, 0,0,SRCCOPY);
	else
		dc.StretchBlt(350+info.bmWidth-1,10+info.bmHeight-1,-info.bmWidth, -info.bmHeight,&dcmem,0,0,info.bmWidth, info.bmHeight, SRCCOPY);
	
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Button = !Button;
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


