
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "ClientDC.h"
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
//	ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
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
	
	for ( int i=0; i<m_arrayPoint.GetSize(); ++i )	//<= [a02]
	{
		CPoint &point = m_arrayPoint.ElementAt( i );
		dc.Ellipse(point.x-20, point.y-20, point.x+20, point.y+20);
	}
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this); 
	m_arrayPoint.Add( point );	//<= [a02]
	Invalidate( FALSE ); 
	//onpaint 함수를 자동적으로 부르는 것
	// 현재 그려져있는거 지우지 않고 그린다
	//Invalidate( TRUE ); // 현재 그려져있는거 지우고 그린다

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this); 
	m_arrayPoint.Add( point );	//<= [a02]
	Invalidate( FALSE );
}
