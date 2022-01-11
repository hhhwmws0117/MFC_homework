
// MFC_homeworkView.h: CMFChomeworkView 类的接口
//

#pragma once
#include "MFC_homeworkDoc.h"


class CMFChomeworkView : public CView
{
protected: // 仅从序列化创建
	CMFChomeworkView() noexcept;
	DECLARE_DYNCREATE(CMFChomeworkView)

// 特性
public:

	CMFChomeworkDoc* GetDocument() const;

// 操作
public:
	int m_PenSize,m_PenType;// 线宽、线型
	COLORREF m_PenColor, m_BrushColor;// 画笔颜色，画刷颜色
	CPoint m_PointBegin, m_PointEnd;// 线开始、线结尾
	CPoint m_Point_memory;// 线暂存

	int layer_num = 1;// 层标记

	enum class DrawType {
		LineSegment, Circle, Rectangle, Ellips,Pencil,Text,Eraser, m_load_or_save, Npoly_1, Npoly_2, dot
	}m_DrawType;// 工具类型




// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFChomeworkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnDialog1(WPARAM wParam, LPARAM lParam);// 对话框1消息
	afx_msg LRESULT OnDialog2(WPARAM wParam, LPARAM lParam);// 对话框2消息
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);// 左键按下
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);// 鼠标移动
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);// 左键抬起
	afx_msg void OnDrawLineSegment();// 画直线算法
	afx_msg void OnDrawRectangle();// 画长方形算法
	afx_msg void OnDrawCircle();// 画圆形算法
	afx_msg void OnDrawEllipse();// 画椭圆形算法
	afx_msg void OnSetColor();// 设置颜色
	afx_msg void OnSetPenSize();// 设置画笔宽度
	afx_msg void OnText();// 暂无
	afx_msg void OnSetPencil();// 画任意曲线算法
	afx_msg void OnSetEraser();// 擦除任意曲线算法
	afx_msg void OnFileOpen();// 打开文件
	afx_msg void OnFileSave();// 保存文件
	afx_msg void OnFileSaveAs();// 保存文件
	afx_msg void OnDrawNpoly();// 画多边形
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);// 右键按下
	afx_msg void OnSetPenType();// 设置线型
	afx_msg void OnLayerone();// 设置图层1
	afx_msg void OnLayertwo();// 设置图层2
	afx_msg void OnLayerboth();// 尝试重叠显示方法一，但现在还未实现
protected:
	//afx_msg LRESULT OnDialog1(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT OnDialog2(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnDrawDot();// 画点算法
	afx_msg void OnChoiceTool();// 工具选择程序
protected:
	afx_msg LRESULT OnDialog3(WPARAM wParam, LPARAM lParam);// 工具选择会话框
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);// 尝试重叠显示方法二，但现在还未实现
};

#ifndef _DEBUG  // MFC_homeworkView.cpp 中的调试版本
inline CMFChomeworkDoc* CMFChomeworkView::GetDocument() const
   { return reinterpret_cast<CMFChomeworkDoc*>(m_pDocument); }
#endif

