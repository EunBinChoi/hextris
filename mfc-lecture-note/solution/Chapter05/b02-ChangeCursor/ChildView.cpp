
// ChildView.cpp : CChildView 클래스의 구현
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



// CChildView 메시지 처리기

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
	// 클라이언트 영역이면 커서를 변경한다.
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point); // 커서 위치(스크린 좌표)를 얻는다.
		ScreenToClient(&point); // 스크린 좌표를 클라이언트 좌표로 변환한다.
		CRgn rgn;
		rgn.CreateEllipticRgn(10, 10, 400, 100); // 타원형 리전을 생성한다.
		if(rgn.PtInRegion(point)) // 커서가 리전 안쪽에 있는지 확인한다.
			// 사용자 정의 커서로 변경한다.
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else
			// 표준 커서 중 하나로 변경한다.
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}

	// 클라이언트 영역이 아니면 운영체제가 자동으로 처리한다.
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
		SetCaretPos( pt ); // 위치 설정

	return pt;
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if ( m_rect.PtInRect(point) == TRUE )
	{
		TEXTMETRIC tm;
		CClientDC dc( this );
		dc.GetTextMetrics( &tm );

		CreateSolidCaret( 2, tm.tmHeight ); // 캐럿 생성
		ShowCaret(); // 화면에 보이도록 한다.
		UpdateCaret();
		m_bCaret = TRUE;
	}
	else
	{
		HideCaret(); // 숨긴다.
		::DestroyCaret(); // 파괴한다.
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

		// 영역을 벗어나는지 검사
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

	HideCaret(); // 숨긴다.
	::DestroyCaret(); // 파괴한다.
}
