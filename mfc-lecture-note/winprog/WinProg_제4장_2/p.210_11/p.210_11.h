
// p.210_11.h : p.210_11 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_11App:
// �� Ŭ������ ������ ���ؼ��� p.210_11.cpp�� �����Ͻʽÿ�.
//

class Cp210_11App : public CWinApp
{
public:
	Cp210_11App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_11App theApp;
