#include <afxwin.h>

// ���� ���α׷� Ŭ������ �����Ѵ�.
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// ���� ������ Ŭ������ �����Ѵ�.
class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

// ���� ���α׷� ��ü�� �����Ѵ�.
CHelloApp theApp;

// ���� ���α׷� Ŭ������ �����Ѵ�.
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	
	return TRUE;
}


/*
SW_HIDE -> �����츦 ����ϴ�.

SW_MINIMIZE -> �����츦 �ּ�ȭ�ϰ� Ȱ��ȭ��Ű�� �ʽ��ϴ�.

SW_RESTORE -> �����츦 Ȱ��ȭ ��ŵ�ϴ�. // Ȯ�� ���¿��� ���� ũ��� �����°�

SW_SHOW -> �����츦 Ȱ��ȭ�Ͽ� �����ݴϴ�.

SW_SHOWNORMAL -> SW_SHOW�� ���������� Ȱ��ȭ�Ͽ� ����������  // ó�� �����Ѵ�� ������

ó������ �����츦 �����ִ� ���̶�� �� �ɼ��� ���Դϴ�.
*/

// ���� ������ Ŭ������ �����Ѵ�.
CMainFrame::CMainFrame()
{
	Create(NULL, _T("HelloMFC"));
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	TCHAR *msg = _T("Hello, MFC");
	dc.TextOut(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	//MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"));
}


BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)

{

    if (pMsg->message==WM_LBUTTONDBLCLK)
    {

        MessageBox(_T("���콺�� ���� Ŭ���߽��ϴ�."), _T("���콺 �޽���"));
		return true;
	}
	else{
		return CFrameWnd::PreTranslateMessage(pMsg);
	}
}


// �޽��� ���� �����Ѵ�.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


