#pragma once


// CHighScore ��ȭ �����Դϴ�.

class CHighScore : public CDialogEx
{
	DECLARE_DYNAMIC(CHighScore)

public:
	CHighScore(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHighScore();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HIGH_SCORE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
