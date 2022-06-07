#pragma once


// CHighScore 대화 상자입니다.

class CHighScore : public CDialogEx
{
	DECLARE_DYNAMIC(CHighScore)

public:
	CHighScore(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHighScore();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HIGH_SCORE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
