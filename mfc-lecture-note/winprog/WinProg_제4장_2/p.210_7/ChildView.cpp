
// ChildView.cpp : CChildView Ŭ������ ����
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
	//CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//Ŭ���̾�Ʈ ������ ��ǥ�� ��´�
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
		pt.y=rect.bottom/2-(int)(sin((x*pi/360.0))*rect.bottom/2); // y��ǥ�谡 �ݴ�� ������ 
		// 200���� �� ������ ������ ����ϰ� ����ϱ� ���� ����
		// �� ������ �ٲ��ָ� ȭ�鿡 ��µǴ� �׷����� �ֱⰡ �ٸ��� ����  
		points.Add(pt); 
	} 
	//�迭�� ��Ƴ��Ҵ� ��ǥ�� ������ �׸��� �׸���
	dc.Polyline(points.GetData(), points.GetSize()); 
	//Invalidate(FALSE);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

