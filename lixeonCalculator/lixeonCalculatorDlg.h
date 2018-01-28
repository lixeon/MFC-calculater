// lixeonCalculatorDlg.h : ͷ�ļ�

#pragma once
#include "afxwin.h"

// ClixeonCalculatorDlg �Ի���
class ClixeonCalculatorDlg : public CDialog
{
protected:
	HICON m_hIcon;//��ȡ����ͼ��

	afx_msg void OnPaint();	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP() //������Ϣ��Ӧ�궨��

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


public:
	ClixeonCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

	~ClixeonCalculatorDlg(); //����

	enum { IDD = IDD_lixeonCalculator_DIALOG };// �Ի�������

	int m_duType;  //���ȽǶȿ���

	double m_first; //��һ��������

	double m_second; //�ڶ���������

	CString m_operator; //���������

	double m_coff; //����С���ж�

	CString m_display; //��ʾ����

	afx_msg void OnBnClickedHudu();    //���Ȱ�ť

	afx_msg void OnBnClickedJiaodu(); //�ǶȰ�ť

	void UpdateDisplay(double dck); //��ʾ���

	void Calculate(void);   //���㺯��

	afx_msg void OnBnClickedButton0(); //0��ť

	afx_msg void OnBnClickedButton1(); //1��ť

	afx_msg void OnBnClickedButton2(); //2��ť

	afx_msg void OnBnClickedButton3(); //3��ť

	afx_msg void OnBnClickedButton4(); //4��ť

	afx_msg void OnBnClickedButton5(); //5��ť

	afx_msg void OnBnClickedButton6(); //6��ť

	afx_msg void OnBnClickedButton7(); //7��ť

	afx_msg void OnBnClickedButton8(); //8��ť

	afx_msg void OnBnClickedButton9(); //9��ť

	afx_msg void OnBnClickedButtonSign(); //������ʶ�ж�

	afx_msg void OnBnClickedButtonPoint(); //С����

	afx_msg void OnBnClickedButtonAdd(); //��

	void onButtonN(int n);            //��ť�ж�

	afx_msg void OnBnClickedButtonMinus();//��

	afx_msg void OnBnClickedButtonMutiply();//��

	afx_msg void OnBnClickedButtonDiv();//��

	afx_msg void OnBnClickedButtonClear();//���ɾ��

	afx_msg void OnBnClickedButtonSqrt();//����

	afx_msg void OnBnClickedButtonReci();//����

	afx_msg void OnBnClickedButtonEqual();//����

	afx_msg void OnBnClickedExp();//ָ����

	afx_msg void OnBnClickedCos();//����

	afx_msg void OnBnClickedSin();//����

	afx_msg void OnBnClickedLn();//��Ȼ����

	afx_msg void OnBnClickedLog();//���ö���

	afx_msg void OnBnClickedArccos();//������

	afx_msg void OnBnClickedArcsin();//������

	afx_msg void OnBnClickedTan();//����

	afx_msg void OnBnClickedArctan();//������

	afx_msg void OnBnClickedXdey();//�ݺ���

	afx_msg void OnBnClickedNjiecheng();//�׳�

	void sanjiaoHanshu(void);//�жϻ��ȽǶ�

	double m_PI; //piֵ

	bool isXY; //�ж��Ƿ���x^y

	bool isMOD; //�ж��Ƿ���mod

	double temp;  //��ʱ����

	void xDEy(void); //����x^y

	void xMODy(void); //����ȡ��

	int jiecheng(int n);  //�׳�����

	afx_msg void OnBnClickedPi(); //piֵ

	afx_msg void OnBnClickedMod(); //ȡģ����

	afx_msg void OnBnClicked3dex(); //2��x

	afx_msg void OnBnClicked2dex(); //ƽ��

	afx_msg void OnBnClickedAbout(); //����鿴����

	afx_msg void OnEnChangeEdit1();

	afx_msg void OnBnClickedbdscal(); //������ʽ����

	CEdit m_edit;
};
