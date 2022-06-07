
// ChildView.cpp : CChildView 클래스의 구현
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



// CChildView 메시지 처리기

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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



//void CChildView::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
////	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
////	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
////	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
////
////	CWnd::OnNcMouseLeave();
////}
//
//
//void CChildView::OnMouseLeave()
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
