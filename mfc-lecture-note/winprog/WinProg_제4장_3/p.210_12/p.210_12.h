
// p.210_12.h : p.210_12 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp210_12App:
// �� Ŭ������ ������ ���ؼ��� p.210_12.cpp�� �����Ͻʽÿ�.
//

class Cp210_12App : public CWinApp
{
public:
	Cp210_12App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp210_12App theApp;
