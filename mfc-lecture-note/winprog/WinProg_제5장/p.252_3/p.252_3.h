
// p.252_3.h : p.252_3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp252_3App:
// �� Ŭ������ ������ ���ؼ��� p.252_3.cpp�� �����Ͻʽÿ�.
//

class Cp252_3App : public CWinApp
{
public:
	Cp252_3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp252_3App theApp;
