
// recView.cpp : implementation of the CrecView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "rec.h"
#endif

#include "recDoc.h"
#include "recView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrecView

IMPLEMENT_DYNCREATE(CrecView, CView)

BEGIN_MESSAGE_MAP(CrecView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CrecView construction/destruction

CrecView::CrecView()
{
	// TODO: add construction code here

}

CrecView::~CrecView()
{
}

BOOL CrecView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CrecView drawing

void CrecView::OnDraw(CDC* pDC)
{
	CrecDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->MoveTo(100,150);
	pDC->LineTo(100,200);
	pDC->LineTo(250,200);
	pDC->LineTo(250,150);
	pDC->LineTo(100,150);

	pDC->MoveTo(150,100);
	pDC->LineTo(200,100);
	pDC->LineTo(200,250);
	pDC->LineTo(150,250);
	pDC->LineTo(150,100);
}

void CrecView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CrecView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CrecView diagnostics

#ifdef _DEBUG
void CrecView::AssertValid() const
{
	CView::AssertValid();
}

void CrecView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CrecDoc* CrecView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CrecDoc)));
	return (CrecDoc*)m_pDocument;
}
#endif //_DEBUG


// CrecView message handlers
