// 电路计算工具Dlg.h : header file
//

#if !defined(AFX_DLG_H__92DC33E5_7524_4CF6_B793_0711BA586E04__INCLUDED_)
#define AFX_DLG_H__92DC33E5_7524_4CF6_B793_0711BA586E04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
// 



#ifndef PI
#define PI 3.1415926535
#endif



class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLrCalc();
	afx_msg void OnLrResetValue();
	afx_msg void OnLrReset();
	afx_msg void OnRcCalc();
	afx_msg void OnRcResetValue();
	afx_msg void OnRcReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
	// RC滤波
	afx_msg void OnChangeEditDitongLvboDianrong();
	afx_msg void OnEnChangeDitongLvboDianzu();
	afx_msg void OnEnChangeDitongLvboPinlv();

	double m_EditDiTongLvBoDianRong;
	double m_EditDiTongLvBoDianZu;
	double m_EditDiTongLvBoPinLv;
	CComboBox m_ComboDiTongLvBoDianRong;
	CComboBox m_ComboDiTongLvBoDianZu;
	CComboBox m_ComboDiTongLvBoPinLv;

	//////////////////////////////////////////////////////////////////////////

	// LR滤波
	afx_msg void OnChangeEditLRLvboDianGan();
	afx_msg void OnEnChangeLRLvboDianzu();
	afx_msg void OnEnChangeLRLvboPinlv();

	double m_EditLRLvBoDianGan;
	double m_EditLRLvBoDianZu;
	double m_EditLRLvBoPinLv;
	CComboBox m_ComboLRLvBoDianGan;
	CComboBox m_ComboLRLvBoDianZu;
	CComboBox m_ComboLRLvBoPinLv;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__92DC33E5_7524_4CF6_B793_0711BA586E04__INCLUDED_)
