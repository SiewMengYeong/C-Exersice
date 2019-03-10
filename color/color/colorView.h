
// colorView.h : interface of the CcolorView class
//

#pragma once


class CcolorView : public CView
{
protected: // create from serialization only
	CcolorView();
	DECLARE_DYNCREATE(CcolorView)

// Attributes
public:
	CcolorDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CcolorView();
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

#ifndef _DEBUG  // debug version in colorView.cpp
inline CcolorDoc* CcolorView::GetDocument() const
   { return reinterpret_cast<CcolorDoc*>(m_pDocument); }
#endif

