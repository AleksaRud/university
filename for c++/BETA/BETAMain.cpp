/***************************************************************
 * Name:      BETAMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-10-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "BETAMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(BETAFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

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

//(*IdInit(BETAFrame)
const long BETAFrame::ID_BUTTON1 = wxNewId();
const long BETAFrame::ID_BUTTON2 = wxNewId();
const long BETAFrame::ID_PANEL1 = wxNewId();
const long BETAFrame::ID_MENUITEM1 = wxNewId();
const long BETAFrame::idMenuAbout = wxNewId();
const long BETAFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BETAFrame,wxFrame)
    //(*EventTable(BETAFrame)
    //*)
END_EVENT_TABLE()

BETAFrame::BETAFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(BETAFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(567,379));
    SetMinSize(wxSize(-1,-1));
    SetMaxSize(wxSize(-1,-1));
    Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxPoint(0,264), wxSize(659,186), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetMinSize(wxSize(0,0));
    Button1->SetMaxSize(wxSize(0,0));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(176,192), wxSize(160,144), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Label"), wxPoint(56,80), wxSize(56,4), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BETAFrame::OnButton1Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BETAFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BETAFrame::OnAbout);
    //*)
}

BETAFrame::~BETAFrame()
{
    //(*Destroy(BETAFrame)
    //*)
}

void BETAFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void BETAFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void BETAFrame::OnButton1Click(wxCommandEvent& event)
{
    wxString msg = "Hi";
    wxMessageBox(msg, _("Hello"));
}
