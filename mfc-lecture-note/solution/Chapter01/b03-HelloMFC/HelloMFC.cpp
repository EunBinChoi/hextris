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

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

protected:
	//virtual BOOL PreTranslateMessage(MSG* pMsg);	//<= [b03]
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

// ���� ������ Ŭ������ �����Ѵ�.
CMainFrame::CMainFrame()
{
	Create(NULL, _T("HelloMFC "));
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	TCHAR *msg = _T("Hello, MFC");
	dc.TextOut(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"));
}



// �޽������� �����Ѵ�.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
//	ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

//BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)	//<= [b03]
//{
//	if (pMsg->message == WM_LBUTTONDBLCLK)
//	{
//		MessageBox( _T("���콺�� ����Ŭ���߽��ϴ�."), _T("���콺 �޽���") );
//		return TRUE;
//	}
//	return CFrameWnd::PreTranslateMessage(pMsg);
//}


void CMainFrame::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	MessageBox(_T("�����콺 Ŭ��!"), _T("���콺 �޽���"));
	CFrameWnd::OnLButtonDblClk(nFlags, point);
}
