
// p.151_16.h : p.151_16 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp151_16App:
// �� Ŭ������ ������ ���ؼ��� p.151_16.cpp�� �����Ͻʽÿ�.
//

class Cp151_16App : public CWinApp
{
public:
	Cp151_16App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp151_16App theApp;
