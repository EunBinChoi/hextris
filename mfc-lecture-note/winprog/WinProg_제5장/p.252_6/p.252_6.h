
// p.252_6.h : p.252_6 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp252_6App:
// �� Ŭ������ ������ ���ؼ��� p.252_6.cpp�� �����Ͻʽÿ�.
//

class Cp252_6App : public CWinApp
{
public:
	Cp252_6App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp252_6App theApp;
