
// moneychangerView.cpp : implementation of the CmoneychangerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "moneychanger.h"
#endif

#include <string>
#include "moneychangerDoc.h"
#include "moneychangerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmoneychangerView

IMPLEMENT_DYNCREATE(CmoneychangerView, CFormView)

BEGIN_MESSAGE_MAP(CmoneychangerView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CmoneychangerView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CmoneychangerView::OnBnClickedButton2)
END_MESSAGE_MAP()

// CmoneychangerView construction/destruction

CmoneychangerView::CmoneychangerView()
	: CFormView(CmoneychangerView::IDD)
{
	// TODO: add construction code here

}

CmoneychangerView::~CmoneychangerView()
{
}

void CmoneychangerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CmoneychangerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CmoneychangerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CmoneychangerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmoneychangerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmoneychangerView diagnostics

#ifdef _DEBUG
void CmoneychangerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CmoneychangerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CmoneychangerDoc* CmoneychangerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmoneychangerDoc)));
	return (CmoneychangerDoc*)m_pDocument;
}
#endif //_DEBUG


// CmoneychangerView message handlers


void CmoneychangerView::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	double i=atof(str);
	str.Format("%f",i*30);
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CmoneychangerView::OnBnClickedButton2()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	double i=atof(str);
	str.Format("%f",i/30);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
}
