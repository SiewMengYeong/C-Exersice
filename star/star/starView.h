
// starView.h : interface of the CstarView class
//

#pragma once


class CstarView : public CView
{
protected: // create from serialization only
	CstarView();
	DECLARE_DYNCREATE(CstarView)

// Attributes
public:
	CstarDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CstarView();
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

#ifndef _DEBUG  // debug version in starView.cpp
inline CstarDoc* CstarView::GetDocument() const
   { return reinterpret_cast<CstarDoc*>(m_pDocument); }
#endif

