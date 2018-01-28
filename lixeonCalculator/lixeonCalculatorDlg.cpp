// lixeonCalculatorDlg.cpp : 实现功能
#include "stdafx.h"
#include "lixeonCalculator.h"
#include "lixeonCalculatorDlg.h"
#include "math.h" //调用数学库
#include "About.h"
#include"Bdscal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



CString tmp;
CString tmp_2;



//  对话框的构造

ClixeonCalculatorDlg::ClixeonCalculatorDlg(CWnd* pParent /*=NULL*/)
: CDialog(ClixeonCalculatorDlg::IDD, pParent)
, m_duType(0) //默认弧度
, m_first(0.0) //初始化为0.0
, m_second(0.0)
, m_operator(_T("+")) 
, m_coff(1.0) //默认为整数
, m_display(_T("0.0"))
, m_PI(3.14159265358979323846)
, isXY(false)
, isMOD(false)
, temp(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

ClixeonCalculatorDlg::~ClixeonCalculatorDlg()
{/*
	UpdateData(true);

	CFileDialog dlg(FALSE,_T("txt"),_T("test.txt"));//FALSE表示为“另存为”对话框，否则为“打开”对话框
	if(dlg.DoModal() == IDOK)
	{
		CString strFile = dlg.GetPathName();//获取完整路径
		CString strEdit1,strEdit2;
		GetDlgItemText(IDC_EDIT1,strEdit1);//获取指定ID的编辑框内容
	//	GetDlgItemText(IDC_EDIT2,strEdit2);//同上
		CStdioFile file;
		if(file.Open(strFile,CStdioFile::modeCreate|CStdioFile::modeNoTruncate|CStdioFile::modeWrite))//创建/打开文件
		{
			file.WriteString(strEdit1);//写入内容
			file.WriteString(_T("\r\n"));//换行
		//	file.WriteString(strEdit2);//写入内容
			file.Close();//关闭输出文件
		}
	}
	*/
}

//实现数据更替
void ClixeonCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, m_display);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

//消息相应宏定义

BEGIN_MESSAGE_MAP(ClixeonCalculatorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_HUDU, &ClixeonCalculatorDlg::OnBnClickedHudu)
	ON_BN_CLICKED(IDC_JIAODU, &ClixeonCalculatorDlg::OnBnClickedJiaodu)
	ON_BN_CLICKED(IDC_BUTTON0, &ClixeonCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &ClixeonCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ClixeonCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ClixeonCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &ClixeonCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &ClixeonCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &ClixeonCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &ClixeonCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &ClixeonCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &ClixeonCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, &ClixeonCalculatorDlg::OnBnClickedButtonSign)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &ClixeonCalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &ClixeonCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &ClixeonCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUTIPLY, &ClixeonCalculatorDlg::OnBnClickedButtonMutiply)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &ClixeonCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &ClixeonCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &ClixeonCalculatorDlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_RECI, &ClixeonCalculatorDlg::OnBnClickedButtonReci)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &ClixeonCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_EXP, &ClixeonCalculatorDlg::OnBnClickedExp)
	ON_BN_CLICKED(IDC_COS, &ClixeonCalculatorDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_SIN, &ClixeonCalculatorDlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_LN, &ClixeonCalculatorDlg::OnBnClickedLn)
	ON_BN_CLICKED(IDC_LOG, &ClixeonCalculatorDlg::OnBnClickedLog)
	ON_BN_CLICKED(IDC_ARCCOS, &ClixeonCalculatorDlg::OnBnClickedArccos)
	ON_BN_CLICKED(IDC_ARCSIN, &ClixeonCalculatorDlg::OnBnClickedArcsin)
	ON_BN_CLICKED(IDC_TAN, &ClixeonCalculatorDlg::OnBnClickedTan)
	ON_BN_CLICKED(IDC_ARCTAN, &ClixeonCalculatorDlg::OnBnClickedArctan)
	ON_BN_CLICKED(IDC_XDEY, &ClixeonCalculatorDlg::OnBnClickedXdey)
	ON_BN_CLICKED(IDC_NJIECHENG, &ClixeonCalculatorDlg::OnBnClickedNjiecheng)
	ON_BN_CLICKED(IDC_PI, &ClixeonCalculatorDlg::OnBnClickedPi)
	ON_BN_CLICKED(IDC_MOD, &ClixeonCalculatorDlg::OnBnClickedMod)
	ON_BN_CLICKED(IDC_3DEX, &ClixeonCalculatorDlg::OnBnClicked3dex)
	ON_BN_CLICKED(IDC_2DEX, &ClixeonCalculatorDlg::OnBnClicked2dex)
	ON_BN_CLICKED(IDC_About, &ClixeonCalculatorDlg::OnBnClickedAbout)
	ON_EN_CHANGE(IDC_EDIT1, &ClixeonCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_bdscal, &ClixeonCalculatorDlg::OnBnClickedbdscal)
END_MESSAGE_MAP()


// ClixeonCalculatorDlg 消息处理



void ClixeonCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


//弧度
void ClixeonCalculatorDlg::OnBnClickedHudu()
{
	m_duType=0;//系统默认m_duType为0 为弧度计算
}
//角度
void ClixeonCalculatorDlg::OnBnClickedJiaodu()
{
	m_duType=1;
}


//在编辑框中显示数据
void ClixeonCalculatorDlg::UpdateDisplay(double dck)
{
	m_display.Format(_T("%lf"),dck);
	m_display = m_display + "\r\n" + tmp_2;
	UpdateData(false);//更新编辑框变量m_display
}

//计算结果
void ClixeonCalculatorDlg::Calculate(void)
{//将前一次数据与当前数据进行运算，作为下次的第一操作数，并在编辑框显示。
	switch(m_operator.GetAt(0))
	{  
	case '+': m_first+=m_second;break;
	case '-': m_first-=m_second;break;
	case '*': m_first*=m_second;break;
	case '/':

		if(fabs(m_second)<=0.000001)
		{
			m_display="除数不能为0";
			UpdateData(false);
			return; 
		}
		m_first/=m_second;break;
	 }

	m_second=0.0;

	m_coff=1.0;

	m_operator = "+";

	UpdateDisplay(m_first);


}

void ClixeonCalculatorDlg::onButtonN(int n)
{
	if( m_coff == 1.0)
		m_second = m_second*10 + n;//作为整数输入数字时
	else  
	{ m_second = m_second + n*m_coff; //作为小数输入数字
	m_coff *= 0.1;	}

	tmp.Format(_T("%g"),m_second);

	UpdateDisplay(m_second);//更新编辑框的数字显示

}

void ClixeonCalculatorDlg::OnBnClickedButton0()
{
	onButtonN(0);
}

void ClixeonCalculatorDlg::OnBnClickedButton1()
{
	onButtonN(1);
}

void ClixeonCalculatorDlg::OnBnClickedButton2()
{
	onButtonN(2);
}

void ClixeonCalculatorDlg::OnBnClickedButton3()
{
	onButtonN(3);
}

void ClixeonCalculatorDlg::OnBnClickedButton4()
{
	onButtonN(4);
}

void ClixeonCalculatorDlg::OnBnClickedButton5()
{
	onButtonN(5);
}

void ClixeonCalculatorDlg::OnBnClickedButton6()
{
	onButtonN(6);
}

void ClixeonCalculatorDlg::OnBnClickedButton7()
{
	onButtonN(7);
}

void ClixeonCalculatorDlg::OnBnClickedButton8()
{
	onButtonN(8);
}

void ClixeonCalculatorDlg::OnBnClickedButton9()
{
	onButtonN(9);
}

//   "+/-"
void ClixeonCalculatorDlg::OnBnClickedButtonSign()
{
	m_second = -m_second;	
	UpdateDisplay(m_second);
}

//   "."
void ClixeonCalculatorDlg::OnBnClickedButtonPoint()
{
	m_coff	= 0.1 ;
}

//   "+"
void ClixeonCalculatorDlg::OnBnClickedButtonAdd()
{
	tmp += '+';
	tmp_2 = tmp;
    Calculate();
	m_operator="+"; 
}


//   "-"
void ClixeonCalculatorDlg::OnBnClickedButtonMinus()
{
	Calculate();
	m_operator="-"; 
	tmp += '-';
	tmp_2 = tmp ;
}

//   "x"
void ClixeonCalculatorDlg::OnBnClickedButtonMutiply()
{
	tmp += '*';
	tmp_2 = tmp ;
	Calculate();
	m_operator="*"; 
}

//   "/"
void ClixeonCalculatorDlg::OnBnClickedButtonDiv()
{	
	tmp += '/';
	tmp_2 = tmp ;
	Calculate();
	m_operator.Format(_T("%s"),"/");

}

//   "C"
void ClixeonCalculatorDlg::OnBnClickedButtonClear()
{
	m_first=0.0;
	m_second=0.0;
	m_operator = "+";
	m_coff = 1.0;
	tmp = "" ;
	tmp_2 = " ";
	UpdateDisplay(0.0);
}
//   "sqrt"
void ClixeonCalculatorDlg::OnBnClickedButtonSqrt()
{
	if( m_second==0)
	{    
	m_first=sqrt(m_first);      
	tmp_2 = "根号下" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_first);   }
	else
	{ m_second=sqrt(m_second);    
	tmp_2 = "根号下" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);	}
}
//   "1/x"
void ClixeonCalculatorDlg::OnBnClickedButtonReci()
{
	//按钮输入和上一步计算均为0 报错
	if(fabs(m_second)<0.000001 && fabs(m_first)<0.000001)
	{
		m_display = "除数不能为零";
		UpdateData(false);
		return;	
	}
	//上一步计算不为0  连续计算时
	if( fabs(m_second)<0.000001)
	{   
		m_first=1.0/m_first;
			tmp_2 =  tmp + "^-1" + '=' ;
	tmp.Format(_T("%g"),m_second);
		UpdateDisplay(m_first);
	}
	else
		//按钮输入不为0
	{ m_second=1.0/m_second;
	tmp_2 =   tmp + "^-1" + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
	}
}
//   "="
void ClixeonCalculatorDlg::OnBnClickedButtonEqual()
{
	xDEy();
	xMODy();
	tmp_2 = tmp_2 + tmp + '=' ;
	Calculate(); 
	tmp.Format(_T("%g"),m_first);
}

//判断是否点击了“x^y”，点击后实现
void ClixeonCalculatorDlg::xDEy(void)
{
	if(isXY)
	{
		m_second=m_second;
		m_second=pow(temp,m_second);

	}
}
//   "Exp"
void ClixeonCalculatorDlg::OnBnClickedExp()
{
	m_second=exp(m_second);
	tmp_2 = "e^" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}

//   "cos"
void ClixeonCalculatorDlg::OnBnClickedCos()
{
	sanjiaoHanshu();
	m_second=cos(m_second);
	tmp_2 = "cos" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}
//   "sin"
void ClixeonCalculatorDlg::OnBnClickedSin()
{
	sanjiaoHanshu();
	m_second=sin(m_second);
	tmp_2 = "sin" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}
//   "ln"
void ClixeonCalculatorDlg::OnBnClickedLn()
{
	m_second=log(m_second);
	tmp_2 = "ln" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}
//   "log"
void ClixeonCalculatorDlg::OnBnClickedLog()
{
	m_second=log10(m_second);
	tmp_2 = "log" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}
//   "arccos"
void ClixeonCalculatorDlg::OnBnClickedArccos()
{
	sanjiaoHanshu();
	m_second=acos(m_second);
	tmp_2 = "arccos" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);

}
//   "arcsin"
void ClixeonCalculatorDlg::OnBnClickedArcsin()
{
	sanjiaoHanshu();
	m_second=asin(m_second);
		tmp_2 = "arcsin" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}
//   "tan"
void ClixeonCalculatorDlg::OnBnClickedTan()
{
	sanjiaoHanshu();
	m_second=tan(m_second);
	tmp_2 = "tan" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}
//   "arctan"
void ClixeonCalculatorDlg::OnBnClickedArctan()
{
	sanjiaoHanshu();
	m_second=atan(m_second);
	tmp_2 = "arctan" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}


// 用来抉择结果，是弧度还是角度
void ClixeonCalculatorDlg::sanjiaoHanshu(void)
{
	switch(m_duType)
	{
	    case 0:
	          m_second=m_second;
	          break;
	    case 1:
	       	  m_second=m_second*m_PI/180;
	      	  break;
	}
}

//   "x^y"
void ClixeonCalculatorDlg::OnBnClickedXdey()
{
	tmp += '^';
	tmp_2 = tmp;
	temp=m_second;
	m_second=0.0;
	m_display = "幂函数运算过程中,请输入下一个操作数";
	UpdateData(false);
	isXY=true;
}

//   "n!"
void ClixeonCalculatorDlg::OnBnClickedNjiecheng()
{
	if((m_second-(int)m_second)>0){
		m_display =_T("你输入的不是整数，请输入整数！");
		UpdateData(false);//如果是非整数，则结束运算，重新开始
		return;
	}
	else {
		m_second=(double)jiecheng(m_second);
		tmp_2 =  tmp + '!' + '=' ;
	tmp.Format(_T("%g"),m_second);
		UpdateDisplay(m_second);
	}
}

int ClixeonCalculatorDlg::jiecheng(int n)
{
	if(n==0||n==1){
		return 1;
	}else if(n>1){
		return n*jiecheng(n-1);
	} //递归计算
}

void ClixeonCalculatorDlg::OnBnClickedPi()
{
	m_second = m_PI;
	tmp_2 = "π" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_PI);
}

void ClixeonCalculatorDlg::OnBnClickedMod()
{
	if((m_second-(int)m_second)>0){
		m_display =_T("你输入的不是整数，请输入整数！");
		UpdateData(false);
		return;
	}
	else
	{
     tmp += "mod";
	 tmp_2 =  tmp  ;
	 temp = m_second;
	 m_second = 0.0;
	 m_display = "求模运算中,请输入下一个整数.";
	 UpdateData(false);
	 isMOD = true;
	}
}

void ClixeonCalculatorDlg::xMODy(void)
{
	if(isMOD)
	{
		m_second = m_second;
		m_second = (int)temp % (int)m_second;

	}
}
void ClixeonCalculatorDlg::OnBnClicked3dex()
{
	temp=m_second;
	m_second=pow(2,temp);
	tmp_2 = "2^" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}

void ClixeonCalculatorDlg::OnBnClicked2dex()
{
	temp=m_second;
	m_second=pow(temp,2);
	tmp_2 =   tmp + "^2" +  '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);
}

void ClixeonCalculatorDlg::OnBnClickedAbout()
{
        About dlg;
		dlg.DoModal(); 
}

void ClixeonCalculatorDlg::OnEnChangeEdit1()
{

}

void ClixeonCalculatorDlg::OnBnClickedbdscal()
{
        Bdscal dlg;
		dlg.DoModal(); 
}
