
// p.210_13.h : p.210_13 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// Cp210_13App:
// 이 클래스의 구현에 대해서는 p.210_13.cpp을 참조하십시오.
//

class Cp210_13App : public CWinApp
{
public:
	Cp210_13App();


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_13App theApp;
