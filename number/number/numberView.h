
// numberView.h : interface of the CnumberView class
//

#pragma once

#include "resource.h"


class CnumberView : public CFormView
{
protected: // create from serialization only
	CnumberView();
	DECLARE_DYNCREATE(CnumberView)

public:
	enum{ IDD = IDD_NUMBER_FORM };

// Attributes
public:
	CnumberDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CnumberView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // debug version in numberView.cpp
inline CnumberDoc* CnumberView::GetDocument() const
   { return reinterpret_cast<CnumberDoc*>(m_pDocument); }
#endif

