
// numberView.cpp : implementation of the CnumberView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "number.h"
#endif

#include "numberDoc.h"
#include "numberView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CnumberView

IMPLEMENT_DYNCREATE(CnumberView, CFormView)

BEGIN_MESSAGE_MAP(CnumberView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_EN_CHANGE(IDC_EDIT1, &CnumberView::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CnumberView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CnumberView construction/destruction

CnumberView::CnumberView()
	: CFormView(CnumberView::IDD)
{
	// TODO: add construction code here

}

CnumberView::~CnumberView()
{
}

void CnumberView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CnumberView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CnumberView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CnumberView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CnumberView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CnumberView diagnostics

#ifdef _DEBUG
void CnumberView::AssertValid() const
{
	CFormView::AssertValid();
}

void CnumberView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CnumberDoc* CnumberView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CnumberDoc)));
	return (CnumberDoc*)m_pDocument;
}
#endif //_DEBUG


// CnumberView message handlers


void CnumberView::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CnumberView::OnBnClickedButton1()
{
	CString str;
	CString str2;
	CString LineNo;
	int nline=1;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	str2.Format(_T("%02d"),nline);
    for (int i=0;i<str.GetLength();i++)
	{
		str2=str2+str[i];
		if(str[i]==10&&i!=str.GetLength())
		{
			LineNo.Format(_TEXT("%02d",++nline));
			str2=str2+LineNo;
		}
	}
		
	GetDlgItem(IDC_EDIT2)->SetWindowText(str2);
}
