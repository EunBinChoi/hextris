
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "TrackMouse.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCMOUSELEAVE()
END_MESSAGE_MAP()

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
	: m_bMouseIn( FALSE )	//<= [a07]
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 프레임의 클라이언트 영역을 차지하는 뷰를 만듭니다.
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("뷰 창을 만들지 못했습니다.\n");
		return -1;
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	cs.cx = 200;
	cs.cy = 100;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 뷰 창으로 포커스를 이동합니다.
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 뷰에서 첫째 크랙이 해당 명령에 나타나도록 합니다.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 그렇지 않으면 기본 처리합니다.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


void CMainFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	if ( m_bMouseIn == FALSE )
	{
		// 마우스 커서 추적을 요청한다.
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE|TME_NONCLIENT;
		tme.hwndTrack = this->m_hWnd;
		tme.dwHoverTime = HOVER_DEFAULT;
		::_TrackMouseEvent( &tme );

		// 메인 윈도우 크기를 300*300으로 변경한다.
		CWnd *pMainWnd = AfxGetMainWnd();
		CRect rect;
		pMainWnd->GetWindowRect( rect );
		rect.right = rect.left + 300;
		rect.bottom = rect.top + 300;
		pMainWnd->MoveWindow( rect );

		// 마우스 커서가 비클라이언트 영역에 있음을 표시한다.
		m_bMouseIn = TRUE;	
	}
	CFrameWnd::OnNcMouseMove(nHitTest, point);
}


void CMainFrame::OnNcMouseLeave()
{
	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.

	// 마우스 커서가 비클라이언트 영역을 벗어남을 표시한다.
	m_bMouseIn = FALSE;

	// 메인 윈도우 크기를 200*200으로 변경한다.
	CWnd *pMainWnd = AfxGetMainWnd();
	CRect rect;
	pMainWnd->GetWindowRect( rect );
	rect.right = rect.left + 200;
	rect.bottom = rect.top + 200;
	pMainWnd->MoveWindow( rect );

	CFrameWnd::OnNcMouseLeave();
}
