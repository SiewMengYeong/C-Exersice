
// moneychanger.h : main header file for the moneychanger application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CmoneychangerApp:
// See moneychanger.cpp for the implementation of this class
//

class CmoneychangerApp : public CWinAppEx
{
public:
	CmoneychangerApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CmoneychangerApp theApp;
