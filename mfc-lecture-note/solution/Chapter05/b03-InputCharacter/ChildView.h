
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once

#include <afxtempl.h>

// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:
	CPoint UpdateCaret( int iIndex=-1, BOOL bCalc=FALSE );
	CString FindRowString( CString& str, DWORD dwRow, int *iIndexFound=NULL );

protected:
	CPoint GetCaretPoint( int iIndex=-1 );	// String[] => Point
	int GetCharIndex( CPoint point );		// Point => String[]
	int GetVertCharIndex( CPoint point, BOOL bUpward );

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

protected:
	CString		m_str;
	CPoint		m_ptCaret;

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

