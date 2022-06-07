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
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
//	m_pMainWnd->ShowWindow(SW_RESTORE);
	//m_pMainWnd = new CMainFrame;
	//m_pMainWnd->ShowWindow(2);
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
	Create(NULL, _T("HelloMFC"),WS_POPUPWINDOW | WS_CAPTION,CRect(0, 0, 500,500));
	
	/*
	lpszClassName
 Windows 클래스의 이름을 지정 하는 null로 끝나는 문자열을 가리킵니다.  클래스 이름으로 등록 된 이름 수를 AfxRegisterWndClass 전역 함수 또는 RegisterClass Windows 함수.  경우 NULL, 미리 정의 된 기본값을 사용 하 여 CFrameWnd 특성.  
lpszWindowName
창의 이름을 나타내는 null로 끝나는 문자열을 가리킵니다.  텍스트로 제목 표시줄을 사용 합니다.  
dwStyle
지정 된 창  스타일 특성.  포함 된 FWS_ADDTOTITLE 제목 표시줄 창에 표시 되는 문서의 이름을 자동으로 표시 하려면 원하는 경우 스타일.  
rect
창의 위치와 크기를 지정합니다.  rectDefault 값을 Windows 크기 및 위치를 새 창에 지정할 수 있습니다.  
pParentWnd
이 프레임 창의 부모 창으로 지정합니다.  이 매개 변수를 해야 NULL 최상위 프레임 창에 대 한.  
lpszMenuName
창에 사용할 메뉴 리소스의 이름을 식별 합니다.  사용 MAKEINTRESOURCE 메뉴 경우 정수 대신 문자열 ID입니다.  이 매개 변수 수 NULL.  
dwExStyle
확장 창 지정  스타일 특성. 
pContext
포인터를 지정 된 CCreateContext 구조.  이 매개 변수 수 NULL. 
*/
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

// 메시지 맵을 선언한다.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
