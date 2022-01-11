// MFC画图软件——面对对象程序设计大作业
// 作者：米唯实 
// 学号：2181311668
// 班级：自动化83
// 
// MFC_homeworkView.cpp: CMFChomeworkView 类的实现

// 引用文件
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_homework.h"
#endif

#include "MFC_homeworkDoc.h"
#include "MFC_homeworkView.h"
#include"resource.h"
#include "CSetPenSizeDialog.h"
#include "CSetPenTypeDialog.h"
#include "CChoiceTool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>
#include <vector>


// HBITMAP hbitmap_1, hbitmap_2;
// 两个图层全局变量，以全白色背景初始化，地址应用相对地址
HBITMAP hbitmap_1 = (HBITMAP)::LoadImage(
	NULL,
	L".\\res\\empty.bmp",
	IMAGE_BITMAP,
	0, 0,
	LR_LOADFROMFILE);
HBITMAP hbitmap_2 = (HBITMAP)::LoadImage(
	NULL,
	L".\\res\\empty.bmp",
	IMAGE_BITMAP,
	0, 0,
	LR_LOADFROMFILE);

CSetPenSizeDialog* pPenSizeDialog;// 线宽设置对话框变量
CSetPenTypeDialog* pPenTypeDialog;// 线宽设置对话框变量
CChoiceTool* pChoiceTool;// 工具设置对话框变量

//#include "vector.h"
using namespace std;

// CMFChomeworkView

IMPLEMENT_DYNCREATE(CMFChomeworkView, CView)

// 信息声明
BEGIN_MESSAGE_MAP(CMFChomeworkView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32771, &CMFChomeworkView::OnDrawLineSegment)
	ON_COMMAND(ID_32772, &CMFChomeworkView::OnDrawRectangle)
	ON_COMMAND(ID_32773, &CMFChomeworkView::OnDrawCircle)
	ON_COMMAND(ID_32774, &CMFChomeworkView::OnDrawEllipse)
	ON_COMMAND(ID_32776, &CMFChomeworkView::OnSetColor)
	ON_COMMAND(ID_32775, &CMFChomeworkView::OnSetPenSize)
	ON_COMMAND(ID_32777, &CMFChomeworkView::OnText)
	ON_COMMAND(ID_32778, &CMFChomeworkView::OnSetPencil)
	ON_COMMAND(ID_32779, &CMFChomeworkView::OnSetEraser)
	ON_COMMAND(ID_FILE_OPEN, &CMFChomeworkView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMFChomeworkView::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFChomeworkView::OnFileSaveAs)
	ON_COMMAND(ID_32780, &CMFChomeworkView::OnDrawNpoly)
	ON_COMMAND(ID_32785, &CMFChomeworkView::OnDrawDot)
	ON_COMMAND(ID_32786, &CMFChomeworkView::OnChoiceTool)
//	ON_WM_MBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_32781, &CMFChomeworkView::OnSetPenType)
	ON_COMMAND(ID_32782, &CMFChomeworkView::OnLayerone)
	ON_COMMAND(ID_32783, &CMFChomeworkView::OnLayertwo)
	ON_COMMAND(ID_32784, &CMFChomeworkView::OnLayerboth)
	ON_MESSAGE(WM_DIALOG1, &CMFChomeworkView::OnDialog1)
	ON_MESSAGE(WM_DIALOG2, &CMFChomeworkView::OnDialog2)
	
	ON_MESSAGE(WM_DIALOG3, &CMFChomeworkView::OnDialog3)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// CMFChomeworkView 构造/析构

// 初始化各个工具和设置
CMFChomeworkView::CMFChomeworkView() noexcept
{
	// TODO: 在此处添加构造代码
	m_PenSize = 1;
	m_PenType = PS_SOLID;
	m_PenColor = RGB(0, 0, 0);
	m_BrushColor = RGB(0, 0, 0);
	m_PointBegin = CPoint(0, 0);
	m_PointEnd = CPoint(0, 0);
	m_DrawType = DrawType::LineSegment;
}

CMFChomeworkView::~CMFChomeworkView()
{
}

BOOL CMFChomeworkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFChomeworkView 绘图

void CMFChomeworkView::OnDraw(CDC* /*pDC*/)
{
	CMFChomeworkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFChomeworkView 打印

BOOL CMFChomeworkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}
//暂未实现打印

void CMFChomeworkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}
//暂未实现打印

void CMFChomeworkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}
//暂未实现打印

// CMFChomeworkView 诊断

#ifdef _DEBUG
void CMFChomeworkView::AssertValid() const
{
	CView::AssertValid();
}

void CMFChomeworkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFChomeworkDoc* CMFChomeworkView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFChomeworkDoc)));
	return (CMFChomeworkDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFChomeworkView 消息处理程序


void CMFChomeworkView::OnLButtonDown(UINT nFlags, CPoint point)// 左键按下
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_PointBegin = m_PointEnd = point;// 初始化
	CClientDC dc(this);
	//dc.MoveTo(m_PointBegin);
	//dc.LineTo(m_PointEnd);
	// 只有画点才会在本步执行完毕
	if(m_DrawType == DrawType::dot){
		dc.SetROP2(R2_NOTXORPEN);
		m_PointBegin.x = m_PointBegin.x - 5;// 半径为5的空心点
		m_PointBegin.y = m_PointBegin.y - 5;// 半径为5的空心点
		m_PointEnd.x = m_PointEnd.x + 5;
		m_PointEnd.y = m_PointEnd.y + 5;
		CRect rectP2(m_PointBegin, m_PointEnd);
		dc.Ellipse(rectP2);
		//dc.MoveTo(m_PointBegin);
		//dc.LineTo(m_PointEnd);
		CRect rect;
		GetClientRect(&rect);

		//作图结束后存入对应图层文件
		if (layer_num == 1)
			hbitmap_1 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		else if (layer_num == 2)
			hbitmap_2 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		else
			;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFChomeworkView::OnMouseMove(UINT nFlags, CPoint point)// 鼠标移动
{
	CClientDC dc(this);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 根据目前m_DrawType即工具类型进行绘图控制
	if (m_DrawType == DrawType::Npoly_2) {
		CPen newPen, * oldPen;

		newPen.CreatePen(m_PenType, m_PenSize, m_PenColor);
		oldPen = dc.SelectObject(&newPen);

		dc.SetROP2(R2_NOTXORPEN);

		dc.MoveTo(m_PointBegin);
		dc.LineTo(m_PointEnd);

		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);

		m_PointEnd = point;


		dc.SelectObject(oldPen);
		
	}// Npoly2是绘制中间过程的工具，由程序自动转换
	// 原因是需区分出开始绘制多边形与绘制中间过程的不同，本步骤不需记忆起始点
	// 不需按住左键，自动跟随鼠标
	if (nFlags & MK_LBUTTON) {
		
		CPen newPen, * oldPen;

		newPen.CreatePen(m_PenType, m_PenSize, m_PenColor);// 配置画笔
		oldPen = dc.SelectObject(&newPen);

		switch (m_DrawType) {
		case DrawType::LineSegment:
		{
			dc.SetROP2(R2_NOTXORPEN);

			dc.MoveTo(m_PointBegin);
			dc.LineTo(m_PointEnd);

			dc.MoveTo(m_PointBegin);
			dc.LineTo(point);

			m_PointEnd = point;
			break;
		}			
		// 画线算法
		case DrawType::Rectangle: {
			dc.SetROP2(R2_NOTXORPEN);
			dc.SelectStockObject(5);

			CRect rectP1(m_PointBegin, m_PointEnd);
			dc.Rectangle(rectP1);
			CRect rectP2(m_PointBegin, point);
			dc.Rectangle(rectP2);
			m_PointEnd = point;
			break;
		}
		// 画矩形算法
		case DrawType::Npoly_1 :
		{
			dc.SetROP2(R2_NOTXORPEN);

			dc.MoveTo(m_PointBegin);
			dc.LineTo(m_PointEnd);

			dc.MoveTo(m_PointBegin);
			dc.LineTo(point);

			m_PointEnd = point;
			break;
		}
		// 画多边形起始算法
		case DrawType::Circle : 
		{
			dc.SetROP2(R2_NOTXORPEN);
			dc.SelectStockObject(5);

			int length_1 = m_PointEnd.y - m_PointBegin.y;
			if (m_PointEnd.x < m_PointBegin.x) {
				m_PointEnd.x = m_PointBegin.x - abs(length_1);
			}
			else {
				m_PointEnd.x = m_PointBegin.x + abs(length_1);
			}

			CRect rectP1(m_PointBegin, m_PointEnd);
			dc.Ellipse(rectP1);
			//分类进行计算
			int length_2 = point.y - m_PointBegin.y;
			if (point.x < m_PointBegin.x) {
				m_PointEnd.x = m_PointBegin.x - abs(length_2);
			}
			else {
				m_PointEnd.x = m_PointBegin.x+ abs(length_2);
			}
			m_PointEnd.y = point.y;

			CRect rectP2(m_PointBegin, m_PointEnd);
			dc.Ellipse(rectP2);

			m_PointEnd = point;
			break;
		}
		//画圆的控制逻辑
		case DrawType::Ellips: {
			dc.SetROP2(R2_NOTXORPEN);
			dc.SelectStockObject(5);

			CRect rectP1(m_PointBegin, m_PointEnd);
			dc.Ellipse(rectP1);
			CRect rectP2(m_PointBegin, point);
			dc.Ellipse(rectP2);
			m_PointEnd = point;
			break;
		}
		//画椭圆的控制逻辑
		case DrawType::Pencil:
		{
			m_PointBegin = m_PointEnd;
			m_PointEnd = point;
			dc.MoveTo(m_PointBegin);
			dc.LineTo(m_PointEnd);
			break;
		}
		//铅笔算法
		case DrawType::Eraser:
		{
			COLORREF pColor = dc.GetBkColor();
			CPen newPen(m_PenType, m_PenSize, pColor);
			dc.SelectObject(&newPen);


			m_PointBegin = m_PointEnd;
			m_PointEnd = point;
			dc.MoveTo(m_PointBegin);
			dc.LineTo(m_PointEnd);
			break;
		}
		//背景色铅笔——橡皮算法
		default:
			break;
		}


		dc.SelectObject(oldPen);
	}


	CView::OnMouseMove(nFlags, point);
}


void CMFChomeworkView::OnLButtonUp(UINT nFlags, CPoint point)// 左键抬起，对于非多边形而言意味着结束
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen newPen, * oldPen;
	
	newPen.CreatePen(m_PenType, m_PenSize, m_PenColor);//设置画笔属性
	oldPen = dc.SelectObject(&newPen);
	switch (m_DrawType) {
	case DrawType::LineSegment:
	{
		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);

		break;
	}
	//结束逻辑
	case DrawType::Npoly_1:
	{
		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);
		m_DrawType = DrawType::Npoly_2;
		m_Point_memory = m_PointBegin;// 记录起始位置到memory全局变量中
		m_PointBegin = m_PointEnd = point;

		break;
	}
	//对于多边形1而言是由初始作图，转为中间过程
	case DrawType::Npoly_2:
	{
		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);
		
		m_PointBegin = m_PointEnd = point;

		break;
	}
	//中间过程与画线类似
	case DrawType::Rectangle:
	{
		dc.SelectStockObject(PS_NULL);
		CRect rectP2(m_PointBegin, point);
		dc.Rectangle(rectP2);

		break;
	}
	// 矩形填充
	case DrawType::Ellips: {
		dc.SelectStockObject(PS_NULL);
		CRect rectP2(m_PointBegin, point);
		dc.Ellipse(rectP2);

		break;
	}
	// 椭圆填充
	case DrawType::Circle:
	{
		dc.SelectStockObject(5);

		int length_2 = point.y - m_PointBegin.y;
		if (point.x < m_PointBegin.x) {
			m_PointEnd.x = m_PointBegin.x - abs(length_2);
		}
		else {
			m_PointEnd.x = m_PointBegin.x + abs(length_2);
		}
		m_PointEnd.y = point.y;

		CRect rectP2(m_PointBegin, m_PointEnd);
		dc.Ellipse(rectP2);

		m_PointEnd = point;
		break;
	}
	// 圆形填充
	case DrawType::Pencil:
	{
		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);
		break;
	}
	// 铅笔结束
	case DrawType::Eraser:
	{
		COLORREF EraserColor = dc.GetBkColor();
		CPen newEraser(m_PenType, m_PenSize, EraserColor);
		dc.SelectObject(&newEraser);

		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);
		break;
	}
	//橡皮结束
	default:
		break;
	}

	CRect rect;
	GetClientRect(&rect);
	
	//作图结束后存入对应图层文件
	if (layer_num == 1)
		hbitmap_1 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
	else if (layer_num == 2)
		hbitmap_2 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
	else
		;
	
	dc.SelectObject(oldPen);
	CView::OnLButtonUp(nFlags, point);
}


void CMFChomeworkView::OnDrawLineSegment()// 画直线算法切换
{
	m_DrawType = DrawType::LineSegment;
	// TODO: 在此添加命令处理程序代码
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
}


void CMFChomeworkView::OnDrawRectangle()// 画长方形算法切换
{
	m_DrawType = DrawType::Rectangle;
	// TODO: 在此添加命令处理程序代码
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
}


void CMFChomeworkView::OnDrawCircle()// 画圆形算法切换
{
	m_DrawType = DrawType::Circle;
	// TODO: 在此添加命令处理程序代码
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
}



void CMFChomeworkView::OnDrawEllipse()// 画椭圆形算法切换
{
	m_DrawType = DrawType::Ellips;
	// TODO: 在此添加命令处理程序代码
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
}


void CMFChomeworkView::OnSetColor()// 设置颜色
{
	CColorDialog dig;

	if (IDOK == dig.DoModal()) {
		m_PenColor = dig.GetColor();//未设置成为非模态对话框，而是应用MFC自带函数GetColor
	}
	//if (pColorDialog == NULL) {
	//	pColorDialog = new CColorDialog;
	//	pColorDialog->Create(IDD_DIALOG1, NULL);//创建非模态对话框 
	//	pColorDialog->ShowWindow(SW_SHOW); //显示非模态对话框 
	//}
	//else
	//	pColorDialog->SetActiveWindow();//若对话框已创建，只需要激活即可
	// TODO: 在此添加命令处理程序代码
}

void CMFChomeworkView::OnSetPenSize()// 设置画笔宽度
{
	// TODO: 在此添加命令处理程序代码
	//CSetPenSizeDialog dig;
	//if (IDOK == dig.DoModal()) {
	//	this->m_PenSize = dig.m_PenSize;
	//}
	if (pPenSizeDialog == NULL) {
		pPenSizeDialog = new CSetPenSizeDialog;
		pPenSizeDialog->Create(IDD_DIALOG1, NULL);//创建非模态对话框 
		pPenSizeDialog->ShowWindow(SW_SHOW); //显示非模态对话框 
	}else
		pPenSizeDialog->SetActiveWindow();//若对话框已创建，只需要激活即可
	
}


//以下这个被废弃了
void CMFChomeworkView::OnText()// 暂无实现
{
	m_DrawType = DrawType::Text;
	// TODO: 在此添加命令处理程序代码
}


void CMFChomeworkView::OnSetPencil()// 画任意曲线算法切换
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DrawType::Pencil;
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
}


void CMFChomeworkView::OnSetEraser()// 擦除任意曲线算法切换
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DrawType::Eraser;
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
}


void CMFChomeworkView::OnFileOpen()// 打开文件算法
{
	m_DrawType = DrawType::m_load_or_save;
	// TODO: 在此添加命令处理程序代码
	CString filter, strPath;
	filter = "bmp图片(*.bmp)|*.bmp||";//提示
	CFileDialog dig(true, NULL, NULL, OFN_HIDEREADONLY, filter);
	if (dig.DoModal() == IDOK) //非模态获得文件地址
	{
		strPath = dig.GetPathName();
		MessageBox(strPath);
	}

	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		strPath,
		IMAGE_BITMAP,
		0, 0,
		LR_LOADFROMFILE);
	CBitmap loadImageBitmap;
	loadImageBitmap.Attach(hBitmap);


	BITMAP bitMap;//获取位图数据
	loadImageBitmap.GetBitmap(& bitMap);
	
	CBrush newBrush, * oldBrush;
	CPen newPen, * oldPen;

	newBrush.CreatePatternBrush(&loadImageBitmap);
	newPen.CreatePen(PS_NULL, 1, RGB(0, 0, 0));


	CClientDC dc(this);
	oldBrush = (CBrush*)dc.SelectObject(&newBrush);
	oldPen = dc.SelectObject(&newPen);

	
	dc.Rectangle(0, 0, bitMap.bmWidth, bitMap.bmHeight);// 按bitmap进行绘制至工作区


	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);


}



//颜色填充
//ExtFloodFill

//参考项目：CSDN—MFC保存文件
void CMFChomeworkView::OnFileSave()// 保存文件算法
{
	{
		m_DrawType = DrawType::m_load_or_save;
		// TODO: 在此添加命令处理程序代码
		CClientDC dc(this);
		CRect rect;
		CString saveFilePath;
		BOOL  showMsgTag;
		BOOL saveTag = FALSE;
		GetClientRect(&rect);
		HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		HDC hdc = CreateCompatibleDC(dc);
		HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
		//复制至目标结构
		BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0,
			SRCCOPY);
		CImage image;
		image.Attach(hbitmap);
		//写入Cimage数据结构
		if (!saveTag)
		{
			saveTag = TRUE;
			showMsgTag = TRUE;
			CString  strFilter = _T("位图文件(*.bmp)|*.bmp|JPEG 图像文件|*.jpg|  GIF图像文件 | *.gif | PNG图像文件 | *.png |其他格式(*.*) | *.* || ");
			CFileDialog dlg(FALSE, _T("bmp"), _T("iPaint1.bmp"), NULL, strFilter);
			if (dlg.DoModal() != IDOK) return;
			CString strFileName;
			CString strExtension;
			strFileName = dlg.m_ofn.lpstrFile;
			//扩展名分类
			if (dlg.m_ofn.nFileExtension == 0)
			{
				switch (dlg.m_ofn.nFilterIndex)
				{
				case 1:
					strExtension = "bmp";
					break;
				case 2:
					strExtension = "jpg";
					break;
				case 3:
					strExtension = "gif";
					break;
				case 4:
					strExtension = "png";
					break;

				}
				strFileName = strFileName + "." + strExtension;
			}
			saveFilePath = strFileName;
		}
		else
		{
			showMsgTag = FALSE;
		}
		HRESULT hResult = image.Save(saveFilePath);
		//保存结果提示
		if (FAILED(hResult)) {
			MessageBox(_T("保存图像文件失败！"));
		}
		else
		{
			if (showMsgTag)
				MessageBox(_T("文件保存成功！"));
		}
		image.Detach();
		SelectObject(hdc, hOldMap);
	}
}


void CMFChomeworkView::OnFileSaveAs()// 保存文件与OnFileSave相同
{
	// TODO: 在此添加命令处理程序代码
	{
		m_DrawType = DrawType::m_load_or_save;
		// TODO: 在此添加命令处理程序代码
		CClientDC dc(this);
		CRect rect;
		CString saveFilePath;
		BOOL  showMsgTag;
		BOOL saveTag = FALSE;
		GetClientRect(&rect);
		HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		HDC hdc = CreateCompatibleDC(dc);
		HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
		BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0,
			SRCCOPY);
		CImage image;
		image.Attach(hbitmap);
		if (!saveTag)
		{
			saveTag = TRUE;
			showMsgTag = TRUE;
			CString  strFilter = _T("位图文件(*.bmp)|*.bmp|JPEG 图像文件|*.jpg|  GIF图像文件 | *.gif | PNG图像文件 | *.png |其他格式(*.*) | *.* || ");
			CFileDialog dlg(FALSE, _T("bmp"), _T("iPaint1.bmp"), NULL, strFilter);
			if (dlg.DoModal() != IDOK) return;
			CString strFileName;
			CString strExtension;
			strFileName = dlg.m_ofn.lpstrFile;
			if (dlg.m_ofn.nFileExtension == 0)
			{
				switch (dlg.m_ofn.nFilterIndex)
				{
				case 1:
					strExtension = "bmp";
					break;
				case 2:
					strExtension = "jpg";
					break;
				case 3:
					strExtension = "gif";
					break;
				case 4:
					strExtension = "png";
					break;

				}
				strFileName = strFileName + "." + strExtension;
			}
			saveFilePath = strFileName;
		}
		else
		{
			showMsgTag = FALSE;
		}
		HRESULT hResult = image.Save(saveFilePath);
		if (FAILED(hResult)) {
			MessageBox(_T("保存图像文件失败！"));
		}
		else
		{
			if (showMsgTag)
				MessageBox(_T("文件保存成功！"));
		}
		image.Detach();
		SelectObject(hdc, hOldMap);
	}
}


void CMFChomeworkView::OnDrawNpoly()// 画多边形起始进入Npoly_1
{
	m_DrawType = DrawType::Npoly_1;
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
	// TODO: 在此添加命令处理程序代码
}


//void CMFChomeworkView::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CClientDC dc(this);
//	dc.MoveTo(m_Point_memory);
//	dc.LineTo(point);
//	m_PointBegin = m_PointEnd = point;
//	m_DrawType = DrawType::Npoly_1;
//
//	CView::OnMButtonDown(nFlags, point);
//}


void CMFChomeworkView::OnRButtonDown(UINT nFlags, CPoint point)// 右键按下，为多边形绘制提供最后的连线封闭
{

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	CPen newPen, * oldPen;

	newPen.CreatePen(m_PenType, m_PenSize, m_PenColor);
	oldPen = dc.SelectObject(&newPen);

	dc.MoveTo(m_Point_memory);// 连接至记录中的全局变量
	dc.LineTo(point);
	m_PointBegin = m_PointEnd = point;// 再初始化
	m_DrawType = DrawType::Npoly_1;// 返回起始状态
	dc.SelectObject(oldPen);
	CRect rect;
	GetClientRect(&rect);

	//作图结束后存入对应图层文件
	if (layer_num == 1)
		hbitmap_1 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
	else if (layer_num == 2)
		hbitmap_2 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
	else
		;
	CView::OnRButtonDown(nFlags, point);
}


void CMFChomeworkView::OnSetPenType()// 设置线型
{
	// TODO: 在此添加命令处理程序代码
	//CSetPenTypeDialog dig;
	//if (IDOK == dig.DoModal()) {
	//	this->m_PenType = dig.m_PenType;
	//}
	if (pPenTypeDialog == NULL) {
		pPenTypeDialog = new CSetPenTypeDialog;
		pPenTypeDialog->Create(IDD_DIALOG2, NULL);//创建非模态对话框 
		pPenTypeDialog->ShowWindow(SW_SHOW); //显示非模态对话框 
	}
	else
		pPenTypeDialog->SetActiveWindow();//若对话框已创建，只需要激活即可
}


void CMFChomeworkView::OnLayerone()// 设置图层1
{
	CClientDC dc(this);
	CRect rect;
	CString saveFilePath;
	//BOOL  showMsgTag;
	BOOL saveTag = FALSE;
	GetClientRect(&rect);
	m_DrawType = DrawType::m_load_or_save;
	//首先进行拒绝操作
	// 
	// TODO: 在此添加命令处理程序代码
	//
	//再进行当前工作区的保存
	if (layer_num == 1) {

		hbitmap_1 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		HDC hdc = CreateCompatibleDC(dc);
		HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap_1);
		BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0,
			SRCCOPY);
	}
	else if (layer_num == 2) {
		hbitmap_2 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		HDC hdc = CreateCompatibleDC(dc);
		HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap_2);
		BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0,
			SRCCOPY);
	}


	layer_num = 1;	//1代表只显示图层1，进行图层代码转变
	// TODO: 在此添加命令处理程序代码
	//CClientDC dc(this);
	//CRect rect;
	//写入本图层数据
	{
		CBitmap loadImageBitmap;
		loadImageBitmap.Attach(hbitmap_1);


		BITMAP bitMap;
		loadImageBitmap.GetBitmap(&bitMap);

		CBrush newBrush, * oldBrush;
		CPen newPen, * oldPen;

		newBrush.CreatePatternBrush(&loadImageBitmap);
		newPen.CreatePen(PS_NULL, 1, RGB(0, 0, 0));


		/*CClientDC dc(this);*/
		oldBrush = (CBrush*)dc.SelectObject(&newBrush);
		oldPen = dc.SelectObject(&newPen);


		dc.Rectangle(0, 0, bitMap.bmWidth, bitMap.bmHeight);


		dc.SelectObject(oldBrush);
		dc.SelectObject(oldPen);
	}
	
	
}


void CMFChomeworkView::OnLayertwo()// 设置图层2
{
	CClientDC dc(this);
	CRect rect;
	CString saveFilePath;
	//BOOL  showMsgTag;
	BOOL saveTag = FALSE;
	GetClientRect(&rect);
	m_DrawType = DrawType::m_load_or_save;
	//首先进行拒绝操作
	// 
	// TODO: 在此添加命令处理程序代码
	//
	//再进行当前工作区的保存
	if (layer_num == 1) {

		hbitmap_1 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		HDC hdc = CreateCompatibleDC(dc);
		HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap_1);
		BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0,
			SRCCOPY);
	}
	else if (layer_num == 2) {
		hbitmap_2 = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		HDC hdc = CreateCompatibleDC(dc);
		HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap_2);
		BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0,
			SRCCOPY);
	}


	layer_num = 2;	//2代表只显示图层2，进行图层处理代码转变
	// TODO: 在此添加命令处理程序代码
	//CClientDC dc(this);
	//CRect rect;
	//写入图层信息
	{
		CBitmap loadImageBitmap;
		loadImageBitmap.Attach(hbitmap_2);


		BITMAP bitMap;
		loadImageBitmap.GetBitmap(&bitMap);

		CBrush newBrush, * oldBrush;
		CPen newPen, * oldPen;

		newBrush.CreatePatternBrush(&loadImageBitmap);
		newPen.CreatePen(PS_NULL, 1, RGB(0, 0, 0));


		/*CClientDC dc(this);*/
		oldBrush = (CBrush*)dc.SelectObject(&newBrush);
		oldPen = dc.SelectObject(&newPen);


		dc.Rectangle(0, 0, bitMap.bmWidth, bitMap.bmHeight);


		dc.SelectObject(oldBrush);
		dc.SelectObject(oldPen);
	}
	
}


void CMFChomeworkView::OnLayerboth()// 尝试重叠显示方法一，但现在还未实现
{
	layer_num = 3;	//3代表both
	CClientDC dc(this);
	CDC* pCD = GetDC();
	m_DrawType = DrawType::m_load_or_save;
	CBitmap MyBMP;
	//MyBMP.LoadBitmap(IDR_MAINFRAME);
	MyBMP.Attach(hbitmap_1);
	CRect rect;
	BITMAP bm;
	MyBMP.GetBitmap(&bm);
	rect.top = bm.bmHeight + 5;
	rect.left = 0;
	CDC ImageDC;
	ImageDC.CreateCompatibleDC(pCD);
	CBitmap* pOldImageBMP = ImageDC.SelectObject(&MyBMP);
	TransparentBlt(pCD->m_hDC, 0, 0, 128, 15, ImageDC.m_hDC, 0, 0, 128, 15, ImageDC.GetPixel(1, 1));
	//可能是本句的使用问题，但未能修正
	//奇怪的是使用小图片进行测试时，重叠显示可以实现
	//另一个解决思路就是做两个bitmap在各个通道上的有优先级的像素级或操作

	//TransparentBlt(ImageDC.m_hDC, 0, 0, bm.bmWidth, bm.bmHeight, (&dc)->m_hDC, 0, 0, bm.bmWidth, bm.bmHeight, ImageDC.GetPixel(1, 1));

	//(&dc)->StretchBlt(0, 0, bm.bmWidth,bm.bmHeight,&ImageDC,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
	ImageDC.SelectObject(pOldImageBMP);

	CBitmap MyBMP2;
	BITMAP bm2;
	MyBMP2.Attach(hbitmap_2);
	MyBMP2.GetBitmap(&bm2);
	rect.bottom = rect.top + bm2.bmHeight;
	rect.right = bm2.bmWidth;
	CDC ImageDC2;
	ImageDC2.CreateCompatibleDC(pCD);
	CBitmap* pOldImageBMP2 = ImageDC2.SelectObject(&MyBMP2);
	TransparentBlt((&dc)->m_hDC, rect.left, rect.top, rect.Width(), rect.Height(), ImageDC2.m_hDC, 0, 0, bm2.bmWidth, bm2.bmHeight, RGB(0xff, 0xff, 0xff));
	pCD->StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(), &ImageDC2,0, 0, bm2.bmWidth,bm2.bmHeight,SRCCOPY);
	ImageDC2.SelectObject(pOldImageBMP);
	//TODO: 在此添加命令处理程序代码
}


afx_msg LRESULT CMFChomeworkView::OnDialog1(WPARAM wParam, LPARAM lParam)// 对话框1消息
{
	this->m_PenSize = pPenSizeDialog->m_PenSize; // 对话框处理 
	pPenSizeDialog->DestroyWindow();// 销毁对话框窗口 
	delete pPenSizeDialog;// 删除当前的非模态对话框对象 
	pPenSizeDialog = NULL;// 设置非模态对话框不存在标志 
	
	return 0;
}


afx_msg LRESULT CMFChomeworkView::OnDialog2(WPARAM wParam, LPARAM lParam)// 对话框2消息
{
	this->m_PenType = pPenTypeDialog->m_PenType;
	pPenTypeDialog->DestroyWindow();// 销毁对话框窗口 
	delete pPenTypeDialog;// 删除当前的非模态对话框对象 
	pPenTypeDialog = NULL;// 设置非模态对话框不存在标志 
	return 0;
}


void CMFChomeworkView::OnDrawDot()// 画点算法切换
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DrawType::dot;
	// TODO: 在此添加命令处理程序代码
	if (layer_num == 3)
		m_DrawType = DrawType::m_load_or_save;
}


void CMFChomeworkView::OnChoiceTool()// 工具选择程序
{
	// TODO: 在此添加命令处理程序代码
	if (pChoiceTool == NULL) {
		pChoiceTool = new CChoiceTool;
		pChoiceTool->Create(IDD_DIALOG3, NULL);//创建非模态对话框 
		pChoiceTool->ShowWindow(SW_SHOW); //显示非模态对话框 
	}
	else
		pChoiceTool->SetActiveWindow();//若对话框已创建，只需要激活即可
}


afx_msg LRESULT CMFChomeworkView::OnDialog3(WPARAM wParam, LPARAM lParam)// 工具选择会话框
{
	int tool_choice = 8;
	tool_choice = pChoiceTool->tool_choice;
	switch (tool_choice) {
	case 0:
	{
		m_DrawType = DrawType::LineSegment;
		break;
	}
	case 1:
	{
		m_DrawType = DrawType::Rectangle;
		break;
	}
	case 2:
	{
		m_DrawType = DrawType::Circle;
		break;
	}
	case 3:
	{
		m_DrawType = DrawType::Ellips;
		break;
	}
	case 5:
	{
		m_DrawType = DrawType::Pencil;
		break;
	}
	case 6:
	{
		m_DrawType = DrawType::Eraser;
		break;
	}
	case 4:
	{
		m_DrawType = DrawType::Npoly_1;
		break;
	}
	case 7:
	{
		m_DrawType = DrawType::dot;
		break;
	}
	default:
		break;
	}
	pChoiceTool->DestroyWindow();// 销毁对话框窗口 
	delete pChoiceTool;// 删除当前的非模态对话框对象 
	pChoiceTool = NULL;// 设置非模态对话框不存在标志 
	return 0;
}


HBRUSH CMFChomeworkView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)// 尝试重叠显示方法二，但现在还未实现
{
	HBRUSH hbr = CView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);		          //设置背景透明
		pDC->SetTextColor(RGB(255, 255, 255));        //设置字体为黄色
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
