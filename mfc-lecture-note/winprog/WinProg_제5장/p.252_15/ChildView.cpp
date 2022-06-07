
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.252_15.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	IsDrawMode = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
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
	
	POSITION pos = Array.GetHeadPosition();
	if ( pos != NULL )
	{
		CPoint &point = Array.GetNext(pos);
		dc.MoveTo(point);
	}
	while ( pos != NULL )
	{
		CPoint &point = Array.GetNext(pos);
		dc.LineTo(point);
	}

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(IsDrawMode){
		CPoint &pt = Array.GetTail();
		Array.AddTail(point);
		
		CRect rect(pt, point);	//<= [a15]
		rect.NormalizeRect();
		rect.InflateRect(1, 1);	// 폭과 높이가 0이 되는 것을 방지
		InvalidateRect(rect); 
	}
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	Array.RemoveAll();
	Invalidate();
	Sleep(100);

	SetCapture();
	IsDrawMode = TRUE;
	Array.AddTail(point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	IsDrawMode = FALSE;
	::ReleaseCapture();

	
}
