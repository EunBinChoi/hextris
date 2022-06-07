
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "DrawCircles.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_iLevel( 1 ), m_bAlt( FALSE ), m_bSpaceBar( FALSE )	//<= [a16]
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
ON_WM_MOUSEMOVE()
ON_WM_KEYDOWN()
ON_WM_KEYUP()
ON_WM_SYSKEYDOWN()
ON_WM_SYSKEYUP()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// 비트맵 리소스를 로드한 후 크기 정보를 얻는다.
	CBitmap bitmap;		//<= [a16]
	bitmap.LoadBitmap( IDB_BITMAP1 );
	BITMAP bmpinfo;
	bitmap.GetBitmap( &bmpinfo );

	// 메모리 디바이스 컨텍스트를 만든 후 비트맵을 선택해 넣는다.
	CDC dcmem;			//<= [a16]
	dcmem.CreateCompatibleDC( &dc );
	dcmem.SelectObject( &bitmap );

	// 비트맵을 화면에 출력한다.
	dc.StretchBlt( 0, 0,
		m_iLevel * bmpinfo.bmWidth, m_iLevel * bmpinfo.bmHeight, 
		&dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY );	//<= [a16]
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
}


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
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_SPACE)
	{
		m_bSpaceBar = TRUE;
		return;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
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
	CWnd::OnSysKeyUp(nChar, nRepCnt, nFlags);
}
