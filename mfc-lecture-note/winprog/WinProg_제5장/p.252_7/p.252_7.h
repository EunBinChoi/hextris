
// p.252_7.h : p.252_7 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp252_7App:
// �� Ŭ������ ������ ���ؼ��� p.252_7.cpp�� �����Ͻʽÿ�.
//

class Cp252_7App : public CWinApp
{
public:
	Cp252_7App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp252_7App theApp;
