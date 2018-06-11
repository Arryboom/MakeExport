
// makeexportDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

typedef enum
{
	OBJECT_TYPE_unknown,//��֪
	OBJECT_TYPE_namespace,//�����ռ�
	OBJECT_TYPE_class,//��
	OBJECT_TYPE_classfun,//���Ա����
	OBJECT_TYPE_function,//����
	OBJECT_TYPE_variant//����
}OBJECT_TYPE;


typedef struct   objectitem
{

	OBJECT_TYPE type;
	CString	 name;
	XLIB::CXMap<CString,objectitem>	items[4];//����,��һ��Ϊ���� ���ڶ���Ϊpublicitems,protecteditems,,privateitems
	/*
	XLIB::CXMap<CString,objectitem>	publicitems;//����
	XLIB::CXMap<CString,objectitem>	protecteditems;//����
	
	XLIB::CXMap<CString,objectitem>	privateitems;//����
	*/
}OBJECTITEM,*LPOBJECTITEM;


// CmakeexportDlg �Ի���
class CmakeexportDlg : public CDialog
{
// ����
public:
	CmakeexportDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MAKEEXPORT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	XLIB::CXMap<int,EXPORTDATA> m_FunctionMap;
	
	BOOL LoadExport( LPCTSTR lpFilePath );
	CString ShowNormal();
	CString ShowAsDef();
	CString ShowAsSource();

	VOID ParserClass( LPCTSTR lpName );
	VOID ParserVariant( LPCTSTR lpName );
	VOID ParserFunction( LPCTSTR lpName );

	CString m_strTitle;

	OBJECTITEM	m_ObjectList;

	BOOL		m_bRemoveCCall; 
	VOID PrintObjects( LPOBJECTITEM item,CString& strText,LPCTSTR prefix = 0,int itemindex = 0 );
	LPOBJECTITEM ProbeForWriteObject( LPCTSTR name,LPOBJECTITEM parent = 0 ,int itemindex = 0);

	VOID		AddUnParser( LPCTSTR lpname );
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_WndDllPath;
	afx_msg void OnBnClickedOpenfile();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CEdit m_wndOut;
	CButton m_wndCplusplus;
	CButton m_wndnormal;
	CButton m_wnddef;
	CButton m_wndsource;
	CButton m_wndRemovecCall;
	afx_msg void OnBnClickedButton1();
	CButton m_wndByOrdin;
};
