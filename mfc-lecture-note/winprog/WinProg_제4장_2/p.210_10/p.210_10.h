
// p.210_10.h : p.210_10 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_10App:
// �� Ŭ������ ������ ���ؼ��� p.210_10.cpp�� �����Ͻʽÿ�.
//

class Cp210_10App : public CWinApp
{
public:
	Cp210_10App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_10App theApp;
