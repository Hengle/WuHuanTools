
// AutomaticOper.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAutomaticOperApp:
// �йش����ʵ�֣������ AutomaticOper.cpp
//

class CAutomaticOperApp : public CWinAppEx
{
public:
	CAutomaticOperApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAutomaticOperApp theApp;