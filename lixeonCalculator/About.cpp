// About.cpp : 实现文件
//

#include "stdafx.h"
#include "lixeonCalculator.h"
#include "About.h"


// About 对话框

IMPLEMENT_DYNAMIC(About, CDialog)

About::About(CWnd* pParent /*=NULL*/)
	: CDialog(About::IDD, pParent)
{

}

About::~About()
{
}

void About::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(About, CDialog)
END_MESSAGE_MAP()


// About 消息处理程序
