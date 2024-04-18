/***************************************************************
 * Name:      CostCalculatingMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-10-24
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef COSTCALCULATINGMAIN_H
#define COSTCALCULATINGMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "CostCalculatingApp.h"

class CostCalculatingFrame: public wxFrame
{
    public:
        CostCalculatingFrame(wxFrame *frame, const wxString& title);
        CostCalculatingFrame(const wxString& title);
        ~CostCalculatingFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButtonPress(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // COSTCALCULATINGMAIN_H
