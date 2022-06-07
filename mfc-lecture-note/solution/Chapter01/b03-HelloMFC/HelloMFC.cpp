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

protected:
	//virtual BOOL PreTranslateMessage(MSG* pMsg);	//<= [b03]
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

// 응용 프로그램 객체를 선언한다.
CHelloApp theApp;

// 응용 프로그램 클래스를 정의한다.
BOOL CHelloApp::InitInstance()
{
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
//	ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

//BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)	//<= [b03]
//{
//	if (pMsg->message == WM_LBUTTONDBLCLK)
//	{
//		MessageBox( _T("마우스를 더블클릭했습니다."), _T("마우스 메시지") );
//		return TRUE;
//	}
//	return CFrameWnd::PreTranslateMessage(pMsg);
//}


void CMainFrame::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	MessageBox(_T("더블마우스 클릭!"), _T("마우스 메시지"));
	CFrameWnd::OnLButtonDblClk(nFlags, point);
}
