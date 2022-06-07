
// ChildView.cpp : CChildView Ŭ������ ����
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
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_listPoints.RemoveAll();		//<= [a15]
	Invalidate();
	Sleep( 100 );

	// ���콺 ĸó�� �����Ѵ�. (MFC �Լ� ���)
	SetCapture();
	// �׸��� ��带 �����Ѵ�.
	m_bDrawMode = TRUE;
	// ��ǥ�� �����Ѵ�.
	m_listPoints.AddTail( point );	//<= [a15]
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// �׸��� ����̸� ������ ����� �׸��⸦ �ݺ��Ѵ�.
	if (m_bDrawMode)
	{
		CPoint &pt = m_listPoints.GetTail();	//<= [a15]
		m_listPoints.AddTail(point);

		CRect rect(pt, point);	//<= [a15]
		rect.NormalizeRect();
		rect.InflateRect(1, 1);	// ���� ���̰� 0�� �Ǵ� ���� ����
		InvalidateRect(rect);
	}
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// �׸��� ��带 ������.
	m_bDrawMode = FALSE;
	// ���콺 ĸó�� �����Ѵ�. (API �Լ� ���)
	::ReleaseCapture();
}
