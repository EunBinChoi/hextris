
// p.151_4.h : p.151_4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp151_4App:
// �� Ŭ������ ������ ���ؼ��� p.151_4.cpp�� �����Ͻʽÿ�.
//

class Cp151_4App : public CWinApp
{
public:
	Cp151_4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp151_4App theApp;
