
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.200.h"
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
		::LoadCursor(NULL, IDC_ARROW), NULL, NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	

	// 클라이언트 영역을 초록색 해치 브러시로 채운다
	CRect rect;
	GetClientRect(&rect);
	CBrush brush(HS_CROSS,RGB(0,255,0));
	dc.SelectObject(&brush);
	dc.Rectangle(&rect);


	// 경계선이 검은색이고 내부가 비어있는 타원을 그린다
	dc.SelectStockObject(BLACK_PEN);
	dc.SelectStockObject(NULL_BRUSH);
	dc.Ellipse(100,50,200,200);


	//경계선이 없고 내부가 발근 회색으로 채워진 다각형을 그린다

	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	POINT points[] = {{250,50},{450,150},{300,200},{250,150},{250,50}};
	dc.Polygon(points,4);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

