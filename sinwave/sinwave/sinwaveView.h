
// sinwaveView.h : interface of the CsinwaveView class
//

#pragma once


class CsinwaveView : public CView
{
protected: // create from serialization only
	CsinwaveView();
	DECLARE_DYNCREATE(CsinwaveView)

// Attributes
public:
	CsinwaveDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CsinwaveView();
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

#ifndef _DEBUG  // debug version in sinwaveView.cpp
inline CsinwaveDoc* CsinwaveView::GetDocument() const
   { return reinterpret_cast<CsinwaveDoc*>(m_pDocument); }
#endif

