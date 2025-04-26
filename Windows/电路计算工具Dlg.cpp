// 电路计算工具Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "电路计算工具.h"
#include "电路计算工具Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_EditDiTongLvBoDianRong = 0.0;
	m_EditDiTongLvBoDianZu = 0.0;
	m_EditDiTongLvBoPinLv = 0.0;
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text(pDX, EDIT_DITONG_LVBO_DIANRONG, m_EditDiTongLvBoDianRong);
	DDX_Text(pDX, EDIT_DITONG_LVBO_DIANZU, m_EditDiTongLvBoDianZu);
	DDX_Text(pDX, EDIT_DITONG_LVBO_PINLV, m_EditDiTongLvBoPinLv);
	DDX_Control(pDX, COMBO_DITONG_LVBO_DIANRONG, m_ComboDiTongLvBoDianRong);
	DDX_Control(pDX, COMBO_DITONG_LVBO_DIANZU, m_ComboDiTongLvBoDianZu);
	DDX_Control(pDX, COMBO_DITONG_LVBO_PINLV, m_ComboDiTongLvBoPinLv);
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
#ifdef VS2010
	ON_EN_CHANGE(EDIT_DITONG_LVBO_DIANRONG, &CMyDlg::OnChangeEditDitongLvboDianrong)
	ON_EN_CHANGE(EDIT_DITONG_LVBO_DIANZU, &CMyDlg::OnEnChangeDitongLvboDianzu)
	ON_EN_CHANGE(EDIT_DITONG_LVBO_PINLV, &CMyDlg::OnEnChangeDitongLvboPinlv)
	ON_BN_CLICKED(BTN_RESET_VALUE, &CMyDlg::OnBnClickedResetValue)
	ON_BN_CLICKED(BTN_RESET2, &CMyDlg::OnBnClickedReset2)
	ON_BN_CLICKED(BTN_RESET_VALUE2, &CMyDlg::OnBnClickedResetValue2)
#else
	ON_EN_CHANGE(EDIT_DITONG_LVBO_DIANRONG, CMyDlg::OnChangeEditDitongLvboDianrong)
	ON_EN_CHANGE(EDIT_DITONG_LVBO_DIANZU, CMyDlg::OnEnChangeDitongLvboDianzu)
	ON_EN_CHANGE(EDIT_DITONG_LVBO_PINLV, CMyDlg::OnEnChangeDitongLvboPinlv)
	ON_BN_CLICKED(BTN_RESET_VALUE, CMyDlg::OnBnClickedResetValue)
	ON_BN_CLICKED(BTN_RESET2, CMyDlg::OnBnClickedReset2)
	ON_BN_CLICKED(BTN_RESET_VALUE2, CMyDlg::OnBnClickedResetValue2)
#endif
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	// 低通滤波电阻单位
	m_ComboDiTongLvBoDianZu.AddString("皮欧 - pΩ (Picoohm)");
	m_ComboDiTongLvBoDianZu.AddString("纳欧 - nΩ (Nanoohm)");
	m_ComboDiTongLvBoDianZu.AddString("微欧 - μΩ(Microohm)");
	m_ComboDiTongLvBoDianZu.AddString("毫欧 - mΩ (Milliohm)");
	m_ComboDiTongLvBoDianZu.AddString("欧姆 - Ω  (Ohm)");
	m_ComboDiTongLvBoDianZu.AddString("千欧 - KΩ (Kiloohm)");
	m_ComboDiTongLvBoDianZu.AddString("兆欧 - MΩ (Megaohm)");
	m_ComboDiTongLvBoDianZu.AddString("吉欧 - GΩ (Gigaohm)");
	m_ComboDiTongLvBoDianZu.AddString("太欧 - TΩ (Teraohm)");
	m_ComboDiTongLvBoDianZu.SetCurSel(4);

	
	// 低通滤波电容单位
	m_ComboDiTongLvBoDianRong.AddString("飞法 - fF  (femtofarad)");
	m_ComboDiTongLvBoDianRong.AddString("皮法 - pF  (picofarad)");
	m_ComboDiTongLvBoDianRong.AddString("纳法 - nF  (nanofarad)");
	m_ComboDiTongLvBoDianRong.AddString("微法 - μF (microfarad)");
	m_ComboDiTongLvBoDianRong.AddString("毫法 - mF  (millifarad)");
	m_ComboDiTongLvBoDianRong.AddString("法拉 - F   (Farad)");
	m_ComboDiTongLvBoDianRong.SetCurSel(2);

	// 低通截止频率单位
	m_ComboDiTongLvBoPinLv.AddString("赫兹 - Hz  (hertz)");
	m_ComboDiTongLvBoPinLv.AddString("千赫 - kHz (kilohertz)");
	m_ComboDiTongLvBoPinLv.AddString("兆赫 - MHz (megahertz)");
	m_ComboDiTongLvBoPinLv.AddString("吉赫 - GHz (gigahertz)");
	m_ComboDiTongLvBoPinLv.AddString("太赫 - THz (terahertz)");
	m_ComboDiTongLvBoPinLv.AddString("拍赫 - PHz (petahertz)");
	m_ComboDiTongLvBoPinLv.AddString("艾赫 - EHz (exahertz)");
	m_ComboDiTongLvBoPinLv.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CMyDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

// 	switch(pMsg->message)
// 	{
// 		case wm_ed
// 	}

	return CDialog::PreTranslateMessage(pMsg);
}


// 低通滤波电容
void CMyDlg::OnChangeEditDitongLvboDianrong()
{
	CString strText;
	GetDlgItemText(EDIT_DITONG_LVBO_DIANRONG, strText);

	// 如果编辑框为空，自动填充0
	if (strText.IsEmpty())
	{
		SetDlgItemText(EDIT_DITONG_LVBO_DIANRONG, _T("0"));
		// 可选：将光标移动到末尾
		CEdit* pEdit = (CEdit*)GetDlgItem(EDIT_DITONG_LVBO_DIANRONG);
		pEdit->SetSel(1, 1);
	}
}


void CMyDlg::OnEnChangeDitongLvboDianzu()
{
	CString strText;
	GetDlgItemText(EDIT_DITONG_LVBO_DIANZU, strText);

	// 如果编辑框为空，自动填充0
	if (strText.IsEmpty())
	{
		SetDlgItemText(EDIT_DITONG_LVBO_DIANZU, _T("0"));
		// 可选：将光标移动到末尾
		CEdit* pEdit = (CEdit*)GetDlgItem(EDIT_DITONG_LVBO_DIANZU);
		pEdit->SetSel(1, 1);
	}
}

void CMyDlg::OnEnChangeDitongLvboPinlv()
{
	CString strText;
	GetDlgItemText(EDIT_DITONG_LVBO_PINLV, strText);

	// 如果编辑框为空，自动填充0
	if(strText.IsEmpty())
	{
		SetDlgItemText(EDIT_DITONG_LVBO_PINLV, _T("0"));
		// 可选：将光标移动到末尾
		CEdit* pEdit = (CEdit*)GetDlgItem(EDIT_DITONG_LVBO_PINLV);
		pEdit->SetSel(1, 1);
	}
}

void CMyDlg::OnBnClickedResetValue()
{
	m_EditDiTongLvBoDianZu = 0;
	m_EditDiTongLvBoDianRong = 0;
	m_EditDiTongLvBoPinLv = 0;
	UpdateData(FALSE);
}


void CMyDlg::OnBnClickedReset2()
{
	m_ComboDiTongLvBoDianZu.SetCurSel(4);
	m_ComboDiTongLvBoDianRong.SetCurSel(2);
	m_ComboDiTongLvBoPinLv.SetCurSel(0);
}


void CMyDlg::OnBnClickedResetValue2()
{
	UpdateData();

	// 电阻
	double dDianZu = 0;
	// 电容
	double dDianRong = 0;
	// 截止频率
	double dZuZhiPinLv = 0;

	// 判断电容为空则填写默认100nf
	if((m_EditDiTongLvBoDianRong == 0 && m_EditDiTongLvBoDianZu == 0 && m_EditDiTongLvBoPinLv == 0)
	|| (m_EditDiTongLvBoDianRong == 0 && m_EditDiTongLvBoDianZu == 0 && m_EditDiTongLvBoPinLv != 0))
	{
		m_EditDiTongLvBoDianRong = 100.0f;
		m_ComboDiTongLvBoDianRong.SetCurSel(2);
	}

	// 电阻
	switch(m_ComboDiTongLvBoDianZu.GetCurSel())
	{
		// 微欧 - μΩ (Microohm)
	case 0: {dDianZu = m_EditDiTongLvBoDianZu / 1000 / 1000 / 1000 / 1000;} break;
		// 微欧 - μΩ (Microohm)
	case 1: {dDianZu = m_EditDiTongLvBoDianZu / 1000 / 1000 / 1000;} break;
		// 微欧 - μΩ (Microohm)
	case 2: {dDianZu = m_EditDiTongLvBoDianZu / 1000 / 1000;} break;
		// 毫欧 - mΩ  (Milliohm)
	case 3: {dDianZu = m_EditDiTongLvBoDianZu / 1000;} break;
		// 欧姆 - Ω   (Ohm)
	case 4: {/*no do...*/dDianZu = m_EditDiTongLvBoDianZu;} break;
		// 千欧 - KΩ  (Kiloohm)
	case 5: {dDianZu = m_EditDiTongLvBoDianZu * 1000;} break;
		// 兆欧 - MΩ  (Megaohm)
	case 6: {dDianZu = m_EditDiTongLvBoDianZu * 1000 * 1000;} break;
		// 吉欧 - GΩ  (Gigaohm)
	case 7: {dDianZu = m_EditDiTongLvBoDianZu * 1000 * 1000 * 1000;} break;
		// 太欧 - TΩ  (Teraohm)
	case 8: {dDianZu = m_EditDiTongLvBoDianZu * 1000 * 1000 * 1000 * 1000;} break;
	}

	// 电容
	switch(m_ComboDiTongLvBoDianRong.GetCurSel())
	{
		// 飞法 - fF  (femtofarad)
	case 0: {dDianRong = m_EditDiTongLvBoDianRong / 1000 / 1000 / 1000 / 1000 / 1000;} break;
		// 皮法 - pF  (picofarad)
	case 1: {dDianRong = m_EditDiTongLvBoDianRong / 1000 / 1000 / 1000 / 1000;} break;
		// 纳法 - nF  (nanofarad)
	case 2: {dDianRong = m_EditDiTongLvBoDianRong / 1000 / 1000 / 1000;} break;
		// 微法 - μF (microfarad)
	case 3: {dDianRong = m_EditDiTongLvBoDianRong / 1000 / 1000;} break;
		// 毫法 - mF  (millifarad)
	case 4: {dDianRong = m_EditDiTongLvBoDianRong / 1000;} break;
		// 法拉 - F   (Farad)
	case 5: {/*no do...*/dDianRong = m_EditDiTongLvBoDianRong;} break;
	}

	// 截止频率
	switch(m_ComboDiTongLvBoPinLv.GetCurSel())
	{
		// 赫兹 - Hz  (hertz)
	case 0: {dZuZhiPinLv = m_EditDiTongLvBoPinLv;} break;
		// 千赫 - kHz (kilohertz)
	case 1: {dZuZhiPinLv = m_EditDiTongLvBoPinLv * 1000;} break;
		// 兆赫 - MHz (megahertz)
	case 2: {dZuZhiPinLv = m_EditDiTongLvBoPinLv * 1000 * 1000;} break;
		// 吉赫 - GHz (gigahertz)
	case 3: {dZuZhiPinLv = m_EditDiTongLvBoPinLv * 1000 * 1000 * 1000;} break;
		// 太赫 - THz (terahertz)
	case 4: {dZuZhiPinLv = m_EditDiTongLvBoPinLv * 1000 * 1000 * 1000 * 1000;} break;
		// 拍赫 - PHz (petahertz)
	case 5: {dZuZhiPinLv = m_EditDiTongLvBoPinLv * 1000 * 1000 * 1000 * 1000 * 1000;} break;
		// 艾赫 - EHz (exahertz)
	case 6: {dZuZhiPinLv = m_EditDiTongLvBoPinLv * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;} break;
	}


	// 判断截止频率为空则表示通过电阻和电容计算截止频率
	if(m_EditDiTongLvBoPinLv == 0 || (m_EditDiTongLvBoDianRong != 0 && m_EditDiTongLvBoDianZu != 0 && m_EditDiTongLvBoPinLv != 0))
	{
		m_EditDiTongLvBoPinLv = 1 / (2 * PI * dDianZu * dDianRong);

		bool bCmp = false;
		double dValue = 1;
		dZuZhiPinLv = m_EditDiTongLvBoPinLv;

		if(dZuZhiPinLv > dValue)
		{
			bCmp = 1;
		}
		else
		{
			bCmp = 0;
		}

		for(int i = 0; i < 6; i++)
		{
			if(bCmp)
			{
				if(dZuZhiPinLv < dValue)
				{
					m_ComboDiTongLvBoPinLv.SetCurSel(i);
					break;
				}
				dValue *= 1000;
				dZuZhiPinLv /= 1000;
			}
			else
			{
				m_ComboDiTongLvBoPinLv.SetCurSel(i);
				break;
			}
		}

		m_EditDiTongLvBoPinLv = dZuZhiPinLv;
	}

	// 判断电容为空则表示通过截止频率和电阻计算电容
	if(m_EditDiTongLvBoDianRong == 0)
	{
		if(m_EditDiTongLvBoDianZu != 0 && m_EditDiTongLvBoPinLv != 0)
		{
			m_EditDiTongLvBoDianRong = 1 / (2 * PI * dDianZu * m_EditDiTongLvBoPinLv);

			bool bCmp = false;
			double dValue = 1;
			dDianRong = m_EditDiTongLvBoDianRong;

			if(dDianRong > dValue)
			{
				bCmp = 1;
			}
			else
			{
				bCmp = 0;
			}

			for(int i = 0; i < 6; i++)
			{
				if(bCmp)
				{
					if(dDianRong < dValue)
					{
						m_ComboDiTongLvBoDianRong.SetCurSel(i);
						break;
					}
					dValue *= 1000;
					dDianRong /= 1000;
				}
				else
				{
					if(dDianRong > dValue)
					{
						m_ComboDiTongLvBoDianRong.SetCurSel(i);
						break;
					}
					dValue = 1;
					dDianRong *= 1000;
				}
			}

			m_EditDiTongLvBoDianRong = dDianRong;
		}
		else
		{
			// 没填写数值
			MessageBox("数值没有填写完全, 请检查...", NULL, MB_ICONINFORMATION);
		}
	}

	// 判断电阻为空则表示通过截止频率和电容计算电阻
	if(m_EditDiTongLvBoDianZu == 0)
	{
		if(m_EditDiTongLvBoDianRong != 0 && m_EditDiTongLvBoPinLv != 0)
		{
			m_EditDiTongLvBoDianZu = 1 / (2 * PI * dDianRong * dZuZhiPinLv);

			bool bCmp = false;
			double dValue = 1;
			dDianZu = m_EditDiTongLvBoDianZu;

			if(dDianZu > dValue)
			{
				bCmp = 1;
				dValue = 1000;
			}
			else
			{
				bCmp = 0;
			}

			for(int i = 0; i < 6; i++)
			{
				if(bCmp)
				{
					// 截止频率是 106.10329539763 kHz  电容是 100nF, 计算电阻是 14.999999999999 Ω
					// 截止频率是 100 kHz  电容是 1nF, 计算电阻是 15.9 KΩ
					if(dDianZu < dValue)
					{
						m_ComboDiTongLvBoDianZu.SetCurSel(4+i);
						break;
					}
//					dValue *= 1000;
					dDianZu /= 1000;
				}
				else
				{
					if(dDianZu > dValue)
					{
						m_ComboDiTongLvBoDianZu.SetCurSel(4-i);
						break;
					}
					dValue = 1;
					dDianZu *= 1000;
				}
			}

			m_EditDiTongLvBoDianZu = dDianZu;
		}
		else
		{
			// 没填写数值
			MessageBox("数值没有填写完全, 请检查...", NULL, MB_ICONINFORMATION);
		}
	}


	UpdateData(FALSE);
}
