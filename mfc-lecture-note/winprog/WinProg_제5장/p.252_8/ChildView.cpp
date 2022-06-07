
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.252_8.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_xPos = m_yPos = 60; // 임의의 값 초기화
	m_bFill = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if(m_bFill == TRUE) dc.SelectStockObject(BLACK_BRUSH);
	dc.Ellipse(m_xPos-20,m_yPos-20,m_xPos+20,m_yPos+20);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnSize(UINT nType, int cx, int cy)
{
	
	m_xMax  = cx;
	m_yMax  = cy;
	CWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nVirtKey = GetKeyState(VK_CONTROL);	//<= [a08]
	const BOOL bCtrlPressed = ( nVirtKey & 0x8000 );
	
	switch(nChar){
	case VK_LEFT:
		m_xPos-=(!bCtrlPressed ? 20 : 40);	//<= [a08]
		break;
	case VK_RIGHT:
		m_xPos+=(!bCtrlPressed ? 20 : 40);	//<= [a08]
		break;
	case VK_UP:
		m_yPos-=(!bCtrlPressed ? 20 : 40);	//<= [a08]
		break;
	case VK_DOWN:
		m_yPos+=(!bCtrlPressed ? 20 : 40);	//<= [a08]
		break;
	case VK_SPACE:
		m_bFill = !m_bFill;
	}
	/* 20 <= m_xPos <= m_xMax-20 */
	m_xPos = min(max(20, m_xPos), m_xMax-20);
	/* 20 <= m_yPos <= m_yMax-20 */
	m_yPos = min(max(20, m_yPos), m_yMax-20);
	Invalidate();
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
