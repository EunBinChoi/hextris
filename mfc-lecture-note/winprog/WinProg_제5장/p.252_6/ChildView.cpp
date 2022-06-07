
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.252_6.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_bPressed( FALSE )
	, m_point(0,0)
	, m_rectEllipse( 50, 50, 500, 200 )
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
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(m_rectEllipse);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point);
		ScreenToClient(&point);
		CRgn rgn;
		rgn.CreateEllipticRgn(10,10,400,100);
		if(rgn.PtInRegion(point))
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	CRgn rgn;
	rgn.CreateEllipticRgn( m_rectEllipse.left, m_rectEllipse.top, m_rectEllipse.right, m_rectEllipse.bottom );
	if ( rgn.PtInRegion(point) )
	{
		m_bPressed = TRUE;
		m_point	= point;
		Invalidate();
	}
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ( m_bPressed != FALSE )
	{
		m_rectEllipse.OffsetRect( point - m_point );
		m_point	= point;
		Invalidate();
	}
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	if ( m_bPressed != FALSE )
	{
		m_bPressed = FALSE;
		m_rectEllipse.OffsetRect( point - m_point );
		m_point	= point;
		Invalidate();
	}
	
}
