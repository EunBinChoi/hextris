
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


	dc.SetMapMode( MM_LOMETRIC ); // 매핑 모드 변경	//<= [b02]
	CSize size = dc.GetWindowExt();
	CRect rectRuler( CPoint(0, 0), size );
	rectRuler.bottom = -100;

	// 굵은 선
	CPen penThick( PS_SOLID, 5, RGB(0, 0, 0) );
	dc.SelectObject( &penThick );
	dc.Rectangle( rectRuler ); // 사각형 출력

	dc.TextOut( 5, -40, _T("0") );	// 0 글자 출력

	// 1cm 눈금과 글자 출력
	for ( int i=100; i<rectRuler.right; i+=100 )
	{
		dc.MoveTo( i, 0 );
		dc.LineTo( i, -60 );

		if ( i % 100 == 0 )
		{
			CString str;
			str.Format( _T("%d"), i/100 );

			CRect rect( i-100, -40, i-5, -100 );
			dc.DrawText( str, str.GetLength(),
				rect, DT_RIGHT|DT_TOP|DT_SINGLELINE );
		}
	}

	// 보통 선
	dc.SelectStockObject( BLACK_PEN );

	// 5mm와 1mm 눈금 출력
	for ( int j=10; j<rectRuler.right; j+=10 )
	{
		if ( j % 50 == 0 )	// 5mm
		{
			dc.MoveTo( j, 0 );
			dc.LineTo( j, -40 );
		}
		else if ( j % 10 == 0 )	// 10mm
		{
			dc.MoveTo( j, 0 );
			dc.LineTo( j, -20 );
		}
	}
}
