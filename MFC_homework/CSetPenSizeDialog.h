#pragma once


// CSetPenSizeDialog 对话框
#define WM_DIALOG1 WM_USER+1// 新定义消息
class CSetPenSizeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSetPenSizeDialog)

public:
	CSetPenSizeDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetPenSizeDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit_1;
	int m_PenSize = 1;// 初始化变量
	afx_msg void OnEnChangeEdit1();
protected:
	//afx_msg LRESULT OnDialog1(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedOk();// 确认OK按钮功能
};
