
// waveView.cpp : implementation of the CwaveView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "wave.h"
#endif

#include "waveDoc.h"
#include "waveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CwaveView

IMPLEMENT_DYNCREATE(CwaveView, CView)

BEGIN_MESSAGE_MAP(CwaveView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CwaveView construction/destruction

CwaveView::CwaveView()
{
	// TODO: add construction code here

}

CwaveView::~CwaveView()
{
}

BOOL CwaveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CwaveView drawing

void CwaveView::OnDraw(CDC* pDC)
{
	CwaveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int x=0;x<8;x++)
	{
	pDC->MoveTo(50+x*100,100);
	pDC->LineTo(50+x*100,50);
	pDC->LineTo(100+x*100,50);
	pDC->LineTo(100+x*100,100);
	pDC->LineTo(150+x*100,100);
	}

	// TODO: add draw code for native data here
}

void CwaveView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CwaveView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CwaveView diagnostics

#ifdef _DEBUG
void CwaveView::AssertValid() const
{
	CView::AssertValid();
}

void CwaveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CwaveDoc* CwaveView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwaveDoc)));
	return (CwaveDoc*)m_pDocument;
}
#endif //_DEBUG


// CwaveView message handlers
