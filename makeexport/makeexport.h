
// makeexport.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CmakeexportApp:
// �йش����ʵ�֣������ makeexport.cpp
//

class CmakeexportApp : public CWinAppEx
{
public:
	CmakeexportApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CmakeexportApp theApp;