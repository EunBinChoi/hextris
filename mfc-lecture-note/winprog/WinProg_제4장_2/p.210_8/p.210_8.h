
// p.210_8.h : p.210_8 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_8App:
// �� Ŭ������ ������ ���ؼ��� p.210_8.cpp�� �����Ͻʽÿ�.
//

class Cp210_8App : public CWinApp
{
public:
	Cp210_8App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_8App theApp;
