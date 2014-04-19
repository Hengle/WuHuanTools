
// IgnoreAssertDlg.h : ͷ�ļ�
//

#pragma once


// CIgnoreAssertDlg �Ի���
class CIgnoreAssertDlg : public CDialogEx
{
// ����
public:
	CIgnoreAssertDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CIgnoreAssertDlg();

// �Ի�������
	enum { IDD = IDD_IGNOREASSERT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	NOTIFYICONDATA	m_nid;			// struct for Shell_NotifyIcon args
	bool m_bStarting;
	bool m_bAutoRun;
	bool m_bAutoStart;
	int m_nTimeAutoStart;
	bool m_bAutoStop;
	bool m_bAutoShutDown;
	CTime m_timeTimeAutoShutDown;
	bool m_bStartingByAutoStart;	// �Զ���ʼ���������
	bool m_bTimeOutShutDown;		// ���ڹػ�������

	void OnTrayContextMenu();
	void FindAllAssertDlg();
	void LoadRegValue();
	void SetAutoRun(bool bRun);
	void CheckAutoStart();
	void CheckAutoShutDown();
	BOOL MySystemShutdown(LPTSTR lpMsg);
	BOOL PreventSystemShutdown();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnTrayNotify(WPARAM wp, LPARAM lp);
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuClose();
	afx_msg void OnUpdateMenuClose(CCmdUI *pCmdUI);
	afx_msg void OnMenuSet();
	afx_msg void OnMenuAbout();
	afx_msg void OnMenuExit();
	afx_msg void OnClose();
	afx_msg void OnUpdateMenuOpen(CCmdUI *pCmdUI);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
};
