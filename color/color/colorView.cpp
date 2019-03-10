
// colorView.cpp : implementation of the CcolorView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "color.h"
#endif

#include "colorDoc.h"
#include "colorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcolorView

IMPLEMENT_DYNCREATE(CcolorView, CView)

BEGIN_MESSAGE_MAP(CcolorView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CcolorView construction/destruction

CcolorView::CcolorView()
{
	// TODO: add construction code here

}

CcolorView::~CcolorView()
{
}

BOOL CcolorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CcolorView drawing

void CcolorView::OnDraw(CDC* pDC)
{
	CcolorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBrush abrush1;
	CBrush abrush2;

	for (int i=0;i<16;i++)
	{
		
	abrush1.CreateSolidBrush(RGB(0,0+i*16,255));
	CBrush*pOldbrush1=pDC->SelectObject(&abrush1);
	pDC->Rectangle(5+15*i,5,15+15*i,15);
	abrush1.DeleteObject();
	pDC->SelectObject(pOldbrush1);

			for(int j=0;j<16;j++)
			{

			abrush2.CreateSolidBrush(RGB(0+j*16,0+i*16,255));
			CBrush*pOldbrush2=pDC->SelectObject(&abrush2);
			pDC->Rectangle(5+15*i,5+15*j,15+15*i,15+15*j);
			abrush2.DeleteObject();
			pDC->SelectObject(pOldbrush2);
	
		}
	}

	// TODO: add draw code for native data here
}

void CcolorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcolorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcolorView diagnostics

#ifdef _DEBUG
void CcolorView::AssertValid() const
{
	CView::AssertValid();
}

void CcolorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcolorDoc* CcolorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcolorDoc)));
	return (CcolorDoc*)m_pDocument;
}
#endif //_DEBUG


// CcolorView message handlers
