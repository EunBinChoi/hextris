
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.252_2.h"
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	POSITION pos = Array.GetHeadPosition();
	dc.SelectStockObject(NULL_BRUSH);
	while(pos!=NULL){
		CRect rect = Array.GetNext(pos);
		dc.Ellipse(rect);
	}
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	dc.SetROP2(R2_COPYPEN);
	COLORREF COLOR= RGB(0,0,0);
	x2 = point.x;
	y2 = point.y;
	
	switch(color)
	{
	case 1:
		COLOR = RGB(255,0,0); break;

	case 2:
		COLOR = RGB(0,255,0); break;
	
	case 3:
		COLOR = RGB(0,0,255); break;
		
	}

	CPen pen;
	pen.CreatePen(PS_SOLID,1,COLOR);
	dc.SelectObject(&pen);

	CRect rect(x1,y1,x2,y2);
	dc.Ellipse(rect);
	IsDrawMode = FALSE;
	::ReleaseCapture();

	Array.AddTail(rect);
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(IsDrawMode){
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		
		dc.SetROP2(R2_NOT);
		dc.Ellipse(x1,y1,x2,y2);


		dc.SetROP2(R2_NOT);
		x2 = point.x;
		y2 = point.y;
		dc.Ellipse(x1,y1,x2,y2);
	}
	
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch(nChar)
	{
	case 'R':
		color = 1;
		break;
	case 'G':
		color = 2;
		break;

	case 'B':
		color = 3;
		break;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
