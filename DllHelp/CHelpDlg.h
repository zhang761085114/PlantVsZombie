#pragma once
#include "afxdialogex.h"


// CHelpDlg 对话框

class CHelpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHelpDlg)

public:
	CHelpDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHelpDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_EdtNum;
	afx_msg void OnBnClickedSun();
	afx_msg void OnBnClickedPlanet();
	afx_msg void OnBnClickedChange();
};
