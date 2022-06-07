
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "ChangeCursor.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_bMoveMode( FALSE )
	, m_rectEllipse( 50, 50, 500, 200 )
	, m_ptMouse( 0, 0 )
	, m_posEllipse( NULL )
{
	m_listEllipse.AddTail( m_rectEllipse );
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
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
	CPaintDC dc(this);
	dc.SelectStockObject(LTGRAY_BRUSH);

	POSITION pos = m_listEllipse.GetHeadPosition();
	while ( pos != NULL )
	{
		CRect &rect = m_listEllipse.GetNext( pos );
		dc.Ellipse( rect );
	}

	if ( m_bMoveMode != FALSE )
	{
		CPen pen( PS_DOT, 1, RGB(0,0,0) );
		CPen *pOldPen = dc.SelectObject( &pen );
		dc.SelectStockObject( NULL_BRUSH );

		dc.Ellipse( m_rectEllipse );
		dc.SelectObject( pOldPen );
	}
}


BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// Ŭ���̾�Ʈ �����̸� Ŀ���� �����Ѵ�.
	if(nHitTest == HTCLIENT)
	{
		CPoint point;
		::GetCursorPos(&point); // Ŀ�� ��ġ(��ũ�� ��ǥ)�� ��´�.
		ScreenToClient(&point); // ��ũ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ�Ѵ�.

		BOOL bFound = FALSE;
		POSITION pos = m_listEllipse.GetHeadPosition();
		while ( pos != NULL )
		{
			CRect &rect = m_listEllipse.GetNext( pos );

			CRgn rgn;
			rgn.CreateEllipticRgnIndirect( rect ); // Ÿ���� ������ �����Ѵ�.

			if ( rgn.PtInRegion(point) ) // Ŀ���� ���� ���ʿ� �ִ��� Ȯ���Ѵ�.
			{
				bFound = TRUE;
				break;
			}
		}

		if ( bFound != FALSE )
			// ����� ���� Ŀ���� �����Ѵ�.
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else
			// ǥ�� Ŀ�� �� �ϳ��� �����Ѵ�.
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}

	// Ŭ���̾�Ʈ ������ �ƴϸ� �ü���� �ڵ����� ó���Ѵ�.
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPoint pt;
	::GetCursorPos( &pt );
	ScreenToClient( &pt );

	POSITION pos = m_listEllipse.GetHeadPosition(), posPrev = NULL;
	while ( pos != NULL )
	{
		posPrev = pos;
		CRect &rect = m_listEllipse.GetNext( pos );

		CRgn rgn;
		rgn.CreateEllipticRgnIndirect( rect );
		if ( rgn.PtInRegion(pt) )
		{
			m_bMoveMode = TRUE;
			m_ptMouse = point;

			m_rectEllipse = rect;
			m_posEllipse = posPrev;

			Invalidate();
			break;
		}
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if ( m_bMoveMode != FALSE )
	{
		m_rectEllipse.OffsetRect( point - m_ptMouse );
		m_ptMouse = point;
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ( m_bMoveMode != FALSE )
	{
		m_rectEllipse.OffsetRect( point - m_ptMouse );

		if ( nFlags & MK_CONTROL )	// ������ ���
		{
			m_listEllipse.AddTail( m_rectEllipse );
		}
		else	// �̵��� ���
		{
			CRect &rect = m_listEllipse.GetAt( m_posEllipse );
			rect = m_rectEllipse;
		}

		m_bMoveMode = FALSE;
		Invalidate();
	}
	CWnd::OnLButtonUp(nFlags, point);
}
