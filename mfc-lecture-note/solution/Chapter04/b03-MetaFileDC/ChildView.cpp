
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MetaFileDC.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	// Ȯ�� ��Ÿ���� ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�.
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL, NULL, NULL, NULL);
	// ��� �Լ��� ȣ���Ͽ� ����Ѵ�.
	dc.Rectangle(0, 0, 10, 10);
	dc.Ellipse(1, 1, 9, 9);
	// Ȯ�� ��Ÿ���� �ڵ��� ��´�.
	m_hmf = dc.CloseEnhanced();

	m_dcMetaFile.CreateEnhanced( NULL, _T("Test.emf"), NULL, NULL );	//<= [b03]
}

CChildView::~CChildView()
{
	// Ȯ�� ��Ÿ������ �����Ѵ�.
	::DeleteEnhMetaFile(m_hmf);

	m_dcMetaFile.CloseEnhanced();	//<= [b03]
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
	
	POSITION pos = m_list.GetHeadPosition();	//<= [b03]
	while ( pos != NULL )
	{
		CRect &rect = m_list.GetNext( pos );

		m_dcMetaFile.PlayMetaFile( m_hmf, &rect );
		dc.PlayMetaFile( m_hmf, &rect );
	}

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CRect rect(point.x-20, point.y-20, point.x+20, point.y+20);
//	dc.PlayMetaFile(m_hmf, &rect);

	m_list.AddTail( rect );	//<= [b03]
	Invalidate();
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CRect rect(point.x-50, point.y-20, point.x+50, point.y+20);
//	dc.PlayMetaFile(m_hmf, &rect);

	m_list.AddTail( rect );	//<= [b03]
	Invalidate();
}
