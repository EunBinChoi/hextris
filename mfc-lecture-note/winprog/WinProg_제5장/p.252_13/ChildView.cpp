
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.252_13.h"
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_NCMOUSEMOVE()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
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
	
	POSITION pos = Array.GetHeadPosition();
	dc.SelectStockObject(NULL_BRUSH);
	while(pos!=NULL){
		CRect rect = Array.GetNext(pos);
		dc.Ellipse(rect);
	}

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_BLACK);
	
	x2 = point.x;
	y2 = point.y;
	
	CRect rect(x1,y1,x2,y2);
	dc.Ellipse(rect);
	IsDrawMode = FALSE;
	CWnd::OnLButtonUp(nFlags, point);
	::ReleaseCapture();

	Array.AddTail(rect);
	CWnd::OnLButtonUp(nFlags, point);
}


//void CChildView::OnNcMouseMove(UINT nHitTest, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//
//	CWnd::OnNcMouseMove(nHitTest, point);
//}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	if ( nChar == VK_DELETE )
	{
		if ( Array.GetCount() > 0 )
		{
			Array.RemoveTail();
			Invalidate();
		}
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
