
// cirView.cpp : implementation of the CcirView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "cir.h"
#endif

#include "cirDoc.h"
#include "cirView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcirView

IMPLEMENT_DYNCREATE(CcirView, CView)

BEGIN_MESSAGE_MAP(CcirView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CcirView construction/destruction

CcirView::CcirView()
{
	// TODO: add construction code here

}

CcirView::~CcirView()
{
}

BOOL CcirView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CcirView drawing

void CcirView::OnDraw(CDC* pDC)
{
	CcirDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for(int x=200;x>0;x-=10)
	pDC->Ellipse(190-x,190-x,210+x,210+x);
}

void CcirView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcirView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcirView diagnostics

#ifdef _DEBUG
void CcirView::AssertValid() const
{
	CView::AssertValid();
}

void CcirView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcirDoc* CcirView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcirDoc)));
	return (CcirDoc*)m_pDocument;
}
#endif //_DEBUG


// CcirView message handlers
