
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.189.h"
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
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), (HBRUSH)GetStockObject(GRAY_BRUSH), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	dc.SetBkMode(OPAQUE); // 이 줄을 주석 처리해도 결과는 같다
	dc.TextOut(100,50,CString("QPAQUE 모드(1)"));
	
	dc.SetBkMode(TRANSPARENT); // 이 줄을 주석 처리해도 결과는 같다
	dc.TextOut(100,100,CString("TRANSPARENT 모드"));

	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(0,255,0));
	dc.TextOut(100,150,CString("QPAQUE 모드(2)"));
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

