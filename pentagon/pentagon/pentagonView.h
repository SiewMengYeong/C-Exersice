
// pentagonView.h : interface of the CpentagonView class
//

#pragma once


class CpentagonView : public CView
{
protected: // create from serialization only
	CpentagonView();
	DECLARE_DYNCREATE(CpentagonView)

// Attributes
public:
	CpentagonDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CpentagonView();
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

#ifndef _DEBUG  // debug version in pentagonView.cpp
inline CpentagonDoc* CpentagonView::GetDocument() const
   { return reinterpret_cast<CpentagonDoc*>(m_pDocument); }
#endif

