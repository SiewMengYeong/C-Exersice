
// cirView.h : interface of the CcirView class
//

#pragma once


class CcirView : public CView
{
protected: // create from serialization only
	CcirView();
	DECLARE_DYNCREATE(CcirView)

// Attributes
public:
	CcirDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CcirView();
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
};

#ifndef _DEBUG  // debug version in cirView.cpp
inline CcirDoc* CcirView::GetDocument() const
   { return reinterpret_cast<CcirDoc*>(m_pDocument); }
#endif

