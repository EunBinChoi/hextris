
// ChildView.cpp : CChildView Ŭ������ ����
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

	// ��������� �׸���.
	POINT points[] = { {rect.right/2, 0}, {rect.right, rect.bottom/2},
		{rect.right/2, rect.bottom}, {0, rect.bottom/2}, {rect.right/2, 0} };
	dc.Polyline(points, 5);


	dc.SetMapMode( MM_LOMETRIC ); // ���� ��� ����	//<= [b02]
	CSize size = dc.GetWindowExt();
	CRect rectRuler( CPoint(0, 0), size );
	rectRuler.bottom = -100;

	// ���� ��
	CPen penThick( PS_SOLID, 5, RGB(0, 0, 0) );
	dc.SelectObject( &penThick );
	dc.Rectangle( rectRuler ); // �簢�� ���

	dc.TextOut( 5, -40, _T("0") );	// 0 ���� ���

	// 1cm ���ݰ� ���� ���
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

	// ���� ��
	dc.SelectStockObject( BLACK_PEN );

	// 5mm�� 1mm ���� ���
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
