
// (��ȭ)p.151_1.h : (��ȭ)p.151_1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C��ȭp151_1App:
// �� Ŭ������ ������ ���ؼ��� (��ȭ)p.151_1.cpp�� �����Ͻʽÿ�.
//

class C��ȭp151_1App : public CWinApp
{
public:
	C��ȭp151_1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ȭp151_1App theApp;
