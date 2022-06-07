
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once

#include <afxtempl.h>

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	CPoint UpdateCaret( int iIndex=-1, BOOL bCalc=FALSE );
	CString FindRowString( CString& str, DWORD dwRow, int *iIndexFound=NULL );

protected:
	CPoint GetCaretPoint( int iIndex=-1 );	// String[] => Point
	int GetCharIndex( CPoint point );		// Point => String[]
	int GetVertCharIndex( CPoint point, BOOL bUpward );

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

protected:
	CString		m_str;
	CPoint		m_ptCaret;

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

