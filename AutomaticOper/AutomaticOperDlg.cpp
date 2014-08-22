
// AutomaticOperDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AutomaticOper.h"
#include "AutomaticOperDlg.h"

#include "CellCtrls\CellEdit.h"
#include "CellCtrls\CellComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CAutomaticOperDlg �Ի���




CAutomaticOperDlg::CAutomaticOperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutomaticOperDlg::IDD, pParent)
	, m_bKeyUp(FALSE)
	, m_bIsAuto(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_ACCELERATOR1));
}

void CAutomaticOperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CONFIG, m_ConfigListCtrl);
	DDX_Control(pDX, IDC_BUTTON_AUTO, m_BtnAuto);
}

BEGIN_MESSAGE_MAP(CAutomaticOperDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_MOVE()
	ON_WM_SIZING()
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE, &CAutomaticOperDlg::OnBnClickedButtonCapture)
	ON_BN_CLICKED(IDC_BUTTON_AUTO, &CAutomaticOperDlg::OnBnClickedButtonAuto)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CAutomaticOperDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CAutomaticOperDlg ��Ϣ�������

BOOL CAutomaticOperDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	InitListInfo();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CAutomaticOperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAutomaticOperDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAutomaticOperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAutomaticOperDlg::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);

	m_ConfigListCtrl.OnParentMove(x, y);
}

void CAutomaticOperDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialog::OnSizing(fwSide, pRect);

	m_ConfigListCtrl.OnSizing(fwSide, pRect);
}

BOOL CAutomaticOperDlg::PreTranslateMessage(MSG* pMsg)
{
	if (m_hAccel) 
	{
		if (::TranslateAccelerator(m_hWnd, m_hAccel, pMsg)) 
		{
			return(TRUE);
		}
	}

	if(pMsg->message==WM_KEYDOWN) 
		m_bKeyUp = FALSE;
	if(pMsg->message==WM_KEYUP) 
		m_bKeyUp = TRUE;
	if((pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN))
	{
		if (m_bKeyUp)
		{
			m_bKeyUp = FALSE;
			return m_ConfigListCtrl.OnEnterEsc(pMsg->wParam);
		}
		else
			return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CAutomaticOperDlg::InitListInfo()
{
	m_ConfigListCtrl.InsertColumn(0, _T("���"));
	m_ConfigListCtrl.SetColumnWidth(0, 80);
	m_ConfigListCtrl.InsertColumn(1, _T("����"));
	m_ConfigListCtrl.SetColumnWidth(1, 100);
	m_ConfigListCtrl.InsertColumn(2, _T("ֹͣ"));
	m_ConfigListCtrl.SetColumnWidth(2, 100);
	m_ConfigListCtrl.InsertColumn(3, _T("��Ϣ������"));
	m_ConfigListCtrl.SetColumnWidth(3, 100);
}

void CAutomaticOperDlg::OnBnClickedButtonCapture()
{
	if (m_bIsAuto)
	{
		return;
	}

	CPoint ptPos;
	GetCursorPos(&ptPos);
	CWnd *pWnd = WindowFromPoint(ptPos);
	if (!pWnd)
	{
		return;
	}

	while (pWnd->GetParent() && pWnd->GetParent()->GetParent())
	{
		pWnd = pWnd->GetParent();
	}
	pWnd->ScreenToClient(&ptPos);
	PointOperInfo info(pWnd->GetSafeHwnd(), MAKELPARAM(ptPos.x, ptPos.y), pWnd->GetDC()->GetPixel(ptPos.x, ptPos.y));
	m_vecPointOperInfo.push_back(info);

	int nCurIndex = m_ConfigListCtrl.InsertItem(m_ConfigListCtrl.GetItemCount(), _T(""));
	CString strCurIndex;
	strCurIndex.Format(_T("%d"), nCurIndex);
	m_ConfigListCtrl.SetItem(nCurIndex, 0, strCurIndex);
	m_ConfigListCtrl.SetItem(nCurIndex, 1, new CCellComboBox, 
		_T("����\n����\n˫��"));
	m_ConfigListCtrl.SetItem(nCurIndex, 2, new CCellComboBox, 
		_T("\n������ʧ"));
	m_ConfigListCtrl.SetItem(nCurIndex, 3, new CCellEdit, 
		_T("0"));
}

UINT AutoThread(LPVOID pParam) 
{ 
	CAutomaticOperDlg *pThis = (CAutomaticOperDlg*)pParam;
	if (pThis)
	{
		pThis->StartAuto();
	}
	return  0 ; 
} 

void CAutomaticOperDlg::OnBnClickedButtonAuto()
{
	if (m_bIsAuto)
	{
		m_bIsAuto = FALSE;
		m_BtnAuto.SetWindowText(_T("�Զ�����"));
	} 
	else
	{
		if (m_vecPointOperInfo.size() == 0)
		{
			AfxMessageBox(_T("û���κβ���"));
			return;
		}

		for (int i = 0; i < m_ConfigListCtrl.GetItemCount() && i < m_vecPointOperInfo.size(); ++i)
		{
			CString strOperType = m_ConfigListCtrl.GetItemText(i, 1);
			if (strOperType == "˫��")
			{
				m_vecPointOperInfo[i].oper = Oper_DBClick;
			}
			CString strStopType = m_ConfigListCtrl.GetItemText(i, 2);
			if (strStopType != "")
			{
				m_vecPointOperInfo[i].stop = Stop_Color;
			}
			CString strWait = m_ConfigListCtrl.GetItemText(i, 3);
			m_vecPointOperInfo[i].wait = _ttoi(strWait);
		}

		m_bIsAuto = TRUE;
		m_BtnAuto.SetWindowText(_T("ֹͣ"));
		AfxBeginThread(AutoThread, this);
	}
}

void CAutomaticOperDlg::OnBnClickedButtonSave()
{
	if (m_bIsAuto)
	{
		return;
	}
	
	m_ConfigListCtrl.DeleteAllItems();
	m_vecPointOperInfo.clear();
}

void CAutomaticOperDlg::StartAuto()
{
	int nCurIndex = 0;
	while (m_bIsAuto)
	{
		CWnd *pWnd = CWnd::FromHandle(m_vecPointOperInfo[nCurIndex].hwnd);
		if (pWnd)
		{
			BOOL bContinue = FALSE;
			do 
			{
				bContinue = FALSE;
				if (m_vecPointOperInfo[nCurIndex].stop == Stop_Color)
				{
					COLORREF curColor = pWnd->GetDC()->GetPixel(LOWORD(m_vecPointOperInfo[nCurIndex].pos), HIWORD(m_vecPointOperInfo[nCurIndex].pos));
					if (curColor == m_vecPointOperInfo[nCurIndex].color)
					{
						bContinue = TRUE;
					}
					else
					{
						break;
					}
				}

				if (m_vecPointOperInfo[nCurIndex].oper == Oper_Click)
				{
					pWnd->SendMessage(WM_LBUTTONDOWN, MK_LBUTTON, m_vecPointOperInfo[nCurIndex].pos);
					pWnd->SendMessage(WM_LBUTTONUP, MK_LBUTTON, m_vecPointOperInfo[nCurIndex].pos);
				}
				else
				{
					pWnd->SendMessage(WM_LBUTTONDBLCLK, MK_LBUTTON, m_vecPointOperInfo[nCurIndex].pos);
				}

				if (bContinue)
				{
					Sleep(2000);
				}
			} while (bContinue);
		}
		Sleep(m_vecPointOperInfo[nCurIndex].wait * 1000);

		nCurIndex++;
		if (nCurIndex >= m_vecPointOperInfo.size())
		{
			nCurIndex = 0;
		}
	}
}
