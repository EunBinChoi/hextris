
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.210_5.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL,NULL,NULL,NULL);
	dc.Rectangle(0,0,10,10);
	dc.Ellipse(1,1,9,9);
	m_hmf = dc.CloseEnhanced();
}

CChildView::~CChildView()
{
	::DeleteEnhMetaFile(m_hmf);
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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
	
	POSITION pos = list.GetHeadPosition();
	while(pos){
		CPoint point = list.GetNext(pos);
		CRect rect(point.x-20,point.y-20,point.x+20,point.y+20);
		dc.PlayMetaFile(m_hmf,&rect);
		
	}
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CRect rect(point.x-20,point.y-20,point.x+20,point.y+20);
	
	//dc.Rectangle(rect);
	dc.PlayMetaFile(m_hmf,&rect);
	list.AddTail(point);
	Invalidate(FALSE);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CRect rect(point.x-20,point.y-20,point.x+20,point.y+20);
	
//dc.Rectangle(rect);
	dc.PlayMetaFile(m_hmf,&rect);
	list.AddTail(point);
	Invalidate(FALSE);
}
