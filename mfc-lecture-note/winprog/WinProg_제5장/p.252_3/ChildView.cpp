
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.252_3.h"
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//	ON_WM_KEYDOWN()
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
	dc.SelectStockObject(NULL_BRUSH);
	while(pos!=NULL){
		CRect rect = Array.GetNext(pos);
		dc.Ellipse(rect);
	}

}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	IsDrawMode = TRUE;

	x1 = point.x;
	y1 = point.y;
	x2 = point.x;
	y2 = point.y;
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_BLACK);

	x2 = point.x;
	y2 = point.y;

	CRect rect(x1,y1,x2,y2);

	int nVirtKey = GetKeyState(VK_SHIFT);	//<= [a03]
	if ( nVirtKey & 0x8000 )
	{
		
		dc.Rectangle(rect);
	}
	else
	{
		dc.Ellipse(rect);
	}
	IsDrawMode = FALSE;
	CWnd::OnLButtonUp(nFlags, point);
	::ReleaseCapture();

	Array.AddTail(rect);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(IsDrawMode){
		CClientDC dc(this);
	
		int nVirtKey = GetKeyState(VK_SHIFT);
		if(nVirtKey & 0x8000){
		dc.SelectStockObject(NULL_BRUSH);

		dc.SetROP2(R2_NOT);
		dc.Rectangle(x1,y1,x2,y2);

		dc.SetROP2(R2_NOT);
		x2 = point.x;
		y2 = point.y;
		dc.Rectangle(x1,y1,x2,y2);
		}

		else{
		dc.SelectStockObject(NULL_BRUSH);

		dc.SetROP2(R2_NOT);
		dc.Ellipse(x1,y1,x2,y2);

		dc.SetROP2(R2_NOT);
		x2 = point.x;
		y2 = point.y;
		dc.Ellipse(x1,y1,x2,y2);
		}
	}
	CWnd::OnMouseMove(nFlags, point);
}


