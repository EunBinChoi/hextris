
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.210_9.h"
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
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	//CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CRect rect;
	CFont font1;
	CFont font2;
	CFont font3;
	GetClientRect(&rect);

	dc.SetTextColor(RGB(255,0,0)); // 글자를 빨간색으로 설정
	dc.SetBkColor(RGB(255,255,0)); //배경을 노란색으로 설정
	font1.CreateFont(70,30,0,0,0,0,TRUE,0,0,0,0,0,0,_T("굴림"));
	//font1.CreatePointFont(400, );
	
	dc.SelectObject(&font1);
	dc.DrawText(CString("DrawText 함수를 연습합니다[1]"),&rect,0);
	
	font2.CreateFont(70,30,0,0,0,TRUE,0,0,0,0,0,0,0,_T("궁서"));
	//font2.CreatePointFont(400, _T("궁서"));
	dc.SelectObject(&font2);
	dc.DrawText(CString("DrawText 함수를 연습합니다[2]"),&rect,
		DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	
	dc.SetTextAlign(TA_CENTER);
	dc.SetTextColor(RGB(0,0,255));
	dc.SetBkColor(RGB(0,255,0));
	font3.CreateFont(70,30,0,0,FW_BOLD,0,0,0,0,0,0,0,0,_T("바탕"));
	//font3.CreatePointFont(400, _T("바탕"));
	dc.SelectObject(&font3);
	dc.TextOut(rect.right/2 , 3*rect.bottom/4,CString("TextOut 함수를 연습합니다"));
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

