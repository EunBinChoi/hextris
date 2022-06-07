
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.210_7.h"
#include "ChildView.h"
#include<math.h>
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
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	//CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//클라이언트 영역의 좌표를 얻는다
	CRect rect;
	GetClientRect(&rect);
	int pi = 3.141592;
	dc.MoveTo(0,rect.bottom/2);
	dc.LineTo(rect.right,rect.bottom/2);
	dc.MoveTo(rect.right/2,0);
	dc.LineTo(rect.right/2,rect.bottom);
	
	POINT pt;
	for (int x = -rect.right/2; x < rect.right/2; x++)
	{ 
		pt.x=x+rect.right/2;
		pt.y=rect.bottom/2-(int)(sin((x*pi/360.0))*rect.bottom/2); // y좌표계가 반대라서 뒤집음 
		// 200도를 한 이유는 문제와 비슷하게 출력하기 위한 것임
		// 이 각도를 바꿔주면 화면에 출력되는 그래프의 주기가 다르게 나옴  
		points.Add(pt); 
	} 
	//배열에 모아놓았던 좌표를 가지고 그림을 그린다
	dc.Polyline(points.GetData(), points.GetSize()); 
	//Invalidate(FALSE);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

