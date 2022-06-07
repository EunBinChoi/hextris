
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "DisableCloseButton.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCMOUSEMOVE()
END_MESSAGE_MAP()

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
	: m_bDirty( FALSE )	//<= [a12]
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


void CMainFrame::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// ���� ��ư�� ���� ��쿡�� Ư���� ó���� �Ѵ�.
	if(nHitTest == HTCLOSE)
		MessageBox(_T("���⸦ ������ ������ �� �����ϴ�."), _T("�׽�Ʈ"));
	// �� ���� ��쿡�� �ü���� �ڵ����� ó���Ѵ�.
	else
		CFrameWnd::OnNcLButtonDown(nHitTest, point);
}


void CMainFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	if ( nHitTest == HTCLOSE )
	{
		CWindowDC dc( this );

		CDC dcMem;
		dcMem.CreateCompatibleDC( &dc );

		CBitmap bitmap;
		bitmap.LoadBitmap( IDB_BITMAP1 );
		BITMAP bm;
		bitmap.GetBitmap( &bm );

		dcMem.SelectObject( &bitmap );

		CRect rect;
		GetWindowRect( rect );

		int cxFrame = ::GetSystemMetrics( SM_CXFRAME );
		int cyFrame = ::GetSystemMetrics( SM_CYFRAME );
		int cxSize = ::GetSystemMetrics( SM_CXSIZE );
		int cySize = ::GetSystemMetrics( SM_CYSIZE );
		int cxBorder = ::GetSystemMetrics( SM_CXBORDER );
		int cyBorder = ::GetSystemMetrics( SM_CYBORDER );

		dc.StretchBlt( rect.Width() - cxSize - cxFrame,
			cyFrame, cxSize, cySize,
			&dcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY );

		m_bDirty = TRUE;
	}
	else if ( m_bDirty == TRUE )
	{
		m_bDirty = FALSE;
		RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INVALIDATE);
	}

	CFrameWnd::OnNcMouseMove(nHitTest, point);
}
