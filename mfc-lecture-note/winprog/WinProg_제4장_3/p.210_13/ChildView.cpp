
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.210_13.h"
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
		::LoadCursor(NULL, IDC_ARROW), NULL, NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// Ŭ���̾�Ʈ ������ �ʷϻ� �ؽ� �귯�÷� ä���
	CRect rect;
	GetClientRect(&rect); // Ŭ���̾�Ʈ �κ��� ������ ����
	CBrush brush(HS_CROSS, RGB(0,255,0));
	
	dc.SelectObject(&brush);
	dc.Rectangle(&rect);


	// ��輱�� �������̰� ���ΰ� ����ִ� Ÿ���� �׸���.
	dc.SelectStockObject(BLACK_PEN);
	dc.SelectStockObject(NULL_BRUSH);
	
	dc.Ellipse(100,50,200,200);

	dc.SelectStockObject(ANSI_FIXED_FONT);
	dc.TextOutW(100,120,_T("Ÿ��(Ellipse)"));

	// ��輱�� ���� ���ΰ� ���� ȸ������ ä���� �ٰ����� �׸���.
	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	POINT points[] = {{250,50},{450,150},{300,200},{250,150}};
	dc.Polygon(points,4);
	dc.SelectStockObject(ANSI_VAR_FONT);
	dc.TextOutW(260,120,_T("�簢��(Tetragon)"));

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

