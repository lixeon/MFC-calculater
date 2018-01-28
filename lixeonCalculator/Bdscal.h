#pragma once


const int MAXN = 200;

// Bdscal 对话框

class Bdscal : public CDialog
{
	DECLARE_DYNAMIC(Bdscal)

public:
	Bdscal(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Bdscal();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnEnChangeEdit1();
public:
	CString str;

    bool Cac();

    char Exp[MAXN];         //表达式

    int NextB[MAXN];        //匹配括号位置

    double Ans;             //求值结果

    void DelandLower(char *str);        //删除空字符 转化为小写

    bool Check(char *str,int & len);

    bool CheckCh(const char *str,int pos);  //检查字符

    bool Is_Num(char c);        //是否为数字

    bool Operat(char c);        //是否为运算符

    bool CheckError(const char *str,int len);

    bool CrectB(const char *str);       //检查括号匹配

    bool Equal(double a,double b);      //判断浮点数相等

    int Prio(double x);             //符号优先级判断

    double hash(char c);            //符号到浮点型映射

    double GetV(const char *str,int st,int ed);     //区间求值



};
