#pragma once


// About �Ի���

class About : public CDialog
{
	DECLARE_DYNAMIC(About)

public:
	About(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~About();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
