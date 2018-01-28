// lixeonCalculatorDlg.h : 头文件

#pragma once
#include "afxwin.h"

// ClixeonCalculatorDlg 对话框
class ClixeonCalculatorDlg : public CDialog
{
protected:
	HICON m_hIcon;//获取窗口图标

	afx_msg void OnPaint();	// 生成的消息映射函数

	DECLARE_MESSAGE_MAP() //声明消息响应宏定义

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


public:
	ClixeonCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

	~ClixeonCalculatorDlg(); //析构

	enum { IDD = IDD_lixeonCalculator_DIALOG };// 对话框数据

	int m_duType;  //弧度角度控制

	double m_first; //第一个操作数

	double m_second; //第二个操作数

	CString m_operator; //运算符控制

	double m_coff; //整数小数判断

	CString m_display; //显示保存

	afx_msg void OnBnClickedHudu();    //弧度按钮

	afx_msg void OnBnClickedJiaodu(); //角度按钮

	void UpdateDisplay(double dck); //显示结果

	void Calculate(void);   //计算函数

	afx_msg void OnBnClickedButton0(); //0按钮

	afx_msg void OnBnClickedButton1(); //1按钮

	afx_msg void OnBnClickedButton2(); //2按钮

	afx_msg void OnBnClickedButton3(); //3按钮

	afx_msg void OnBnClickedButton4(); //4按钮

	afx_msg void OnBnClickedButton5(); //5按钮

	afx_msg void OnBnClickedButton6(); //6按钮

	afx_msg void OnBnClickedButton7(); //7按钮

	afx_msg void OnBnClickedButton8(); //8按钮

	afx_msg void OnBnClickedButton9(); //9按钮

	afx_msg void OnBnClickedButtonSign(); //正负标识判断

	afx_msg void OnBnClickedButtonPoint(); //小数点

	afx_msg void OnBnClickedButtonAdd(); //加

	void onButtonN(int n);            //按钮判断

	afx_msg void OnBnClickedButtonMinus();//减

	afx_msg void OnBnClickedButtonMutiply();//乘

	afx_msg void OnBnClickedButtonDiv();//除

	afx_msg void OnBnClickedButtonClear();//清除删除

	afx_msg void OnBnClickedButtonSqrt();//开方

	afx_msg void OnBnClickedButtonReci();//倒数

	afx_msg void OnBnClickedButtonEqual();//等于

	afx_msg void OnBnClickedExp();//指数幂

	afx_msg void OnBnClickedCos();//余弦

	afx_msg void OnBnClickedSin();//正弦

	afx_msg void OnBnClickedLn();//自然对数

	afx_msg void OnBnClickedLog();//常用对数

	afx_msg void OnBnClickedArccos();//反余弦

	afx_msg void OnBnClickedArcsin();//反正弦

	afx_msg void OnBnClickedTan();//正切

	afx_msg void OnBnClickedArctan();//反正切

	afx_msg void OnBnClickedXdey();//幂函数

	afx_msg void OnBnClickedNjiecheng();//阶乘

	void sanjiaoHanshu(void);//判断弧度角度

	double m_PI; //pi值

	bool isXY; //判断是否按下x^y

	bool isMOD; //判断是否按下mod

	double temp;  //临时变量

	void xDEy(void); //计算x^y

	void xMODy(void); //计算取余

	int jiecheng(int n);  //阶乘运算

	afx_msg void OnBnClickedPi(); //pi值

	afx_msg void OnBnClickedMod(); //取模运算

	afx_msg void OnBnClicked3dex(); //2的x

	afx_msg void OnBnClicked2dex(); //平方

	afx_msg void OnBnClickedAbout(); //点击查看作者

	afx_msg void OnEnChangeEdit1();

	afx_msg void OnBnClickedbdscal(); //点击表达式计算

	CEdit m_edit;
};
