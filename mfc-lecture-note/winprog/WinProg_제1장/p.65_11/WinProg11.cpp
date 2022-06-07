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
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
//	m_pMainWnd->ShowWindow(SW_RESTORE);
	//m_pMainWnd = new CMainFrame;
	//m_pMainWnd->ShowWindow(2);
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
	Create(NULL, _T("HelloMFC"),WS_POPUPWINDOW | WS_CAPTION,CRect(0, 0, 500,500));
	
	/*
	lpszClassName
 Windows Ŭ������ �̸��� ���� �ϴ� null�� ������ ���ڿ��� ����ŵ�ϴ�.  Ŭ���� �̸����� ��� �� �̸� ���� AfxRegisterWndClass ���� �Լ� �Ǵ� RegisterClass Windows �Լ�.  ��� NULL, �̸� ���� �� �⺻���� ��� �� �� CFrameWnd Ư��.  
lpszWindowName
â�� �̸��� ��Ÿ���� null�� ������ ���ڿ��� ����ŵ�ϴ�.  �ؽ�Ʈ�� ���� ǥ������ ��� �մϴ�.  
dwStyle
���� �� â  ��Ÿ�� Ư��.  ���� �� FWS_ADDTOTITLE ���� ǥ���� â�� ǥ�� �Ǵ� ������ �̸��� �ڵ����� ǥ�� �Ϸ��� ���ϴ� ��� ��Ÿ��.  
rect
â�� ��ġ�� ũ�⸦ �����մϴ�.  rectDefault ���� Windows ũ�� �� ��ġ�� �� â�� ������ �� �ֽ��ϴ�.  
pParentWnd
�� ������ â�� �θ� â���� �����մϴ�.  �� �Ű� ������ �ؾ� NULL �ֻ��� ������ â�� �� ��.  
lpszMenuName
â�� ����� �޴� ���ҽ��� �̸��� �ĺ� �մϴ�.  ��� MAKEINTRESOURCE �޴� ��� ���� ��� ���ڿ� ID�Դϴ�.  �� �Ű� ���� �� NULL.  
dwExStyle
Ȯ�� â ����  ��Ÿ�� Ư��. 
pContext
�����͸� ���� �� CCreateContext ����.  �� �Ű� ���� �� NULL. 
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
	MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"));
}

// �޽��� ���� �����Ѵ�.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
