
// p.210_7.h : p.210_7 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_7App:
// �� Ŭ������ ������ ���ؼ��� p.210_7.cpp�� �����Ͻʽÿ�.
//

class Cp210_7App : public CWinApp
{
public:
	Cp210_7App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_7App theApp;
