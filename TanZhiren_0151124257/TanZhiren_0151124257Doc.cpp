
// TanZhiren_0151124257Doc.cpp : CTanZhiren_0151124257Doc 类的实现
//

#include "stdafx.h"
#include<string>
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TanZhiren_0151124257.h"
#endif

#include "TanZhiren_0151124257Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTanZhiren_0151124257Doc

IMPLEMENT_DYNCREATE(CTanZhiren_0151124257Doc, CDocument)

BEGIN_MESSAGE_MAP(CTanZhiren_0151124257Doc, CDocument)
END_MESSAGE_MAP()


// CTanZhiren_0151124257Doc 构造/析构
CTanZhiren_0151124257Doc::CTanZhiren_0151124257Doc()
{
	// TODO:  在此添加一次性构造代码
	head = new data;
	head->x = 0;
	head->next = NULL;
	head->Start.x = head->Start.y = head->End.x = head->End.y = 0;
}

CTanZhiren_0151124257Doc::~CTanZhiren_0151124257Doc()
{
}

BOOL CTanZhiren_0151124257Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CTanZhiren_0151124257Doc 序列化

void CTanZhiren_0151124257Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
		data *temp = head->next;
		while (temp != NULL)
		{
			int x0, y0, x1, y1, s;
			x0 = temp->Start.x;
			y0 = temp->Start.y;
			x1 = temp->End.x;
			y1 = temp->End.y;
			s = temp->x;
			CString str1;  str1.Format(_T("%d"), x0);
			CString str2;  str2.Format(_T("%d"), y0);
			CString str3;  str3.Format(_T("%d"), x1);
			CString str4;  str4.Format(_T("%d"), y1);
			CString str5;  str5.Format(_T("%d"), s);
			CString str;
			str = CString("\r\n");
			str = '(' + str1 + ',' + str2 + ')' + ' ' + ' ' + '(' + str3 + ',' + str4 + ')' + ' ' + '<' + str5 + '>'+str;
			ar.WriteString(str);
			temp = temp->next;
		}
	}
	else
	{
		int symbol = 0;
		CString str_temp = 0;
		CString str=0;
		CString str_x0=0, str_y0= 0,str_x1=0, str_y1=0;
		CString z;
		CString str1;
		while (ar.ReadString(str))
		{
			str1 += str;
		}
		int position=0;
		int num = str1.GetLength();
		for (int i = position; i < str1.GetLength(); i++)
		{
			if (str1[i] == 41||str1[i]==44||str1[i]==62)
				symbol ++;
			if (48<=str1[i]&&str1[i]<=57||str1[i]==45)
			{
				str_temp+=str1[i];
			}
			else
			{
				
				if (symbol == 1)
				{
					str_x0 = str_temp;
					str_temp.Empty();
				}
				else
				if (symbol == 2)
				{
					symbol++;
					str_y0 = str_temp;
					str_temp.Empty();
				}
				else
				if (symbol == 4)
				{
					str_x1 = str_temp;
					str_temp.Empty();
				}
				else
				if (symbol == 5)
				{
					symbol++;
					str_y1 = str_temp;
					str_temp.Empty();
				}
				else
				if (symbol == 7)
				{
					position = i + 5;
					z = str_temp;
					symbol = 0;
					data *p = new data;
					data *temp = head;
					p->next = NULL;
					p->Start.x = _ttoi(str_x0);
					p->Start.y = _ttoi(str_y0);
					p->End.x = _ttoi(str_x1);
					p->End.y = _ttoi(str_y1);
					p->x = _ttoi(z);
					while (temp->next != NULL)
						temp = temp->next;
					temp->next = p;
					str_temp.Empty();
				}
			}

		}
		// TODO:  在此添加加载代码

	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CTanZhiren_0151124257Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CTanZhiren_0151124257Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CTanZhiren_0151124257Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTanZhiren_0151124257Doc 诊断

#ifdef _DEBUG
void CTanZhiren_0151124257Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTanZhiren_0151124257Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTanZhiren_0151124257Doc 命令
