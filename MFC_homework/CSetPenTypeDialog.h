#pragma once


// CSetPenTypeDialog 对话框
#define WM_DIALOG2 WM_USER+2// 新定义消息
class CSetPenTypeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSetPenTypeDialog)

public:
	CSetPenTypeDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetPenTypeDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit_2;
	int m_PenType = PS_SOLID;// 初始化变量
	afx_msg void OnBnClickedOk();// 确认OK按钮功能
};
