#include <afxwin.h>

// 응용 프로그램 클래스를 선언한다.
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// 메인 윈도우 클래스를 선언한다.
class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

// 응용 프로그램 객체를 선언한다.
CHelloApp theApp;

// 응용 프로그램 클래스를 정의한다.
BOOL CHelloApp::InitInstance()
{
	if (m_lpCmdLine != NULL && lstrlen(m_lpCmdLine) > 0)	//<= [a15]
	{
		int iRtn = ::AfxMessageBox(
			_T("명령행 인자를 처리할 수 없습니다.\n계속 진행하시겠습니까?"),
			MB_YESNO);
		if (iRtn == IDNO)
			return FALSE;
	}
	
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}

// 메인 윈도우 클래스를 정의한다.
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
	MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"));
}

// 메시지맵을 선언한다.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
