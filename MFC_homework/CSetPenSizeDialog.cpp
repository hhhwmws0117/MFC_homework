// CSetPenSizeDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFC_homework.h"
#include "CSetPenSizeDialog.h"
#include "afxdialogex.h"


// CSetPenSizeDialog 对话框

IMPLEMENT_DYNAMIC(CSetPenSizeDialog, CDialogEx)

CSetPenSizeDialog::CSetPenSizeDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CSetPenSizeDialog::~CSetPenSizeDialog()
{
}

void CSetPenSizeDialog::DoDataExchange(CDataExchange* pDX)// 从输入控件中获得对应线宽选择
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit_1);


	CString str;
	m_Edit_1.GetWindowTextW(str);// 从输入控件中获得对应线宽选择

	m_PenSize = _ttoi(str);// 传入m_PenSize
}
// 从输入控件中获得对应线宽选择

BEGIN_MESSAGE_MAP(CSetPenSizeDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CSetPenSizeDialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CSetPenSizeDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CSetPenSizeDialog 消息处理程序


void CSetPenSizeDialog::OnEnChangeEdit1()
{

	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSetPenSizeDialog::OnBnClickedOk()// 定义OK选项含义，适应于非模态对话框
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK(); // 构造 
	UpdateData(true); // 开启数据更新 
	CFrameWnd* pFrame = GetParentFrame(); // 获得父窗口框架 
	CView* pView = pFrame->GetActiveView(); // 获得当前视图 
	pView->PostMessage(WM_DIALOG1, IDOK); // 向视图发送消息，参数为IDOK 
	CDialog::OnOK();
}
