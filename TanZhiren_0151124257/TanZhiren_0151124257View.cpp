
// TanZhiren_0151124257View.cpp : CTanZhiren_0151124257View 类的实现
//

#include "stdafx.h"
#include<cmath>
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TanZhiren_0151124257.h"
#endif
#include "TanZhiren_0151124257Doc.h"
#include "TanZhiren_0151124257View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTanZhiren_0151124257View

IMPLEMENT_DYNCREATE(CTanZhiren_0151124257View, CView)

BEGIN_MESSAGE_MAP(CTanZhiren_0151124257View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAW_BRESENHAM, &CTanZhiren_0151124257View::OnDrawBresenham)
	ON_COMMAND(ID_DRAW_DDA, &CTanZhiren_0151124257View::OnDrawDda)
	ON_COMMAND(ID_DRAW_MID, &CTanZhiren_0151124257View::OnDrawMid)
	ON_COMMAND(ID_DRAW, &CTanZhiren_0151124257View::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_CIRCLE, &CTanZhiren_0151124257View::OnDrawCircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_BRESENHAM, &CTanZhiren_0151124257View::OnUpdateDrawBresenham)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DDA, &CTanZhiren_0151124257View::OnUpdateDrawDda)
	ON_UPDATE_COMMAND_UI(ID_DRAW_MID, &CTanZhiren_0151124257View::OnUpdateDrawMid)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()

END_MESSAGE_MAP()

// CTanZhiren_0151124257View 构造/析构

CTanZhiren_0151124257View::CTanZhiren_0151124257View()
{
	c = 0;
	// TODO:  在此处添加构造代码
}

CTanZhiren_0151124257View::~CTanZhiren_0151124257View()
{
}

BOOL CTanZhiren_0151124257View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTanZhiren_0151124257View 绘制

void CTanZhiren_0151124257View::OnDraw(CDC* pDC)
{
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	data *p = pDoc->head->next;
	while (p != NULL)
	{
		if (p->x == 1)
		{
			BRESENHAM(p->Start.x, p->Start.y, p->End.x, p->End.y, c);
		}
		else
		if (p->x == 2)
		{
			DDA(p->Start.x,p->End.x, p->Start.y, p->End.y, c);
		}
		else
		if (p->x == 3)
		{
			MID(p->Start.x,p->Start.y,p->End.x,p->End.y, c);
		}
		else
		if (p->x == 4)
		{
			int r;
			int temp;
			temp = (p->End.x - p->Start.x)*(p->End.x - p->Start.x) + (p->End.y - p->Start.y)* (p->End.y - p->Start.y);
			r = sqrt(temp);
			CIRCLE(p->Start.x, p->Start.y, r, c);
		}
		else
		if (p->x == 5)
		{
			int a;
			int b;
			a = p->End.x - p->Start.x;
			b = p->End.y - p->Start.y;
			ELLIPSE(p->Start.x,p->Start.y,a,b);
		}
		p = p->next;
	}
	
	//绘图


		
}


// CTanZhiren_0151124257View 打印

BOOL CTanZhiren_0151124257View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTanZhiren_0151124257View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CTanZhiren_0151124257View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CTanZhiren_0151124257View 诊断

#ifdef _DEBUG
void CTanZhiren_0151124257View::AssertValid() const
{
	CView::AssertValid();
}

void CTanZhiren_0151124257View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTanZhiren_0151124257Doc* CTanZhiren_0151124257View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTanZhiren_0151124257Doc)));
	return (CTanZhiren_0151124257Doc*)m_pDocument;
}
#endif //_DEBUG


// CTanZhiren_0151124257View 消息处理程序

void CTanZhiren_0151124257View::OnDrawBresenham()
{
	// TODO:  在此添加命令处理程序代码
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->Select = 1;
}


void CTanZhiren_0151124257View::OnDrawDda()
{
	// TODO:  在此添加命令处理程序代码
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->Select = 2;
}


void CTanZhiren_0151124257View::OnDrawMid()
{
	// TODO:  在此添加命令处理程序代码
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->Select = 3;
}


void CTanZhiren_0151124257View::OnUpdateDrawBresenham(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->Select==1)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CTanZhiren_0151124257View::OnUpdateDrawDda(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->Select == 2)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CTanZhiren_0151124257View::OnUpdateDrawMid(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->Select == 3)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CTanZhiren_0151124257View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->p = point;
	CView::OnLButtonDown(nFlags, point);
}


void CTanZhiren_0151124257View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->q = point;
	data *p = new data;
	p->next = NULL;
	p->Start = pDoc->p;
	p->End = pDoc->q;
	p->x = pDoc->Select;
	data *temp;
	temp = pDoc->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = p;
	switch (pDoc->Select)
	{
	case 1:BRESENHAM(pDoc->p.x, pDoc->p.y, pDoc->q.x, pDoc->q.y, c);
		break;
	case 2:DDA(pDoc->p.x, pDoc->q.x,pDoc-> p.y,pDoc-> q.y, c);
		break;
	case 3:MID(pDoc->p.x,pDoc ->p.y,pDoc-> q.x, pDoc->q.y, c);
		break;
	case 4:
	{
			  int r;
			  int temp;
			  temp = (pDoc->q.x - pDoc->p.x)*(pDoc->q.x - pDoc->p.x) + (pDoc->q.y - pDoc->p.y)* (pDoc->q.y - pDoc->p.y);
			  r = sqrt(temp);
			  CIRCLE(pDoc->p.x, pDoc->p.y, r, c);
	}
		break;
	case 5:
	{
			  int a;
			  int b;
			  a = pDoc->q.x - pDoc->p.x;
			  b = pDoc->q.y - pDoc->p.y;
			  ELLIPSE(pDoc->p.x,pDoc->p.y,a,b);
	}
		break;
	default:
		break;
	}
	//保存数据
	CView::OnLButtonUp(nFlags, point);
}



void CTanZhiren_0151124257View::DDA(float x, float x1, float y, float y1, int c)
{
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC* pDC = GetDC();
	float dx, dy;
	dx = (float)(pDoc->q.x - pDoc->p.x);
	dy = (float)(pDoc->q.y - pDoc->p.y);
	float k = dy / dx;
	x1 = pDoc->p.x;
	y1 = pDoc->p.y;
	y = pDoc->p.y;
	c = RGB(0, 0, 0);
	int step = 1;
	if (fabs(k) <= 1)
	{
		for (x = pDoc->p.x; x<pDoc->q.x; x = x + step)
		{
			pDC->SetPixel(x, y, c);
			y = y + k*step;
		}
	}
	else if (fabs(k)>1)
	{
		for (y = pDoc->p.y; y<pDoc->q.y; y = y + step)
		{
			pDC->SetPixel(x1, y, c);
			x1 = x1 + (1 / k)*step;
		}
	}
	ReleaseDC(pDC);
}


void CTanZhiren_0151124257View::MID(float x0, float y0, float x1, float y1, int c)
{
	CDC* pDC = GetDC();
	int a, b, d1, d2, d, x, y; float m; if (x1<x0){ d = x0, x0 = x1, x1 = d; d = y0, y0 = y1, y1 = d; }
	a = y0 - y1, b = x1 - x0; if (b == 0) m = -1 * a * 100;
	else m = (float)a / (x0 - x1); x = x0, y = y0;
	pDC->SetPixel(x, y, c);
	if (m >= 0 && m <= 1)
	{
		d = 2 * a + b; d1 = 2 * a, d2 = 2 * (a + b);
		while (x<x1)
		{
			if (d <= 0)    { x++, y++, d += d2; }
			else    { x++, d += d1; }
			pDC->SetPixel(x, y, c);
		}
	}
	else if (m <= 0 && m >= -1)
	{
		d = 2 * a - b; d1 = 2 * a - 2 * b, d2 = 2 * a;
		while (x<x1)
		{
			if (d>0) { x++, y--, d += d1; }
			else    { x++, d += d2; }
			pDC->SetPixel(x, y, c);
		}
	}
	else if (m>1)
	{
		d = a + 2 * b; d1 = 2 * (a + b), d2 = 2 * b;
		while (y<y1)
		{
			if (d>0) { x++, y++, d += d1; }
			else    { y++, d += d2; }
			pDC->SetPixel(x, y, c);
		}
	}
	else
	{
		d = a - 2 * b; d1 = -2 * b, d2 = 2 * (a - b);
		while (y>y1)
		{
			if (d <= 0)
			{
				x++, y--, d += d2;
			}
			else
			{
				y--, d += d1;
			}
			pDC->SetPixel(x, y, c);
		}
	}
}


void CTanZhiren_0151124257View::BRESENHAM(float x0, float y0, float x1, float y1, int c)
{
	CDC* pDC = GetDC();
	int x, y, dx, dy, s1, s2, p, temp, interchange, i;
	x = x0;
	y = y0; 
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);  
	if (x1>x0)  
		s1 = 1; 
	else   s1 = -1;  
	if (y1>y0)  
		s2 = 1; 
	else
		s2 = -1;  
	if (dy>dx)
	{ temp = dx;   dx = dy;   dy = temp;   interchange = 1; }
	else 
		interchange = 0;  
	p = 2 * dy - dx; 
	for (i = 1; i <= dx; i++)
	{
		pDC->SetPixel(x, y, c); 
		if (p >= 0) 
		{
			if (interchange == 0)  
				y = y + s2;  
			else
				x = x + s1;  
			p = p - 2 * dx;
		} 
		else
		if (interchange == 0) 
			x = x + s1;   
		else   
			y = y + s2;   
		p = p + 2 * dy;
	}
}



void CTanZhiren_0151124257View::OnDrawEllipse()
{
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->Select = 5;
	// TODO:  在此添加命令处理程序代码
}


void CTanZhiren_0151124257View::OnDrawCircle()
{
	CTanZhiren_0151124257Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->Select = 4;
	// TODO:  在此添加命令处理程序代码
}
void CTanZhiren_0151124257View::CIRCLE(float x0, float y0, int r, int c)
{
	int x, y;
	float d;
	x = 0;
	y = r;
	d = 5.0 / 4 - r;
	while (x <= y)
	{
		putdot(x0, y0, x, y, c);
		if (d<0)
			d += x*2.0 + 3;
		else
		{
			d += 2.0*(x - y) + 5;
			y--;
		}
		x++;
	}
}

void CTanZhiren_0151124257View::putdot(int x0, int y0, int x1, int y1, int c)//八分画圆
{
	CDC* pDC = GetDC();
	pDC->SetPixel(x0 + x1, y0 + y1, c);

	pDC->SetPixel(x0 + x1, y0 - y1, c);

	pDC->SetPixel(x0 - x1, y0 + y1, c);

	pDC->SetPixel(x0 - x1, y0 - y1, c);

	pDC->SetPixel(x0 + y1, y0 + x1, c);

	pDC->SetPixel(x0 + y1, y0 - x1, c);

	pDC->SetPixel(x0 - y1, y0 + x1, c);

	pDC->SetPixel(x0 - y1, y0 - x1, c);
}


void CTanZhiren_0151124257View::ELLIPSE(int x0, int y0, int a, int b)
{
	double sqa = a*a;
	double sqb = b*b;

	double d = sqb + sqa*(0.25 - b);
	int x = 0;
	int y = b;
	Ellipsepot(x0, y0, x, y);
	// 1
	while (sqb*(x + 1) < sqa*(y - 0.5))
	{
		if (d < 0)
		{
			d += sqb*(2 * x + 3);
		}
		else
		{
			d += (sqb*(2 * x + 3) + sqa*((-2)*y + 2));
			--y;
		}
		++x;
		Ellipsepot(x0, y0, x, y);
	}
	d = (b * (x + 0.5)) * 2 + (a * (y - 1)) * 2 - (a * b) * 2;
	// 2
	while (y > 0)
	{
		if (d < 0)
		{
			d += sqb * (2 * x + 2) + sqa * ((-2) * y + 3);
			++x;
		}
		else
		{
			d += sqa * ((-2) * y + 3);
		}
		--y;
		Ellipsepot(x0, y0, x, y);
	}
}


void CTanZhiren_0151124257View::Ellipsepot(int x0, int y0, int x, int y)//四分画椭圆
{
	CDC* pDC = GetDC();
	// 1
	pDC->SetPixel((x0 + x), (y0 + y),c);
	// 2
	pDC->SetPixel((x0 + x), (y0 - y),c);
	// 3
	pDC->SetPixel((x0 - x), (y0 - y),c);
	// 4
	pDC->SetPixel((x0 - x), (y0 + y),c);
}
