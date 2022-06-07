
// ChildView.cpp : CChildView Ŭ������ ����
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
	
	for ( int i=0; i<m_arrayPoint.GetSize(); ++i )	//<= [a02]
	{
		CPoint &point = m_arrayPoint.ElementAt( i );
		dc.Ellipse(point.x-20, point.y-20, point.x+20, point.y+20);
	}
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this); 
	m_arrayPoint.Add( point );	//<= [a02]
	Invalidate( FALSE ); 
	//onpaint �Լ��� �ڵ������� �θ��� ��
	// ���� �׷����ִ°� ������ �ʰ� �׸���
	//Invalidate( TRUE ); // ���� �׷����ִ°� ����� �׸���

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this); 
	m_arrayPoint.Add( point );	//<= [a02]
	Invalidate( FALSE );
}
