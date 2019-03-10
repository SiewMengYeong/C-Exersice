
// moneychangerView.h : interface of the CmoneychangerView class
//

#pragma once

#include "resource.h"


class CmoneychangerView : public CFormView
{
protected: // create from serialization only
	CmoneychangerView();
	DECLARE_DYNCREATE(CmoneychangerView)

public:
	enum{ IDD = IDD_MONEYCHANGER_FORM };

// Attributes
public:
	CmoneychangerDoc* GetDocument() const;

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
	virtual ~CmoneychangerView();
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // debug version in moneychangerView.cpp
inline CmoneychangerDoc* CmoneychangerView::GetDocument() const
   { return reinterpret_cast<CmoneychangerDoc*>(m_pDocument); }
#endif

