
// Tetris.h : Tetris ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.
#include "HowToPaly.h"
#include "HighScore.h"


// CTetrisApp:
// �� Ŭ������ ������ ���ؼ��� Tetris.cpp�� �����Ͻʽÿ�.
//

class CTetrisApp : public CWinApp
{
public:
	CTetrisApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnHelpHowtoplay();
	afx_msg void OnGameHighscore();
//	afx_msg void OnUpdateGameHighscore(CCmdUI *pCmdUI);
};

extern CTetrisApp theApp;
