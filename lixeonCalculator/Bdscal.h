#pragma once


const int MAXN = 200;

// Bdscal �Ի���

class Bdscal : public CDialog
{
	DECLARE_DYNAMIC(Bdscal)

public:
	Bdscal(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Bdscal();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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

    char Exp[MAXN];         //���ʽ

    int NextB[MAXN];        //ƥ������λ��

    double Ans;             //��ֵ���

    void DelandLower(char *str);        //ɾ�����ַ� ת��ΪСд

    bool Check(char *str,int & len);

    bool CheckCh(const char *str,int pos);  //����ַ�

    bool Is_Num(char c);        //�Ƿ�Ϊ����

    bool Operat(char c);        //�Ƿ�Ϊ�����

    bool CheckError(const char *str,int len);

    bool CrectB(const char *str);       //�������ƥ��

    bool Equal(double a,double b);      //�жϸ��������

    int Prio(double x);             //�������ȼ��ж�

    double hash(char c);            //���ŵ�������ӳ��

    double GetV(const char *str,int st,int ed);     //������ֵ



};
