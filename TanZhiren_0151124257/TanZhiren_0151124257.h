
// TanZhiren_0151124257.h : TanZhiren_0151124257 应用程序的主头文件
//

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CTanZhiren_0151124257App:
// 有关此类的实现，请参阅 TanZhiren_0151124257.cpp
//

class CTanZhiren_0151124257App : public CWinAppEx
{
public:
	CTanZhiren_0151124257App();
// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTanZhiren_0151124257App theApp;
