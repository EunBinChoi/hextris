
// p.151_15.h : p.151_15 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp151_15App:
// �� Ŭ������ ������ ���ؼ��� p.151_15.cpp�� �����Ͻʽÿ�.
//

class Cp151_15App : public CWinApp
{
public:
	Cp151_15App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp151_15App theApp;
