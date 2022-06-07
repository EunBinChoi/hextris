
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "InputCharacter.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_ptCaret( 0, 0 )
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_KEYDOWN()
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
	
	// 현재까지 입력된 글자들을 화면에 출력한다.
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str, &rect, DT_LEFT|DT_TOP);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar >= 32)	// ASCII 제어 문자를 제외시킨다.
	{
		int iIndex = GetCharIndex(m_ptCaret);
		if (iIndex == m_str.GetLength())
		{
			m_str += (TCHAR)nChar;
			m_ptCaret = UpdateCaret();
		}
		else
		{	// 덮어쓰기 모드
			m_str.Format( _T("%s%c%s"),
				m_str.Left(iIndex), nChar, m_str.Mid(iIndex+1));
			m_ptCaret = UpdateCaret(iIndex+1);
		}
		Invalidate();
	}
}


void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);

	TEXTMETRIC tm;
	CClientDC dc(this);
	dc.GetTextMetrics(&tm);

	CreateSolidCaret(2, tm.tmHeight); // 캐럿 생성
	ShowCaret(); // 화면에 보이도록 한다.
	SetCaretPos(m_ptCaret);
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	HideCaret(); // 숨긴다.
	::DestroyCaret(); // 파괴한다.	
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int iIndex = -1;

	switch (nChar)
	{
	case VK_LEFT:
		iIndex = GetCharIndex(m_ptCaret);
		iIndex --;
		if (iIndex < 0)
			iIndex = 0;
		m_ptCaret = UpdateCaret(iIndex);
		break;
	case VK_RIGHT:
		iIndex = GetCharIndex(m_ptCaret);
		iIndex ++;
		if (iIndex > m_str.GetLength())
			iIndex = m_str.GetLength();
		m_ptCaret = UpdateCaret(iIndex);
		break;
	case VK_UP:
		iIndex = GetVertCharIndex(m_ptCaret, TRUE);
		if (iIndex != -1)
			m_ptCaret = UpdateCaret(iIndex);
		break;
	case VK_DOWN:
		iIndex = GetVertCharIndex(m_ptCaret, FALSE);
		if (iIndex != -1)
		m_ptCaret = UpdateCaret(iIndex);
		break;
	}

	if (nChar == VK_RETURN)
	{
		int iIndex = GetCharIndex(m_ptCaret);
		if (iIndex == m_str.GetLength())
		{
			m_str += (TCHAR)nChar;
			m_ptCaret = UpdateCaret();
		}
		else
		{	// 삽입 모드(줄 바꿈)
			m_str.Format( _T("%s%c%s"),
				m_str.Left(iIndex), nChar, m_str.Mid(iIndex));
			m_ptCaret = UpdateCaret(iIndex+1);
		}
		Invalidate();
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CChildView::GetCharIndex(CPoint point)
{
	TEXTMETRIC tm;
	CClientDC dc(this);
	dc.GetTextMetrics(&tm);

	CRect rect;
	GetClientRect(rect);

	DWORD dwRow = point.y / tm.tmHeight;
	int iIndex = 0;
	CString str = FindRowString(m_str, dwRow, &iIndex);

	if (str.IsEmpty() == TRUE)
		return iIndex;

	if (point.x == 0)
		return iIndex;

	CString strFraction;
	CPoint pt(point);
	CRect rectCalc;

	for (int i=1; i<=str.GetLength(); i++)
	{
		rectCalc = rect;
		strFraction = str.Left(i);

		dc.DrawText(strFraction, rectCalc,
			DT_CALCRECT|DT_LEFT|DT_TOP|DT_SINGLELINE);
		if (point.x == rectCalc.right)
			return (iIndex + i);
	}

	return (-1);
}

CString CChildView::FindRowString(CString &str, DWORD dwRow, int *iIndexFound)
{
	int iIndex=0, iIndexNext=-1;

	for (DWORD i=0; i<=dwRow; i++)
	{
		iIndex = iIndexNext + 1;
		iIndexNext = str.Find(VK_RETURN, iIndex);
	}

	if (iIndexNext == -1)
		iIndexNext = str.GetLength();

	if (iIndexFound != NULL)
		*iIndexFound = iIndex;

	return str.Mid(iIndex, iIndexNext - iIndex);
}

CPoint CChildView::UpdateCaret(int iIndex, BOOL bCalc)
{
	CPoint pt = GetCaretPoint(iIndex);

	if (bCalc == FALSE)
		SetCaretPos(pt); // 위치 설정

	return pt;
}

CPoint CChildView::GetCaretPoint(int iIndex)
{
	TEXTMETRIC tm;
	CClientDC dc(this);
	dc.GetTextMetrics(&tm);

	CRect rect;
	GetClientRect(rect);
	CPoint pt(0, 0);

	CString str = (iIndex == -1) ?
		m_str : m_str.Left(iIndex);
	CRect rectCalc(rect);

	if (str.IsEmpty() == FALSE)
	{
		dc.DrawText(str, rectCalc,
			DT_CALCRECT|DT_LEFT|DT_TOP);
		pt.y = rectCalc.bottom - tm.tmHeight;

		CString strRow = FindRowString(str, pt.y / tm.tmHeight);
		if (strRow.IsEmpty() == FALSE)
		{
			rectCalc = rect;
			dc.DrawText(strRow, rectCalc,
				DT_CALCRECT|DT_LEFT|DT_TOP|DT_SINGLELINE);
			pt.x = rectCalc.right;
		}
		else
			pt.x = 0;
	}

	return pt;
}

int CChildView::GetVertCharIndex(CPoint point, BOOL bUpward)
{
	TEXTMETRIC tm;
	CClientDC dc(this);
	dc.GetTextMetrics(&tm);

	CRect rect;
	GetClientRect(rect);

	CPoint pt(point);
	if (bUpward == TRUE)
	{
		pt.y -= tm.tmHeight;
		if (pt.y < 0)
			return -1;
	}
	else
	{
		pt.y += tm.tmHeight;

		CRect rectCalc(rect);
		dc.DrawText(m_str, rectCalc,
			DT_CALCRECT|DT_LEFT|DT_TOP);
		if (pt.y > rectCalc.bottom - tm.tmHeight)
			return -1;
	}

	int dx = tm.tmAveCharWidth / 2;
	for ( int i=pt.x; i>=pt.x-dx; --i )	// 중간에서 앞쪽 검색
	{
		CPoint ptSearch(i, pt.y);
		int iIndex = GetCharIndex(ptSearch);
		if (iIndex != -1)
			return iIndex;
	}
	for ( int i=pt.x+1; i<=pt.x+dx; ++i )		// 뒤쪽 검색
	{
		CPoint ptSearch(i, pt.y);
		int iIndex = GetCharIndex(ptSearch);
		if (iIndex != -1)
			return iIndex;
	}

	// 행 끝으로 이동
	DWORD dwRow = pt.y / tm.tmHeight;
	int iIndex = 0;
	CString str = FindRowString(m_str,
		bUpward ? dwRow++ : dwRow++, &iIndex);
	return (iIndex + str.GetLength());
}
