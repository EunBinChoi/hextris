
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.252_16.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	//ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_WM_KEYDOWN()
ON_WM_KEYUP()
ON_WM_SYSKEYUP()
ON_WM_SYSKEYDOWN()
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
	
	// ��Ʈ�� ���ҽ��� �ε��� �� ũ�� ������ ��´�.
	CBitmap bitmap;		//<= [a16]
	bitmap.LoadBitmap( IDB_BITMAP1 );
	BITMAP bmpinfo;
	bitmap.GetBitmap( &bmpinfo );

	// �޸� ����̽� ���ؽ�Ʈ�� ���� �� ��Ʈ���� ������ �ִ´�.
	CDC dcmem;			//<= [a16]
	dcmem.CreateCompatibleDC( &dc );
	dcmem.SelectObject( &bitmap );

	// ��Ʈ���� ȭ�鿡 ����Ѵ�.
	dc.StretchBlt( 0, 0,
		m_iLevel * bmpinfo.bmWidth, m_iLevel * bmpinfo.bmHeight, 
		&dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY );	//<= [a16]
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}




//void CChildView::OnMButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//
//	CWnd::OnMButtonDblClk(nFlags, point);
//}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ( m_bSpaceBar == TRUE )	//<= [a16]
	{
		if ( nFlags & MK_CONTROL )
			++ m_iLevel;
		else if ( m_bAlt == TRUE )
			-- m_iLevel;

		NormalizeLevel();
		Invalidate();
	}

	CWnd::OnLButtonUp(nFlags, point);
}




void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ( nChar == VK_SPACE )
	{
		m_bSpaceBar = FALSE;
		return;
	}
	else if ( nChar == VK_MENU )
	{
		m_bAlt = FALSE;
		return;
	}
	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}



void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	if (nChar == VK_SPACE)
	{
		m_bSpaceBar = TRUE;
		return;
	}

	else if ( nChar == VK_MENU )
	{
		m_bAlt = TRUE;
		return;
	}
	
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);

}


void CChildView::OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ( nChar == VK_MENU )
	{
		m_bAlt = FALSE;
		return;
	}
	else if ( nChar == VK_SPACE )
	{
		m_bSpaceBar = FALSE;
		return;
	}
	CWnd::OnSysKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ( nChar == VK_MENU )
	{
		m_bAlt = TRUE;
		return;
	}
	else if ( nChar == VK_SPACE )
	{
		m_bSpaceBar = TRUE;
		return;
	}
	CWnd::OnSysKeyDown(nChar, nRepCnt, nFlags);
}
