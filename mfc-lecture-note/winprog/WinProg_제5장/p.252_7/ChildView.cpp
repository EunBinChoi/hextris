
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.252_7.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
//	m_bMouseIn = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_MOUSEMOVE()
//	ON_WM_NCMOUSELEAVE()
//ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



//void CChildView::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	if(m_bMouseIn == FALSE){
//		TRACKMOUSEEVENT tme;
//		tme.cbSize = sizeof(tme);
//		tme.dwFlags = TME_LEAVE;
//		tme.hwndTrack = this->m_hWnd;
//		tme.dwHoverTime = HOVER_DEFAULT;
//		::TrackMouseEvent(&tme);
//			
//		
//		CWnd *pMainWnd = AfxGetMainWnd();
//		CRect rect;
//		pMainWnd -> GetWindowRect(&rect);
//		rect.right = rect.left + 300;
//		rect.bottom = rect.top + 150;
//		pMainWnd->MoveWindow(&rect);
//		m_bMouseIn = TRUE;
//	
//	}
//	CWnd::OnMouseMove(nFlags, point);
//}
//
//
////void CChildView::OnNcMouseLeave()
////{
////	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
////	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.
////	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
////
////	CWnd::OnNcMouseLeave();
////}
//
//
//void CChildView::OnMouseLeave()
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	m_bMouseIn = FALSE;
//
//	CWnd *pMainWnd = AfxGetMainWnd();
//	CRect rect;
//	pMainWnd->GetWindowRect(&rect);
//	rect.right = rect.left + 300;
//	rect.bottom = rect.top + 100;
//	pMainWnd->MoveWindow(&rect);
//	CWnd::OnMouseLeave();
//}
