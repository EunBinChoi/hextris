
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "DrawLines.h"
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
	CPaintDC dc(this);
#if 0	
	// 클라이언트 영역의 좌표를 얻는다.
	CRect rect;
	GetClientRect(&rect);

	// 수평선과 수직선을 그린다.
	dc.MoveTo(0, rect.bottom/2);
	dc.LineTo(rect.right, rect.bottom/2);
	dc.MoveTo(rect.right/2, 0);
	dc.LineTo(rect.right/2, rect.bottom);

	// 마름모꼴을 그린다.
	POINT points[] = { {rect.right/2, 0}, {rect.right, rect.bottom/2},
		{rect.right/2, rect.bottom}, {0, rect.bottom/2}, {rect.right/2, 0} };
	dc.Polyline(points, 5);
#endif

	POINT ptArray[][8] = {	//<= [b01]
		{ {10, 10}, {90, 10}, {140, 10}, {190, 10}, {240, 10}, {290, 10}, {340, 10}, {390, 10} },
		{ {10, 40}, {90, 40}, {140, 40}, {190, 40}, {240, 40}, {290, 40}, {340, 40}, {390, 40} },
		{ {10, 70}, {90, 70}, {140, 70}, {190, 70}, {240, 70}, {290, 70}, {340, 70}, {390, 70} },
		{ {10, 100}, {90, 100}, {140, 100}, {190, 100}, {240, 100}, {290, 100}, {340, 100}, {390, 100} },
	};
	CString strProp[] = {
		_T("확률"), _T("0.1"), _T("0.3"), _T("0.2"), _T("0.1"), _T("0.1"), _T("0.2")
	};
	CString strAccu[] = {
		_T("누적"), _T("0.1"), _T("0.4"), _T("0.6"), _T("0.7"), _T("0.8"), _T("1.0")
	};

	// 회색 배경, 굵은 선
	dc.SelectStockObject( LTGRAY_BRUSH );
	CPen penThick( PS_SOLID, 2, RGB(0, 0, 0) );
	dc.SelectObject( &penThick );
	dc.Rectangle( CRect(ptArray[0][0], ptArray[1][7]) );

	// 굵은 선
 	dc.SelectStockObject( WHITE_BRUSH );
	dc.Rectangle( CRect(ptArray[1][0], ptArray[3][7]) );

	// 보통 선
	dc.SelectStockObject( BLACK_PEN );
	// (가로 선)
	dc.MoveTo( ptArray[2][0] );
	dc.LineTo( ptArray[2][7] );
	// (세로 선)
	for ( int i=1; i<7; ++i )
	{
		dc.MoveTo( ptArray[0][i] );
		dc.LineTo( ptArray[3][i] );
	}

	// 보통 글자
	dc.SelectStockObject( SYSTEM_FONT );
	dc.SetBkMode( TRANSPARENT );
	for ( int j=0; j<7; ++j )
	{
		dc.DrawText( strProp[j], strProp[j].GetLength(),
			CRect(ptArray[1][j], ptArray[2][j+1]),
			DT_CENTER|DT_VCENTER|DT_SINGLELINE );
		dc.DrawText( strAccu[j], strAccu[j].GetLength(),
			CRect(ptArray[2][j], ptArray[3][j+1]),
			DT_CENTER|DT_VCENTER|DT_SINGLELINE );
	}

	// 굵은 글자
	LOGFONT lf;
	CFont *pFontCurrent = dc.GetCurrentFont();
	pFontCurrent->GetLogFont( &lf );
	lf.lfWeight = FW_BOLD;
	CFont fontBold;
	fontBold.CreateFontIndirect( &lf );

	dc.SelectObject(&fontBold);
	for ( int k=1; k<7; ++k )
	{
		CString str;
		str.Format( _T("%d"), k );

		dc.DrawText( str, str.GetLength(),
			CRect(ptArray[0][k], ptArray[1][k+1]),
			DT_CENTER|DT_VCENTER|DT_SINGLELINE );
	}
}
