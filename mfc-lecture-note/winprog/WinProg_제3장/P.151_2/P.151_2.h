
// P.151_2.h : P.151_2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CP151_2App:
// �� Ŭ������ ������ ���ؼ��� P.151_2.cpp�� �����Ͻʽÿ�.
//

class CP151_2App : public CWinApp
{
public:
	CP151_2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CP151_2App theApp;
