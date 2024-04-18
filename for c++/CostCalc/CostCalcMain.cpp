/***************************************************************
 * Name:      CostCalcMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-10-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "CostCalcMain.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
#include "ChoiceDialog.h"
#include "InputDialog.h"
#include "DeleteDialog.h"
#include "SaveDialog.h"
#include "CalcFunc.h"
#include "GenerateDialog.h"
#include "shellapi.h"
//(*InternalHeaders(CostCalcFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
Product Prod;
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

//(*IdInit(CostCalcFrame)
const long CostCalcFrame::ID_PANEL1 = wxNewId();
const long CostCalcFrame::idMenuNewList = wxNewId();
const long CostCalcFrame::idMenuSave = wxNewId();
const long CostCalcFrame::idMenuQuit = wxNewId();
const long CostCalcFrame::idAddChoose = wxNewId();
const long CostCalcFrame::idAddKeyboard = wxNewId();
const long CostCalcFrame::ID_MENUITEM1 = wxNewId();
const long CostCalcFrame::idEditDelete = wxNewId();
const long CostCalcFrame::idSortAmount = wxNewId();
const long CostCalcFrame::idSortProdCost = wxNewId();
const long CostCalcFrame::idEditSort = wxNewId();
const long CostCalcFrame::idGenMinMaxCost = wxNewId();
const long CostCalcFrame::idMenuAbout = wxNewId();
const long CostCalcFrame::idMenuHelp = wxNewId();
const long CostCalcFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CostCalcFrame,wxFrame)
    //(*EventTable(CostCalcFrame)
    //*)
END_EVENT_TABLE()

CostCalcFrame::CostCalcFrame(wxWindow* parent,wxWindowID id)
{
    cin >> Prod;
    //(*Initialize(CostCalcFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1000,600));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(32,72), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuNewList, _("New list"), _("Create new list"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuSave, _("Save"), _("Save list"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem5 = new wxMenu();
    MenuItem6 = new wxMenuItem(MenuItem5, idAddChoose, _("Choose elements"), wxEmptyString, wxITEM_NORMAL);
    MenuItem5->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(MenuItem5, idAddKeyboard, _("Keyboard input"), wxEmptyString, wxITEM_NORMAL);
    MenuItem5->Append(MenuItem7);
    Menu3->Append(ID_MENUITEM1, _("Add"), MenuItem5, wxEmptyString);
    MenuItem8 = new wxMenuItem(Menu3, idEditDelete, _("Delete"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem8);
    MenuItem9 = new wxMenu();
    MenuItem10 = new wxMenuItem(MenuItem9, idSortAmount, _("Sort by amount"), wxEmptyString, wxITEM_NORMAL);
    MenuItem9->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(MenuItem9, idSortProdCost, _("Sort by final cost of 1 item"), wxEmptyString, wxITEM_NORMAL);
    MenuItem9->Append(MenuItem11);
    Menu3->Append(idEditSort, _("Sort"), MenuItem9, wxEmptyString);
    MenuBar1->Append(Menu3, _("Edit"));
    Menu4 = new wxMenu();
    MenuItem13 = new wxMenuItem(Menu4, idGenMinMaxCost, _("Generate by min and max cost"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem13);
    MenuBar1->Append(Menu4, _("Generate"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuItem12 = new wxMenuItem(Menu2, idMenuHelp, _("Help"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem12);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnAbout);
    //*)
    Connect(idMenuHelp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnHelp);
    Connect(idMenuNewList,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnNewList);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnSave);
    Connect(idSortAmount,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnSortAmount);
    Connect(idSortProdCost,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnSortCost);
    Connect(idEditDelete,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnDelete);
    Connect(idAddChoose,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnChoice);
    Connect(idAddKeyboard,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnKeyboard);
    Connect(idGenMinMaxCost,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CostCalcFrame::OnGenMinMax);

    MenuItem4->Enable(false);
    MenuItem6->Enable(false);
    MenuItem7->Enable(false);
    MenuItem8->Enable(false);
    MenuItem10->Enable(false);
    MenuItem11->Enable(false);
    MenuItem13->Enable(false);
}

CostCalcFrame::~CostCalcFrame()
{
    //(*Destroy(CostCalcFrame)
    //*)
}

void CostCalcFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CostCalcFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Program for calculating the cost of laptops \nMade by Rudovich Alexandra";
    wxMessageBox(msg, _("Welcome to CostCalc"));
}

void CostCalcFrame::OnHelp(wxCommandEvent& event)
{
    ShellExecuteA(NULL, NULL, "Guide.pdf", NULL, NULL, 0);
}

wxGrid* grid;

void CostCalcFrame::OnNewList(wxCommandEvent& event)
{
    grid = new wxGrid(this, -1, wxPoint(0,0), wxSize(900, 500));
    grid->CreateGrid(1, 6);

    MenuItem4->Enable(true);
    MenuItem6->Enable(true);
    MenuItem7->Enable(true);
    MenuItem13->Enable(true);

    grid->SetColLabelValue( 0, "Processor" );
    grid->SetColLabelValue( 1, "Videocard" );
    grid->SetColLabelValue( 2, "Storage device" );
    grid->SetColLabelValue( 3, "Material cost" );
    grid->SetColLabelValue( 4, "Product amount" );
    grid->SetColLabelValue( 5, "Final cost of 1 item" );

    grid->AutoSize();
}

void CostCalcFrame::OnSave(wxCommandEvent& event)
{
    SaveDialog dialog(this);
    dialog.ShowModal();
}

void CostCalcFrame::OnSortAmount(wxCommandEvent& event)
{
    Prod.Sort("1");
    int j = 0;
    for(auto i = Prod.list_products.begin(); i != Prod.list_products.end(); i++)
    {
        Info temp = *i;

        grid->SetCellValue( j, 0, temp.name_proc );
        grid->SetCellValue( j, 1, temp.name_videocard );
        grid->SetCellValue( j, 2, temp.name_storage_device );
        grid->SetCellValue( j, 3, to_string(temp.material_cost) );
        grid->SetCellValue( j, 4, to_string(temp.prod_amount) );
        grid->SetCellValue( j, 5, to_string(temp.fin_cost) );
        j++;
    }
    grid->AutoSize();
}

void CostCalcFrame::OnSortCost(wxCommandEvent& event)
{
    Prod.Sort("2");
    int j = 0;
    for(auto i = Prod.list_products.begin(); i != Prod.list_products.end(); i++)
    {
        Info temp = *i;

        grid->SetCellValue( j, 0, temp.name_proc );
        grid->SetCellValue( j, 1, temp.name_videocard );
        grid->SetCellValue( j, 2, temp.name_storage_device );
        grid->SetCellValue( j, 3, to_string(temp.material_cost) );
        grid->SetCellValue( j, 4, to_string(temp.prod_amount) );
        grid->SetCellValue( j, 5, to_string(temp.fin_cost) );
        j++;
    }
    grid->AutoSize();
}

void CostCalcFrame::OnDelete(wxCommandEvent& event)
{
    DeleteDialog dialog(this);
    dialog.ShowModal();
}

void CostCalcFrame::OnChoice(wxCommandEvent& event)
{
    ChoiceDialog dialog(this);
    dialog.ShowModal();
    MenuItem8->Enable(true);
    MenuItem10->Enable(true);
    MenuItem11->Enable(true);
}

void CostCalcFrame::OnKeyboard(wxCommandEvent& event)
{
    InputDialog dialog(this);
    dialog.ShowModal();
    MenuItem8->Enable(true);
    MenuItem10->Enable(true);
    MenuItem11->Enable(true);
}

void CostCalcFrame::OnGenMinMax(wxCommandEvent& event)
{
    GenerateDialog dialog(this);
    dialog.ShowModal();
    MenuItem8->Enable(true);
    MenuItem10->Enable(true);
    MenuItem11->Enable(true);
}
