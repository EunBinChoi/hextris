
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p.231.h"
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
	ON_WM_SETCURSOR()
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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(10,10,400,100);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point); // Ŀ�� ��ġ(��ũ�� ��ǥ)�� ��´�
		ScreenToClient(&point); // ��ũ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ�Ѵ�
		CRgn rgn;
		rgn.CreateEllipticRgn(10,10,400,100);
		if(rgn.PtInRegion(point)) // Ŀ���� ���� ���ʿ� �ִ��� Ȯ���Ѵ�
			// ����� ���� Ŀ���� �����Ѵ�
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else // ǥ�� Ŀ�� �� �ϳ��� �����Ѵ�
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}

	
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}
