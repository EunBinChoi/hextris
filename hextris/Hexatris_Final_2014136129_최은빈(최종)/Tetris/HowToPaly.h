#pragma once


// CHowToPaly 대화 상자입니다.

class CHowToPaly : public CDialogEx
{
	DECLARE_DYNAMIC(CHowToPaly)

public:
	CHowToPaly(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHowToPaly();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HOWTOPLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
};
