
// IgnoreAssert.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#define STR_REG_AUTORUN _T("autorun")
#define STR_REG_AUTOSTART _T("autostart")
#define STR_REG_TIMEAUTOSTART _T("timeautostart")
#define STR_REG_AUTOSTOP _T("autostop")
#define STR_REG_AUTOSHUTDOWN _T("autoshutdown")
#define STR_REG_TIMESHUTDOWN _T("timeshutdown")

// CIgnoreAssertApp:
// �йش����ʵ�֣������ IgnoreAssert.cpp
//

class CIgnoreAssertApp : public CWinAppEx
{
public:
	CIgnoreAssertApp();

// ��д
public:
	virtual BOOL InitInstance();
	void fixFont();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIgnoreAssertApp theApp;