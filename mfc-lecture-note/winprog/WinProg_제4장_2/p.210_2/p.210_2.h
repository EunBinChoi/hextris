
// p.210_2.h : p.210_2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_2App:
// �� Ŭ������ ������ ���ؼ��� p.210_2.cpp�� �����Ͻʽÿ�.
//

class Cp210_2App : public CWinApp
{
public:
	Cp210_2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_2App theApp;
