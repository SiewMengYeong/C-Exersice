
// pentagonView.cpp : implementation of the CpentagonView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "pentagon.h"
#endif

#include <cmath>
#include "pentagonDoc.h"
#include "pentagonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpentagonView

IMPLEMENT_DYNCREATE(CpentagonView, CView)

BEGIN_MESSAGE_MAP(CpentagonView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CpentagonView construction/destruction

CpentagonView::CpentagonView()
{
	// TODO: add construction code here

}

CpentagonView::~CpentagonView()
{
}

BOOL CpentagonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CpentagonView drawing

void CpentagonView::OnDraw(CDC* pDC)
{
	CpentagonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	int R = 50;
	int z = 200;
	pDC->MoveTo( z+R * cos(0.0), z+R * sin(0.0) );
	
	double pi=3.14159265358979323846;

    for (int i=0;i<8;i++)
	{
		double theta = i * 2 * pi / 5;
	    pDC->LineTo( z+ R * cos(theta), z+ R * sin(theta) );
	}

}

void CpentagonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CpentagonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CpentagonView diagnostics

#ifdef _DEBUG
void CpentagonView::AssertValid() const
{
	CView::AssertValid();
}

void CpentagonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CpentagonDoc* CpentagonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpentagonDoc)));
	return (CpentagonDoc*)m_pDocument;
}
#endif //_DEBUG


// CpentagonView message handlers
