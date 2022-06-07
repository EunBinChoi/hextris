
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.210_14.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	Button = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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
	// 비트맵 리소스를 로드한 후 크기 정보를 얻는다
	CBitmap bitmap;
	CRect rect;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP info;
	bitmap.GetBitmap(&info);
	GetClientRect(&rect);

	// 메모리 DC를 만든후 비트맵을 선택해 넣는다
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// 비트맵을 화면에 출력한다
	dc.BitBlt(10,10,info.bmWidth, info.bmHeight,&dcmem, 0,0,SRCCOPY);
	dc.StretchBlt(10,100,info.bmWidth*4, info.bmHeight*2,&dcmem, 0,0,info.bmWidth, info.bmHeight, SRCCOPY);
	

	// 메모리 DC에 그림을 그린 후 다시 화면에 출력한다
	if(Button == FALSE)
		dc.BitBlt(350,10,info.bmWidth, info.bmHeight,&dcmem, 0,0,SRCCOPY);
	else
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcmem, 0,0,info.bmWidth, info.bmHeight, SRCCOPY);
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Button = TRUE;
	Invalidate();
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	Button = FALSE;
	Invalidate();
}
