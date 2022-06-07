
// MainFrm.cpp : CMainFrame Ŭ������ ����
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

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
	: m_bMouseIn( FALSE )	//<= [a07]
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// �������� Ŭ���̾�Ʈ ������ �����ϴ� �並 ����ϴ�.
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("�� â�� ������ ���߽��ϴ�.\n");
		return -1;
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	cs.cx = 200;
	cs.cy = 100;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame ����

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


// CMainFrame �޽��� ó����

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// �� â���� ��Ŀ���� �̵��մϴ�.
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// �信�� ù° ũ���� �ش� ��ɿ� ��Ÿ������ �մϴ�.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// �׷��� ������ �⺻ ó���մϴ�.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


void CMainFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	if ( m_bMouseIn == FALSE )
	{
		// ���콺 Ŀ�� ������ ��û�Ѵ�.
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE|TME_NONCLIENT;
		tme.hwndTrack = this->m_hWnd;
		tme.dwHoverTime = HOVER_DEFAULT;
		::_TrackMouseEvent( &tme );

		// ���� ������ ũ�⸦ 300*300���� �����Ѵ�.
		CWnd *pMainWnd = AfxGetMainWnd();
		CRect rect;
		pMainWnd->GetWindowRect( rect );
		rect.right = rect.left + 300;
		rect.bottom = rect.top + 300;
		pMainWnd->MoveWindow( rect );

		// ���콺 Ŀ���� ��Ŭ���̾�Ʈ ������ ������ ǥ���Ѵ�.
		m_bMouseIn = TRUE;	
	}
	CFrameWnd::OnNcMouseMove(nHitTest, point);
}


void CMainFrame::OnNcMouseLeave()
{
	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.

	// ���콺 Ŀ���� ��Ŭ���̾�Ʈ ������ ����� ǥ���Ѵ�.
	m_bMouseIn = FALSE;

	// ���� ������ ũ�⸦ 200*200���� �����Ѵ�.
	CWnd *pMainWnd = AfxGetMainWnd();
	CRect rect;
	pMainWnd->GetWindowRect( rect );
	rect.right = rect.left + 200;
	rect.bottom = rect.top + 200;
	pMainWnd->MoveWindow( rect );

	CFrameWnd::OnNcMouseLeave();
}
