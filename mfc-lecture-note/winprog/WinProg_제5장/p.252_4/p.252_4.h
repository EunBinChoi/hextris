
// p.252_4.h : p.252_4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp252_4App:
// �� Ŭ������ ������ ���ؼ��� p.252_4.cpp�� �����Ͻʽÿ�.
//

class Cp252_4App : public CWinApp
{
public:
	Cp252_4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp252_4App theApp;
