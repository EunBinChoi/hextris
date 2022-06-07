
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once

#include "Block.h"
#include "Board.h"
// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();
	int board_h;  //���� ������ ����
	int board_w;  //���� ������ ����
	Board gameBoard;  //���� ���� ��ü
	Block* currentBlock; //���� �� ���� ���� �� ������ ���� ������ ����
	Block* nextBlock;	//���� �� ���� ���� �� ������ ���� ������ ����
	const static COLORREF colors[]; //�� �� ���� ǥ
	int score; //����
	bool isGameOver; //Game ���� ����
	bool pauseGame;	//Game ���� ����
	int currentLevel; //���� ���� ����
	int levels[4];  //������ ���� �� ���ǵ� ����
// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
// �����Դϴ�.
public:
	virtual ~CChildView();
	bool moveDown();  //���� �Ʒ��� �����̴� �Լ�
	void createNextBlock();  //���� �� ���� �Լ�
	void gameOver();  //���� ���� ó�� �Լ�
	void addScore(int n);  //���� �߰�
	int scoreLines(int n);  //�ѹ��� ���ŵǴ� ������ ����ġ�� ������ִ� �Լ�
	void newGame(); //���ο� ������ ������ �� ó�����ִ� �Լ�
	void setBoardSize(int w, int h); //���� ���� ũ�⸦ ����
	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent); //Ÿ�̸� �Լ�
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags); //Ű���� ó��

	afx_msg void OnGameNew(); //�޴����� Game - New Ŭ������ �� �߻��Ǵ� �̺�Ʈ ó�� �Լ�
	//������ ���� ó�� �Լ�
	afx_msg void OnSize7x13();
	afx_msg void OnSize7x15();
	afx_msg void OnSize9x15();
	afx_msg void OnSize9x17();
	afx_msg void OnSize11x17();
	afx_msg void OnSize11x19();

	//���� ���� ó�� �Լ�
	afx_msg void OnLevelEasy();
	afx_msg void OnLevelMedium();
	afx_msg void OnLevelHard();
	afx_msg void OnLevelExtremelyhard();
//	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnUpdateGameHighscore(CCmdUI *pCmdUI);
};

