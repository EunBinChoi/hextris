
// p.151_11.h : p.151_11 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp151_11App:
// �� Ŭ������ ������ ���ؼ��� p.151_11.cpp�� �����Ͻʽÿ�.
//

class Cp151_11App : public CWinApp
{
public:
	Cp151_11App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp151_11App theApp;
