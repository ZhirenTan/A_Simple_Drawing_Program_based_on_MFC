
// TanZhiren_0151124257Doc.h : CTanZhiren_0151124257Doc ��Ľӿ�
//
struct data
{
	CPoint Start, End;
	int x;
	data *next;
};
class CTanZhiren_0151124257Doc : public CDocument
{
protected: // �������л�����
	CTanZhiren_0151124257Doc();
	DECLARE_DYNCREATE(CTanZhiren_0151124257Doc)

// ����
public:
	CPoint p,q;
	int Select;
// ����
public:
	data *head;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CTanZhiren_0151124257Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
