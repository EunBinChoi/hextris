
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.231.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
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
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(10,10,400,100);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point); // 커서 위치(스크린 좌표)를 얻는다
		ScreenToClient(&point); // 스크린 좌표를 클라이언트 좌표로 변환한다
		CRgn rgn;
		rgn.CreateEllipticRgn(10,10,400,100);
		if(rgn.PtInRegion(point)) // 커서가 리전 안쪽에 있는지 확인한다
			// 사용자 정의 커서로 변경한다
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else // 표준 커서 중 하나로 변경한다
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}

	
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}
