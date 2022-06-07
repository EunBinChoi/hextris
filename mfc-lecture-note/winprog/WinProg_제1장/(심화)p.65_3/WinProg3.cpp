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
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
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


/*
SW_HIDE -> 윈도우를 숨깁니다.

SW_MINIMIZE -> 윈도우를 최소화하고 활성화시키지 않습니다.

SW_RESTORE -> 윈도우를 활성화 시킵니다. // 확대 상태에서 원래 크기로 돌리는것

SW_SHOW -> 윈도우를 활성화하여 보여줍니다.

SW_SHOWNORMAL -> SW_SHOW와 마찮가지로 활성화하여 보여주지만  // 처음 설정한대로 보여줌

처음으로 윈도우를 보여주는 것이라면 이 옵션이 쓰입니다.
*/

// 메인 윈도우 클래스를 정의한다.
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
	//MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"));
}


BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)

{

    if (pMsg->message==WM_LBUTTONDBLCLK)
    {

        MessageBox(_T("마우스를 더블 클릭했습니다."), _T("마우스 메시지"));
		return true;
	}
	else{
		return CFrameWnd::PreTranslateMessage(pMsg);
	}
}


// 메시지 맵을 선언한다.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


