
// TanZhiren_0151124257Doc.h : CTanZhiren_0151124257Doc 类的接口
//
struct data
{
	CPoint Start, End;
	int x;
	data *next;
};
class CTanZhiren_0151124257Doc : public CDocument
{
protected: // 仅从序列化创建
	CTanZhiren_0151124257Doc();
	DECLARE_DYNCREATE(CTanZhiren_0151124257Doc)

// 特性
public:
	CPoint p,q;
	int Select;
// 操作
public:
	data *head;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CTanZhiren_0151124257Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
