
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once

#include "Block.h"
#include "Board.h"
// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();
	int board_h;  //게임 보드의 높이
	int board_w;  //게임 보드의 넓이
	Board gameBoard;  //게임 보드 객체
	Block* currentBlock; //현재 블럭 동적 생성 및 저장을 위한 포인터 변수
	Block* nextBlock;	//다음 블럭 동정 생성 및 저장을 위한 포인터 변수
	const static COLORREF colors[]; //블럭 색 저장 표
	int score; //점수
	bool isGameOver; //Game 종료 여부
	bool pauseGame;	//Game 중지 여부
	int currentLevel; //현재 게임 레벨
	int levels[4];  //레벨에 따른 블럭 스피드 저장
// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
// 구현입니다.
public:
	virtual ~CChildView();
	bool moveDown();  //블럭을 아래로 움직이는 함수
	void createNextBlock();  //다음 블럭 생성 함수
	void gameOver();  //게임 오버 처리 함수
	void addScore(int n);  //점수 추가
	int scoreLines(int n);  //한번에 제거되는 라인의 가중치를 계산해주는 함수
	void newGame(); //새로운 게임을 시작할 때 처리해주는 함수
	void setBoardSize(int w, int h); //게임 보드 크기를 세팅
	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent); //타이머 함수
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags); //키보드 처리

	afx_msg void OnGameNew(); //메뉴에서 Game - New 클릭했을 때 발생되는 이벤트 처리 함수
	//사이즈 변경 처리 함수
	afx_msg void OnSize7x13();
	afx_msg void OnSize7x15();
	afx_msg void OnSize9x15();
	afx_msg void OnSize9x17();
	afx_msg void OnSize11x17();
	afx_msg void OnSize11x19();

	//레벨 변경 처리 함수
	afx_msg void OnLevelEasy();
	afx_msg void OnLevelMedium();
	afx_msg void OnLevelHard();
	afx_msg void OnLevelExtremelyhard();
//	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnUpdateGameHighscore(CCmdUI *pCmdUI);
};

