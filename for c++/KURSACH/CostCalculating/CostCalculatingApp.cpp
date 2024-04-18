/***************************************************************
 * Name:      CostCalculatingApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-10-24
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "CostCalculatingApp.h"
#include "CostCalculatingMain.h"

IMPLEMENT_APP(CostCalculatingApp);

bool CostCalculatingApp::OnInit()
{
    CostCalculatingFrame* frame = new CostCalculatingFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
