
// ChildView.cpp : CChildView Ŭ������ ����
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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(IsDrawMode){
		CPoint &pt = Array.GetTail();
		Array.AddTail(point);
		
		CRect rect(pt, point);	//<= [a15]
		rect.NormalizeRect();
		rect.InflateRect(1, 1);	// ���� ���̰� 0�� �Ǵ� ���� ����
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
