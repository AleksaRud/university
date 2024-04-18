/***************************************************************
 * Name:      CostCalcApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-10-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "CostCalcApp.h"

//(*AppHeaders
#include "CostCalcMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CostCalcApp);

bool CostCalcApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CostCalcFrame* Frame = new CostCalcFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}
