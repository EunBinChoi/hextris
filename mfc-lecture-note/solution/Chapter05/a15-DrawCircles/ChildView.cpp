
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
{
	m_bDrawMode = FALSE;
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
	
	POSITION pos = m_listPoints.GetHeadPosition();	//<= [a15]
	if ( pos != NULL )
	{
		CPoint &point = m_listPoints.GetNext(pos);
		dc.MoveTo(point);
	}

	while ( pos != NULL )
	{
		CPoint &point = m_listPoints.GetNext(pos);
		dc.LineTo(point);
	}
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_listPoints.RemoveAll();		//<= [a15]
	Invalidate();
	Sleep( 100 );

	// 마우스 캡처를 시작한다. (MFC 함수 사용)
	SetCapture();
	// 그리기 모드를 시작한다.
	m_bDrawMode = TRUE;
	// 좌표를 저장한다.
	m_listPoints.AddTail( point );	//<= [a15]
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// 그리기 모드이면 직선을 지우고 그리기를 반복한다.
	if (m_bDrawMode)
	{
		CPoint &pt = m_listPoints.GetTail();	//<= [a15]
		m_listPoints.AddTail(point);

		CRect rect(pt, point);	//<= [a15]
		rect.NormalizeRect();
		rect.InflateRect(1, 1);	// 폭과 높이가 0이 되는 것을 방지
		InvalidateRect(rect);
	}
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// 그리기 모드를 끝낸다.
	m_bDrawMode = FALSE;
	// 마우스 캡처를 해제한다. (API 함수 사용)
	::ReleaseCapture();
}
