// lixeonCalculator.h : Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// ClixeonCalculatorApp:
// �йش����ʵ�֣������ lixeonCalculator.cpp
//

class ClixeonCalculatorApp : public CWinApp
{
public:
	ClixeonCalculatorApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern ClixeonCalculatorApp theApp;