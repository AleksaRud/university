/***************************************************************
 * Name:      BETAMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-10-27
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef BETAMAIN_H
#define BETAMAIN_H

//(*Headers(BETAFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
//*)

class BETAFrame: public wxFrame
{
    public:

        BETAFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~BETAFrame();

    private:

        //(*Handlers(BETAFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(BETAFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(BETAFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BETAMAIN_H
