
// P.151_3.h : P.151_3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CP151_3App:
// �� Ŭ������ ������ ���ؼ��� P.151_3.cpp�� �����Ͻʽÿ�.
//

class CP151_3App : public CWinApp
{
public:
	CP151_3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CP151_3App theApp;
