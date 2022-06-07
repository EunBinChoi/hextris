
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
	: m_mode( RED )
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
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// ���콺 ĸó�� �����Ѵ�. (MFC �Լ� ���)
	SetCapture();
	// �׸��� ��带 �����Ѵ�.
	m_bDrawMode = TRUE;
	// ��ǥ�� �����Ѵ�.
	m_x1 = m_x2 = point.x;
	m_y1 = m_y2 = point.y;
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// �׸��� ���� Ÿ���� ����� �׸��⸦ �ݺ��Ѵ�.
	if(m_bDrawMode){
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		// ������ �׸� Ÿ���� �����.
		dc.SetROP2(R2_NOT);
		dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		// ���ο� Ÿ���� �׸���.
		dc.SetROP2(R2_NOT);
		m_x2 = point.x;
		m_y2 = point.y;
		dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
	}
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	// �������� Ÿ���� �׸���.
	dc.SetROP2(R2_COPYPEN);
	m_x2 = point.x;
	m_y2 = point.y;

	COLORREF color;		//<= [a02]

	switch ( m_mode )	//<= [a02]
	{
	case RED:	color	= RGB(255,0,0);	break;
	case GREEN:	color	= RGB(0,255,0);	break;
	case BLUE:	color	= RGB(0,0,255);	break;
	}	

	CPen pen;			//<= [a02]
	pen.CreatePen( PS_SOLID, 1, color );
	dc.SelectObject( &pen );

	dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
	// �׸��� ��带 ������.
	m_bDrawMode = FALSE;
	// ���콺 ĸó�� �����Ѵ�. (API �Լ� ���)
	::ReleaseCapture();
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 	//<= [a02]
{
	switch ( nChar )
	{
	case 'R':	m_mode	= RED;		break;
	case 'G':	m_mode	= GREEN;	break;
	case 'B':	m_mode	= BLUE;		break;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
