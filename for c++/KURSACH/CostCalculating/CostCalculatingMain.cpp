/***************************************************************
 * Name:      CostCalculatingMain.cpp
 * Purpose:   Code for Application Frame
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

#include "CostCalculatingMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(CostCalculatingFrame, wxFrame)
    EVT_BUTTON(wxID_CLOSE, CostCalculatingFrame::OnButtonPress)
    EVT_CLOSE(CostCalculatingFrame::OnClose)
    EVT_MENU(idMenuQuit, CostCalculatingFrame::OnQuit)
    EVT_MENU(idMenuAbout, CostCalculatingFrame::OnAbout)

END_EVENT_TABLE()

CostCalculatingFrame::CostCalculatingFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

}
CostCalculatingFrame::CostCalculatingFrame(const wxString& title)
    :wxFrame(NULL, wxID_ANY, title)
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(sizer);
    wxButton *button = new wxButton(this, wxID_CLOSE, "Click me");
    sizer->Add(50, 50);
    sizer->Add(button, 0, wxALL, 50);
}

CostCalculatingFrame::~CostCalculatingFrame()
{
}

void CostCalculatingFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void CostCalculatingFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void CostCalculatingFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void CostCalculatingFrame::OnButtonPress(wxCommandEvent &event)
{
    Close(true);
}
