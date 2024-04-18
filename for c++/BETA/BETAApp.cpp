/***************************************************************
 * Name:      BETAApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-10-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "BETAApp.h"

//(*AppHeaders
#include "BETAMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(BETAApp);

bool BETAApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	BETAFrame* Frame = new BETAFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
