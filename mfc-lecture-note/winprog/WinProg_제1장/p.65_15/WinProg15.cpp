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
};

// ���� ���α׷� ��ü�� �����Ѵ�.
CHelloApp theApp;

// ���� ���α׷� Ŭ������ �����Ѵ�.
BOOL CHelloApp::InitInstance()
{
	if (m_lpCmdLine != NULL || m_lpCmdLine != _T(" "))
	{
		LPCTSTR strSave = AfxGetApp()->m_pszAppName;

		// ���ο� ����
		CString strTemp;
		strTemp.Format(_T("����� ����"));
		AfxGetApp()->m_pszAppName = strTemp;


		int iRtn = AfxMessageBox(_T(
			"����� ���ڸ� ó���� �� �����ϴ�.\n��� �����Ͻðڽ��ϱ�?"),
			MB_YESNO);



		// ������ �������� ����
		AfxGetApp()->m_pszAppName = strSave; 

		
			if (iRtn == IDNO)
				return FALSE;
	}


	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
	m_pMainWnd->ShowWindow(SW_RESTORE);
	//m_pMainWnd = new CMainFrame;
	//m_pMainWnd->ShowWindow(2);
	return TRUE;
}

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
	MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"));
}

// �޽��� ���� �����Ѵ�.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
