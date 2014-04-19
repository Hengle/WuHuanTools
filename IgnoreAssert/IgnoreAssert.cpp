
// IgnoreAssert.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "IgnoreAssert.h"
#include "IgnoreAssertDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIgnoreAssertApp

BEGIN_MESSAGE_MAP(CIgnoreAssertApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CIgnoreAssertApp ����

CIgnoreAssertApp::CIgnoreAssertApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CIgnoreAssertApp ����

CIgnoreAssertApp theApp;


// CIgnoreAssertApp ��ʼ��

BOOL CIgnoreAssertApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();
	fixFont();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("JsNdTools"));
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));

	CIgnoreAssertDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
static const CString strOfficeFontName = _T("����");
static const CString strOffice2007FontName = _T("΢���ź�");

static int CALLBACK FontFamalyProcFonts(const LOGFONT FAR* lplf, const TEXTMETRIC FAR* /*lptm*/, ULONG /*ulFontType*/, LPARAM lParam)
{
	ENSURE(lplf != NULL);
	ENSURE(lParam != NULL);

	CString strFont = lplf->lfFaceName;
	return strFont.CollateNoCase((LPCTSTR) lParam) == 0 ? 0 : 1;
}

void CIgnoreAssertApp::fixFont()
{
	CWindowDC dc(NULL);
	LOGFONT lf;
	CString strNewName = strOfficeFontName;
	BYTE bNewQuality = 0;
	if (::EnumFontFamilies(dc.GetSafeHdc(), NULL, FontFamalyProcFonts, (LPARAM)(LPCTSTR) strOffice2007FontName) == 0)
	{
		strNewName = strOffice2007FontName;
		bNewQuality = 5 /*CLEARTYPE_QUALITY*/;
	}

	afxGlobalData.fontRegular.GetLogFont(&lf);
	lstrcpy(lf.lfFaceName, strNewName);
	lf.lfQuality = bNewQuality;
	afxGlobalData.fontRegular.DeleteObject();
	afxGlobalData.fontRegular.CreateFontIndirect(&lf);

	afxGlobalData.fontSmall.GetLogFont(&lf);
	lstrcpy(lf.lfFaceName, strNewName);
	lf.lfQuality = bNewQuality;
	afxGlobalData.fontSmall.DeleteObject();
	afxGlobalData.fontSmall.CreateFontIndirect(&lf);

	afxGlobalData.fontTooltip.GetLogFont(&lf);
	lstrcpy(lf.lfFaceName, strNewName);
	lf.lfQuality = bNewQuality;
	afxGlobalData.fontTooltip.DeleteObject();
	afxGlobalData.fontTooltip.CreateFontIndirect(&lf);

	afxGlobalData.fontUnderline.GetLogFont(&lf);
	lstrcpy(lf.lfFaceName, strNewName);
	lf.lfQuality = bNewQuality;
	afxGlobalData.fontUnderline.DeleteObject();
	afxGlobalData.fontUnderline.CreateFontIndirect(&lf);

	afxGlobalData.fontBold.GetLogFont(&lf);
	lstrcpy(lf.lfFaceName, strNewName);
	lf.lfQuality = bNewQuality;
	afxGlobalData.fontBold.DeleteObject();
	afxGlobalData.fontBold.CreateFontIndirect(&lf);

}
