
// starView.cpp : implementation of the CstarView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "star.h"
#endif

#include <cmath>
#include "starDoc.h"
#include "starView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CstarView

IMPLEMENT_DYNCREATE(CstarView, CView)

BEGIN_MESSAGE_MAP(CstarView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CstarView construction/destruction

CstarView::CstarView()
{
	// TODO: add construction code here

}

CstarView::~CstarView()
{
}

BOOL CstarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CstarView drawing

void CstarView::OnDraw(CDC* pDC)
{
	CstarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	
	CPen aPen;
	aPen.CreatePen(PS_DOT,1,RGB(0,0,255));
	CPen*pOldPen=pDC->SelectObject(&aPen);
	pDC->Ellipse(100,100,200,200);

	pDC->SelectObject(pOldPen);
	int R = 50;
	int z = 150;
	double pi=3.14159265358979323846;
	double t = pi/4+.15;

	pDC->MoveTo( z+R * cos(t+0.0), z+R * sin(t+0.0) );
	
	
	
    for (int i=2;i<5;i+=2)
	{
		double theta = t+ i * 2 * pi / 5;
	    pDC->LineTo( z+ R * cos(theta), z+ R * sin(theta) );
	}

	for (int i=1;i<6;i+=2)
	{
		double theta =  t+i * 2 * pi / 5;
	    pDC->LineTo( z+ R * cos(theta), z+ R * sin(theta) );
	}
	// TODO: add draw code for native data here
	

}

void CstarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CstarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CstarView diagnostics

#ifdef _DEBUG
void CstarView::AssertValid() const
{
	CView::AssertValid();
}

void CstarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CstarDoc* CstarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CstarDoc)));
	return (CstarDoc*)m_pDocument;
}
#endif //_DEBUG


// CstarView message handlers
