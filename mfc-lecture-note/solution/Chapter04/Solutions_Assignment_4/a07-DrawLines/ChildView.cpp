
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "DrawLines.h"
#include "ChildView.h"
#include <math.h>

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

#define PI 3.141592653589793

void CChildView::OnPaint() 
{
	CPaintDC dc(this);
	
	// Ŭ���̾�Ʈ ������ ��ǥ�� ��´�.
	CRect rect;
	GetClientRect(&rect);

	// ���򼱰� �������� �׸���.
	dc.MoveTo(0, rect.bottom/2);
	dc.LineTo(rect.right, rect.bottom/2);
	dc.MoveTo(rect.right/2, 0);
	dc.LineTo(rect.right/2, rect.bottom);

#if 0
	// ��������� �׸���.
	POINT points[] = { {rect.right/2, 0}, {rect.right, rect.bottom/2},
		{rect.right/2, rect.bottom}, {0, rect.bottom/2}, {rect.right/2, 0} };
	dc.Polyline(points, 5);
#endif

	const int nDeltaX = rect.Width()/2;	//<= [a07]
	const int nDeltaY = rect.Height()/2;

	CArray<POINT, POINT&>	array;	//<= [a07]
	for ( int i=0; i<rect.right; i++ )
	{
		POINT pt;
		pt.x = i;
		pt.y =  nDeltaY - (LONG)( ::sin( (double)(i-nDeltaX)/(8*PI) ) * (double)nDeltaY );
		TRACE( _T("%d\n"), pt.y );
		array.Add( pt );
	}

	dc.Polyline( array.GetData(), array.GetSize() );	//<= [a07]
}
