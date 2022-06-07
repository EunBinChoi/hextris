#include <afxwin.h>
#include <locale.h>

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
	_tsetlocale(LC_ALL, _T("")); // TRACE() ��ũ�ο��� �����ڵ� �ѱ� ��¿� �ʿ�!
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}

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
#if 0
	AfxMessageBox(_T("���콺 Ŭ��!"));
#endif
#if 1
	TRACE(_T("���� ���α׷� ��ü �ּ�: %p = %p\n"), AfxGetApp(), &theApp);
	//TRACE(_T("���� ������ ��ü �ּ�: %p = %p\n"), AfxGetMainWnd(), theApp.m_pMainWnd);
	TRACE(_T("���� ������ ��ü �ּ�: %p = %p\n"), AfxGetMainWnd(), this);
	TRACE(_T("���� ���α׷� �̸�: %s\n"), AfxGetAppName());
#endif
#if 0
	// �ν��Ͻ� �ڵ鰪�� ���� ������ �ε�� ���� �޸� �ּҴ�.
	TRACE("�ν��Ͻ� �ڵ�: %p\n", AfxGetInstanceHandle());
#endif
}

// �޽������� �����Ѵ�.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
