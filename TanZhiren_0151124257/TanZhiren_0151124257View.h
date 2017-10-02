
// TanZhiren_0151124257View.h : CTanZhiren_0151124257View 类的接口
//

class CTanZhiren_0151124257View : public CView
{
protected: // 仅从序列化创建
	CTanZhiren_0151124257View();
	DECLARE_DYNCREATE(CTanZhiren_0151124257View)

// 特性
public:
   CTanZhiren_0151124257Doc* GetDocument() const;
// 操作
public:
	int c;
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
	virtual ~CTanZhiren_0151124257View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawBresenham();
	afx_msg void OnDrawDda();
	afx_msg void OnDrawMid();
	afx_msg void OnUpdateDrawBresenham(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawDda(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawMid(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPtrArray m_ptrarray;
	void DDA(float x, float x1, float y, float y1, int c);
	void MID(float x0, float y0, float x1, float y1, int c);
	void BRESENHAM(float x1, float y1, float x2, float y2, int c);
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawCircle();
	void CIRCLE(float x0, float y0, int r, int c);
//	void putdot(int x0);
	void putdot(int x0, int y0, int x1, int y1, int c);
	void ELLIPSE(int x0, int y0, int a, int b);
	void Ellipsepot(int x0, int y0, int x, int y);
};

#ifndef _DEBUG  // TanZhiren_0151124257View.cpp 中的调试版本
inline CTanZhiren_0151124257Doc* CTanZhiren_0151124257View::GetDocument() const
   { return reinterpret_cast<CTanZhiren_0151124257Doc*>(m_pDocument); }
#endif

