
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
	: m_bCaret( FALSE )
	, m_rect( CRect(50, 50, 350, 110) )
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_KILLFOCUS()
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

	CRect rect = m_rect;
	rect.InflateRect(10, 0);
	dc.Rectangle(rect);

	dc.DrawText(m_str, &m_rect,
		DT_LEFT|DT_VCENTER|DT_SINGLELINE);
}


BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// Ŭ���̾�Ʈ �����̸� Ŀ���� �����Ѵ�.
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point); // Ŀ�� ��ġ(��ũ�� ��ǥ)�� ��´�.
		ScreenToClient(&point); // ��ũ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ�Ѵ�.
		CRgn rgn;
		rgn.CreateEllipticRgn(10, 10, 400, 100); // Ÿ���� ������ �����Ѵ�.
		if(rgn.PtInRegion(point)) // Ŀ���� ���� ���ʿ� �ִ��� Ȯ���Ѵ�.
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

CPoint CChildView::UpdateCaret(BOOL bCalc)
{
	TEXTMETRIC tm;
	CClientDC dc(this);
	dc.GetTextMetrics(&tm);

	CRect rect = m_rect;
	CPoint pt = rect.CenterPoint();

	if ( m_str.IsEmpty() == FALSE )
	{
		dc.DrawText(m_str, rect,
			DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		pt.x = rect.right;
	}
	else
	{
		pt.x = rect.left;
	}
	pt.y -= tm.tmHeight / 2;

	if ( bCalc == FALSE )
		SetCaretPos( pt ); // ��ġ ����

	return pt;
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if ( m_rect.PtInRect(point) == TRUE )
	{
		TEXTMETRIC tm;
		CClientDC dc( this );
		dc.GetTextMetrics( &tm );

		CreateSolidCaret( 2, tm.tmHeight ); // ĳ�� ����
		ShowCaret(); // ȭ�鿡 ���̵��� �Ѵ�.
		UpdateCaret();
		m_bCaret = TRUE;
	}
	else
	{
		HideCaret(); // �����.
		::DestroyCaret(); // �ı��Ѵ�.
		m_bCaret = FALSE;
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ( nChar >= 32 && m_bCaret == TRUE )
	{
		CString strBackup = m_str;
		m_str += (TCHAR)nChar;

		// ������ ������� �˻�
		CPoint pt = UpdateCaret( TRUE );
		if ( m_rect.PtInRect(pt) == FALSE )
			m_str = strBackup;

		UpdateCaret();
		Invalidate();
	}
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	HideCaret(); // �����.
	::DestroyCaret(); // �ı��Ѵ�.
}
