
// TanZhiren_0151124257.h : TanZhiren_0151124257 Ӧ�ó������ͷ�ļ�
//

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTanZhiren_0151124257App:
// �йش����ʵ�֣������ TanZhiren_0151124257.cpp
//

class CTanZhiren_0151124257App : public CWinAppEx
{
public:
	CTanZhiren_0151124257App();
// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTanZhiren_0151124257App theApp;
