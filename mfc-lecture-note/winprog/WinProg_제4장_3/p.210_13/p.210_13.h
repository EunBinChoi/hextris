
// p.210_13.h : p.210_13 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_13App:
// �� Ŭ������ ������ ���ؼ��� p.210_13.cpp�� �����Ͻʽÿ�.
//

class Cp210_13App : public CWinApp
{
public:
	Cp210_13App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_13App theApp;
