
// sinwaveView.cpp : implementation of the CsinwaveView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "sinwave.h"
#endif

#include <cmath>
#include "sinwaveDoc.h"
#include "sinwaveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsinwaveView

IMPLEMENT_DYNCREATE(CsinwaveView, CView)

BEGIN_MESSAGE_MAP(CsinwaveView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CsinwaveView construction/destruction

CsinwaveView::CsinwaveView()
{
	// TODO: add construction code here

}

CsinwaveView::~CsinwaveView()
{
}

BOOL CsinwaveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsinwaveView drawing

void CsinwaveView::OnDraw(CDC* pDC)
{
	CsinwaveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int R = 100;
	double pi=3.14159265358979323846;
	
	pDC->MoveTo(0,100);
   
	for (int i=0;i<720;i++)
	{
		double x = i*pi/180;
		pDC->LineTo(i, 100 + sin(x)*-100);
	}

	// TODO: add draw code for native data here
}

void CsinwaveView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsinwaveView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsinwaveView diagnostics

#ifdef _DEBUG
void CsinwaveView::AssertValid() const
{
	CView::AssertValid();
}

void CsinwaveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsinwaveDoc* CsinwaveView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsinwaveDoc)));
	return (CsinwaveDoc*)m_pDocument;
}
#endif //_DEBUG


// CsinwaveView message handlers
