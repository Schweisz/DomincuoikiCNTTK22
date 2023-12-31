
// domin.h : main header file for the domin application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CdominApp:
// See domin.cpp for the implementation of this class
//

class CdominApp : public CWinApp
{
public:
	CdominApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CdominApp theApp;
