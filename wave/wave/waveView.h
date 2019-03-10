
// waveView.h : interface of the CwaveView class
//

#pragma once


class CwaveView : public CView
{
protected: // create from serialization only
	CwaveView();
	DECLARE_DYNCREATE(CwaveView)

// Attributes
public:
	CwaveDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CwaveView();
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

#ifndef _DEBUG  // debug version in waveView.cpp
inline CwaveDoc* CwaveView::GetDocument() const
   { return reinterpret_cast<CwaveDoc*>(m_pDocument); }
#endif

