
// p.210_15.h : p.210_15 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_15App:
// �� Ŭ������ ������ ���ؼ��� p.210_15.cpp�� �����Ͻʽÿ�.
//

class Cp210_15App : public CWinApp
{
public:
	Cp210_15App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_15App theApp;
