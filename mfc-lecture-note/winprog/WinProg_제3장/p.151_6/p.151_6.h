
// p.151_6.h : p.151_6 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp151_6App:
// �� Ŭ������ ������ ���ؼ��� p.151_6.cpp�� �����Ͻʽÿ�.
//

class Cp151_6App : public CWinApp
{
public:
	Cp151_6App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp151_6App theApp;
