
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Bitmaps.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_bPressed( FALSE )	//<= [a14]
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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
	CPaintDC dc(this);

	// ��Ʈ�� ���ҽ��� �ε��� �� ũ�� ������ ��´�.
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	// �޸� DC�� ���� �� ��Ʈ���� ������ �ִ´�.
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// ��Ʈ���� ȭ�鿡 ����Ѵ�.
	dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight,
		&dcmem, 0, 0, SRCCOPY);
	dc.StretchBlt(10, 100, bmpinfo.bmWidth*4, bmpinfo.bmHeight*2,
		&dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	// �޸� DC�� �׸��� �׸� �� �ٽ� ȭ�鿡 ����Ѵ�.
	if ( m_bPressed == FALSE )	//<= [a14]
	{
		dc.BitBlt(350, 10, bmpinfo.bmWidth, bmpinfo.bmHeight,
			&dcmem, 0, 0, SRCCOPY);
	}
	else						//<= [a14]
	{
		CRect rect;
		GetClientRect( rect );
		dc.StretchBlt( 0, 0, rect.Width(), rect.Height(),
			&dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY );
	}
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)	//<= [a14]
{
	m_bPressed = TRUE;
	Invalidate();

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)		//<= [a14]
{
	m_bPressed = FALSE;
	Invalidate();

	CWnd::OnLButtonUp(nFlags, point);
}
