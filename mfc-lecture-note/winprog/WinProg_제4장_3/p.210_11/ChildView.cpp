
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.210_11.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_bIsotropic  = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
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
	CRect rect;
	GetClientRect(&rect);
	dc.SetMapMode(m_bIsotropic ? MM_ISOTROPIC : MM_ANISOTROPIC);
	dc.SetWindowExt(100,100);
	dc.SetViewportExt(rect.Width(), rect.Height());
	dc.RoundRect(0,0,100,100,50,50);
	dc.DrawEdge(CRect(20,20,80,80), BDR_SUNKENINNER | BDR_RAISEDOUTER ,BF_RECT);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bIsotropic=!m_bIsotropic;
	Invalidate(TRUE);

	CWnd::OnLButtonDown(nFlags, point);
}
