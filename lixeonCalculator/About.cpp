// About.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lixeonCalculator.h"
#include "About.h"


// About �Ի���

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


// About ��Ϣ�������
