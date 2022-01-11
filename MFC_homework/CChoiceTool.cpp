// CChoiceTool.cpp: 实现文件
// 实现绘图工具的非模态对话框选择

#include "pch.h"
#include "MFC_homework.h"
#include "CChoiceTool.h"
#include "afxdialogex.h"
#include"MFC_homeworkView.h"

// CChoiceTool 对话框

IMPLEMENT_DYNAMIC(CChoiceTool, CDialogEx)

CChoiceTool::CChoiceTool(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CChoiceTool::~CChoiceTool()
{
}

void CChoiceTool::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit_3);

	CString str;
	m_Edit_3.GetWindowTextW(str);// 从输入控件中获得对应工具选择

	tool_choice = _ttoi(str);// 传入tool_choice
}
// 从输入控件中获得对应工具选择

BEGIN_MESSAGE_MAP(CChoiceTool, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChoiceTool::OnBnClickedOk)
END_MESSAGE_MAP()


// CChoiceTool 消息处理程序


void CChoiceTool::OnBnClickedOk()// 定义OK选项含义，适应于非模态对话框
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	UpdateData(true); // 开启数据更新 
	CFrameWnd* pFrame = GetParentFrame(); // 获得父窗口框架 
	CView* pView = pFrame->GetActiveView(); // 获得当前视图 
	pView->PostMessage(WM_DIALOG3, IDOK); // 向视图发送消息，参数为IDOK 
	CDialog::OnOK();
}
