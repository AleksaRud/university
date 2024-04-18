#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include "SaveDialog.h"
#include "CalcFunc.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
//(*InternalHeaders(SaveDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
extern Product Prod;
extern wxGrid* grid;
//(*IdInit(SaveDialog)
const long SaveDialog::ID_STATICBOX1 = wxNewId();
const long SaveDialog::ID_TEXTCTRL1 = wxNewId();
const long SaveDialog::ID_OKEY = wxNewId();
const long SaveDialog::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(SaveDialog,wxDialog)
	//(*EventTable(SaveDialog)
	//*)
END_EVENT_TABLE()

SaveDialog::SaveDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SaveDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(337,138));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("File\'s name"), wxPoint(8,8), wxSize(320,56), 0, _T("ID_STATICBOX1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("DataBase"), wxPoint(16,32), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Okey = new wxButton(this, ID_OKEY, _("Okey"), wxPoint(208,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OKEY"));
	Cancel = new wxButton(this, ID_CANCEL, _("Cancel"), wxPoint(40,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));

	Connect(ID_OKEY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SaveDialog::OnOkeyClick);
	Connect(ID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SaveDialog::OnCancelClick);
	//*)
}

SaveDialog::~SaveDialog()
{
	//(*Destroy(SaveDialog)
	//*)
}

void SaveDialog::OnOkeyClick(wxCommandEvent& event) //Okey
{
    if( TextCtrl1->IsEmpty() )
    {
        wxString msg = "All fields must be filled in!";
        wxMessageBox(msg, _("Error"));
    }
    else
    {
        string file_name = string( TextCtrl1->GetValue() );

        bool isOk = true;

        for(int i=0; i<file_name.length(); i++)
        {
            if( (file_name[i] == '\\') || (file_name[i] == '/') || (file_name[i] == ':') ||
                (file_name[i] == '*') || (file_name[i] == '?') || (file_name[i] == '"') ||
                (file_name[i] == '<') || (file_name[i] == '>') || (file_name[i] == '|') )
            {
                wxString msg = "Incorrect input: File's name mustn't contain such symbols \n \\ / : * ? \" < > |";
                wxMessageBox(msg, _("Error"));
                isOk = false;
                break;
            }
        }

        if(isOk)
        {
            Prod.Save(file_name);

            wxString msg = "List was saved on folder with programm";
            wxMessageBox(msg, _("Save"));

            Close();
        }
    }
}

void SaveDialog::OnCancelClick(wxCommandEvent& event) //Cancel
{
    Close();
}


