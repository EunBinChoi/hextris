
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.252_10.h"
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
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_CHAR()
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CFont font;
	font.CreatePointFont(150,_T("궁서"));
	dc.SelectObject(&font);

	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT|DT_SINGLELINE);
	//dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT|DT_SINGLELINE|DT_CALCRECT);	//<= [a10]


	
	CPoint pt;	//<= [a10]
	if ( m_str.GetSize() > 0 )
	{
		pt = rect.BottomRight();
		pt.y -= 15;
	}
	else
	{
		pt = CPoint(0,0);
	}
	SetCaretPos( pt );
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CreateSolidCaret(20,20); //캐럿을 생성한다
	SetCaretPos(CPoint(50,50)); // 캐럿의 위치를 설정한다
	ShowCaret(); // 캐럿을 화면에 보인다
	CWnd::OnSetFocus(pOldWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	HideCaret(); // 캐럿을 숨긴다
	::DestroyCaret(); //캐럿을 파괴한다
	CWnd::OnKillFocus(pNewWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{// Backspace 입력 시 맨 마지막 글자를 삭제한다.
	if(nChar == _T('\b')){
		if(m_str.GetSize() > 0)
			m_str.RemoveAt(m_str.GetSize()-1);
	}
	// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
	else{
		m_str.Add(nChar);
	}

	// 화면을 갱신한다.
	Invalidate();
}
