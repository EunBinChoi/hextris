
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "ChangeCursor.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_bMoveMode( FALSE )
	, m_rectEllipse( 50, 50, 500, 200 )
	, m_ptMouse( 0, 0 )
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
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
	CPaintDC dc(this);
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse( m_rectEllipse );
}


BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// 클라이언트 영역이면 커서를 변경한다.
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point); // 커서 위치(스크린 좌표)를 얻는다.
		ScreenToClient(&point); // 스크린 좌표를 클라이언트 좌표로 변환한다.
		CRgn rgn;
		rgn.CreateEllipticRgnIndirect( m_rectEllipse ); // 타원형 리전을 생성한다.
		if(rgn.PtInRegion(point)) // 커서가 리전 안쪽에 있는지 확인한다.
			// 사용자 정의 커서로 변경한다.
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else
			// 표준 커서 중 하나로 변경한다.
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}

	// 클라이언트 영역이 아니면 운영체제가 자동으로 처리한다.
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPoint pt;
	::GetCursorPos( &pt );
	ScreenToClient( &pt );

	CRgn rgn;
	rgn.CreateEllipticRgnIndirect( m_rectEllipse );
	if ( rgn.PtInRegion(pt) )
	{
		m_bMoveMode = TRUE;
		m_ptMouse = point;
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if ( m_bMoveMode != FALSE )
	{
		m_rectEllipse.OffsetRect( point - m_ptMouse );
		m_ptMouse = point;
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bMoveMode = FALSE;

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ( m_bMoveMode )
	{ 
		CPoint pt;
		::GetCursorPos( &pt );

		switch (nChar)
		{
		case VK_LEFT:	pt.x --;	break;
		case VK_RIGHT:	pt.x ++;	break;
		case VK_UP:		pt.y --;	break;
		case VK_DOWN:	pt.y ++;	break;
		}

		::SetCursorPos( pt.x, pt.y );
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
