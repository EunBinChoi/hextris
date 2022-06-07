
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.252_5.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView(): m_rectEllipse( 50, 50, 500, 200 )
{
		//<= [a05]
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
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
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(m_rectEllipse);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// Ŭ���̾�Ʈ �����̸� Ŀ���� �����Ѵ�.
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point); // Ŀ�� ��ġ(��ũ�� ��ǥ)�� ��´�.
		ScreenToClient(&point); // ��ũ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ�Ѵ�.
		CRgn rgn;
		rgn.CreateEllipticRgn( m_rectEllipse.left, m_rectEllipse.top, m_rectEllipse.right, m_rectEllipse.bottom ); // Ÿ���� ������ �����Ѵ�.	//<= [a05]
		if(rgn.PtInRegion(point)) // Ŀ���� ���� ���ʿ� �ִ��� Ȯ���Ѵ�.
			// ����� ���� Ŀ���� �����Ѵ�.
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else
			// ǥ�� Ŀ�� �� �ϳ��� �����Ѵ�.
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	m_rectEllipse = CRect( point.x,point.y, point.x+ (int)m_rectEllipse.Width(),point.y+(int)m_rectEllipse.Height() );
	Invalidate();

	CWnd::OnMouseMove(nFlags, point);
}
