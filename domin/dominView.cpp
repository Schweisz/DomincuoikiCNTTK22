
// dominView.cpp : implementation of the CdominView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "domin.h"
#endif

#include "dominDoc.h"
#include "dominView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdominView

IMPLEMENT_DYNCREATE(CdominView, CView)

BEGIN_MESSAGE_MAP(CdominView, CView)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CdominView construction/destruction

CdominView::CdominView() noexcept
{
	// TODO: add construction code here
	banco = CBanco();
}

CdominView::~CdominView()
{
}

BOOL CdominView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CdominView drawing

void CdominView::OnDraw(CDC* /*pDC*/)
{
	CdominDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pdc(this);
	//Omin omin = Omin(50, 50, 100, 100);
	//omin.mo = 1;
	//omin.giatri= -1;
	banco.draw(&pdc);
	// TODO: add draw code for native data here
}


// CdominView diagnostics

#ifdef _DEBUG
void CdominView::AssertValid() const
{
	CView::AssertValid();
}

void CdominView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdominDoc* CdominView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdominDoc)));
	return (CdominDoc*)m_pDocument;
}
#endif //_DEBUG


// CdominView message handlers


void CdominView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	banco.bambanco(&pdc, point);
	CView::OnLButtonUp(nFlags, point);
}
