#pragma once


// CHowToPaly ��ȭ �����Դϴ�.

class CHowToPaly : public CDialogEx
{
	DECLARE_DYNAMIC(CHowToPaly)

public:
	CHowToPaly(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHowToPaly();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HOWTOPLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
};
