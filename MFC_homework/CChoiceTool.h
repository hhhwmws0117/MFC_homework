#pragma once

//#include"MFC_homeworkView.h"
//#include "MFC_homeworkView.h"


// CChoiceTool 对话框
#define WM_DIALOG3 WM_USER+3// 新定义消息
class CChoiceTool : public CDialogEx
{
	DECLARE_DYNAMIC(CChoiceTool)

public:
	CChoiceTool(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChoiceTool();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持


	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit_3;
	int tool_choice = 0;// 初始化变量
	//afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();// 确认OK按钮功能
};
