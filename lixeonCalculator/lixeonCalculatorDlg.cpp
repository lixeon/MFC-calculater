// lixeonCalculatorDlg.cpp : ʵ�ֹ���
#include "stdafx.h"
#include "lixeonCalculator.h"
#include "lixeonCalculatorDlg.h"
#include "math.h" //������ѧ��
#include "About.h"
#include"Bdscal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



CString tmp;
CString tmp_2;



//  �Ի���Ĺ���

ClixeonCalculatorDlg::ClixeonCalculatorDlg(CWnd* pParent /*=NULL*/)
: CDialog(ClixeonCalculatorDlg::IDD, pParent)
, m_duType(0) //Ĭ�ϻ���
, m_first(0.0) //��ʼ��Ϊ0.0
, m_second(0.0)
, m_operator(_T("+")) 
, m_coff(1.0) //Ĭ��Ϊ����
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

	CFileDialog dlg(FALSE,_T("txt"),_T("test.txt"));//FALSE��ʾΪ�����Ϊ���Ի��򣬷���Ϊ���򿪡��Ի���
	if(dlg.DoModal() == IDOK)
	{
		CString strFile = dlg.GetPathName();//��ȡ����·��
		CString strEdit1,strEdit2;
		GetDlgItemText(IDC_EDIT1,strEdit1);//��ȡָ��ID�ı༭������
	//	GetDlgItemText(IDC_EDIT2,strEdit2);//ͬ��
		CStdioFile file;
		if(file.Open(strFile,CStdioFile::modeCreate|CStdioFile::modeNoTruncate|CStdioFile::modeWrite))//����/���ļ�
		{
			file.WriteString(strEdit1);//д������
			file.WriteString(_T("\r\n"));//����
		//	file.WriteString(strEdit2);//д������
			file.Close();//�ر�����ļ�
		}
	}
	*/
}

//ʵ�����ݸ���
void ClixeonCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, m_display);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

//��Ϣ��Ӧ�궨��

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


// ClixeonCalculatorDlg ��Ϣ����



void ClixeonCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


//����
void ClixeonCalculatorDlg::OnBnClickedHudu()
{
	m_duType=0;//ϵͳĬ��m_duTypeΪ0 Ϊ���ȼ���
}
//�Ƕ�
void ClixeonCalculatorDlg::OnBnClickedJiaodu()
{
	m_duType=1;
}


//�ڱ༭������ʾ����
void ClixeonCalculatorDlg::UpdateDisplay(double dck)
{
	m_display.Format(_T("%lf"),dck);
	m_display = m_display + "\r\n" + tmp_2;
	UpdateData(false);//���±༭�����m_display
}

//������
void ClixeonCalculatorDlg::Calculate(void)
{//��ǰһ�������뵱ǰ���ݽ������㣬��Ϊ�´εĵ�һ�����������ڱ༭����ʾ��
	switch(m_operator.GetAt(0))
	{  
	case '+': m_first+=m_second;break;
	case '-': m_first-=m_second;break;
	case '*': m_first*=m_second;break;
	case '/':

		if(fabs(m_second)<=0.000001)
		{
			m_display="��������Ϊ0";
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
		m_second = m_second*10 + n;//��Ϊ������������ʱ
	else  
	{ m_second = m_second + n*m_coff; //��ΪС����������
	m_coff *= 0.1;	}

	tmp.Format(_T("%g"),m_second);

	UpdateDisplay(m_second);//���±༭���������ʾ

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
	tmp_2 = "������" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_first);   }
	else
	{ m_second=sqrt(m_second);    
	tmp_2 = "������" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_second);	}
}
//   "1/x"
void ClixeonCalculatorDlg::OnBnClickedButtonReci()
{
	//��ť�������һ�������Ϊ0 ����
	if(fabs(m_second)<0.000001 && fabs(m_first)<0.000001)
	{
		m_display = "��������Ϊ��";
		UpdateData(false);
		return;	
	}
	//��һ�����㲻Ϊ0  ��������ʱ
	if( fabs(m_second)<0.000001)
	{   
		m_first=1.0/m_first;
			tmp_2 =  tmp + "^-1" + '=' ;
	tmp.Format(_T("%g"),m_second);
		UpdateDisplay(m_first);
	}
	else
		//��ť���벻Ϊ0
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

//�ж��Ƿ����ˡ�x^y���������ʵ��
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


// �������������ǻ��Ȼ��ǽǶ�
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
	m_display = "�ݺ������������,��������һ��������";
	UpdateData(false);
	isXY=true;
}

//   "n!"
void ClixeonCalculatorDlg::OnBnClickedNjiecheng()
{
	if((m_second-(int)m_second)>0){
		m_display =_T("������Ĳ���������������������");
		UpdateData(false);//����Ƿ���������������㣬���¿�ʼ
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
	} //�ݹ����
}

void ClixeonCalculatorDlg::OnBnClickedPi()
{
	m_second = m_PI;
	tmp_2 = "��" + tmp + '=' ;
	tmp.Format(_T("%g"),m_second);
	UpdateDisplay(m_PI);
}

void ClixeonCalculatorDlg::OnBnClickedMod()
{
	if((m_second-(int)m_second)>0){
		m_display =_T("������Ĳ���������������������");
		UpdateData(false);
		return;
	}
	else
	{
     tmp += "mod";
	 tmp_2 =  tmp  ;
	 temp = m_second;
	 m_second = 0.0;
	 m_display = "��ģ������,��������һ������.";
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
