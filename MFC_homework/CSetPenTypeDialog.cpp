// CSetPenTypeDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFC_homework.h"
#include "CSetPenTypeDialog.h"
#include "afxdialogex.h"


// CSetPenTypeDialog 对话框

IMPLEMENT_DYNAMIC(CSetPenTypeDialog, CDialogEx)

CSetPenTypeDialog::CSetPenTypeDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CSetPenTypeDialog::~CSetPenTypeDialog()
{
}

void CSetPenTypeDialog::DoDataExchange(CDataExchange* pDX)// 从输入控件中获得对应线型选择
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit_2);
	CString str;
	m_Edit_2.GetWindowTextW(str);// 从输入控件中获得对应线型选择

	m_PenType = _ttoi(str);// 传入m_PenType
}
// 从输入控件中获得对应线型选择

BEGIN_MESSAGE_MAP(CSetPenTypeDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSetPenTypeDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CSetPenTypeDialog 消息处理程序


void CSetPenTypeDialog::OnBnClickedOk()// 定义OK选项含义，适应于非模态对话框
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	UpdateData(true); // 开启数据更新 
	CFrameWnd* pFrame = GetParentFrame(); // 获得父窗口框架 
	CView* pView = pFrame->GetActiveView(); // 获得当前视图 
	pView->PostMessage(WM_DIALOG2, IDOK); // 向视图发送消息，参数为IDOK 
	CDialog::OnOK();
}
