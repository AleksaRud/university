#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include "InputDialog.h"
#include "CalcFunc.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
//(*InternalHeaders(InputDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
extern Product Prod;
extern wxGrid* grid;
//(*IdInit(InputDialog)
const long InputDialog::ID_STATICTEXT1 = wxNewId();
const long InputDialog::ID_STATICBOX1 = wxNewId();
const long InputDialog::ID_STATICBOX2 = wxNewId();
const long InputDialog::ID_STATICBOX3 = wxNewId();
const long InputDialog::ID_STATICBOX4 = wxNewId();
const long InputDialog::ID_STATICBOX5 = wxNewId();
const long InputDialog::ID_TEXTCTRL1 = wxNewId();
const long InputDialog::ID_TEXTCTRL2 = wxNewId();
const long InputDialog::ID_TEXTCTRL3 = wxNewId();
const long InputDialog::ID_TEXTCTRL4 = wxNewId();
const long InputDialog::ID_TEXTCTRL5 = wxNewId();
const long InputDialog::ID_OKEY = wxNewId();
const long InputDialog::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(InputDialog,wxDialog)
	//(*EventTable(InputDialog)
	//*)
END_EVENT_TABLE()

InputDialog::InputDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(InputDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(337,394));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Input your laptop"), wxPoint(112,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Micro processor"), wxPoint(8,32), wxSize(320,56), 0, _T("ID_STATICBOX1"));
	StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Videocard"), wxPoint(8,88), wxSize(320,56), 0, _T("ID_STATICBOX2"));
	StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, _("Storage device"), wxPoint(8,144), wxSize(320,56), 0, _T("ID_STATICBOX3"));
	StaticBox4 = new wxStaticBox(this, ID_STATICBOX4, _("Material costs"), wxPoint(8,200), wxSize(320,56), 0, _T("ID_STATICBOX4"));
	StaticBox5 = new wxStaticBox(this, ID_STATICBOX5, _("Amount of laptops"), wxPoint(8,256), wxSize(320,56), 0, _T("ID_STATICBOX5"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,56), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(16,112), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(16,168), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(16,224), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(16,280), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	Okey = new wxButton(this, ID_OKEY, _("Okey"), wxPoint(216,336), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OKEY"));
	Cancel = new wxButton(this, ID_CANCEL, _("Cancel"), wxPoint(32,336), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));

	Connect(ID_OKEY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputDialog::OnOkeyClick);
	Connect(ID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputDialog::OnCancelClick);
	//*)
}

InputDialog::~InputDialog()
{
	//(*Destroy(InputDialog)
	//*)
}

void InputDialog::OnOkeyClick(wxCommandEvent& event)//Okey
{
    if(( TextCtrl1->IsEmpty() ) || ( TextCtrl2->IsEmpty() ) || ( TextCtrl3->IsEmpty() ) || ( TextCtrl4->IsEmpty() ) || ( TextCtrl5->IsEmpty() ))
    {
        wxString msg = "All fields must be filled in!";
        wxMessageBox(msg, _("Error"));
    }
    else
    {
        string processor = string( TextCtrl1->GetValue() );
        string videocard = string( TextCtrl2->GetValue() );
        string storage_device = string( TextCtrl3->GetValue() );
        string mat_cost = string( TextCtrl4->GetValue() );
        string amount = string( TextCtrl5->GetValue() );

        bool isOk = true;

        for(int i=0; i<mat_cost.length(); i++)
        {
            if((mat_cost[i] > '9') || (mat_cost[i]<'0'))
            {
                wxString msg = "Incorrect input: Material cost must be number!";
                wxMessageBox(msg, _("Error"));
                isOk = false;
                break;
            }
        }
        for(int i=0; i<amount.length(); i++)
        {
            if((amount[i] > '9') || (amount[i]<'0'))
            {
                wxString msg = "Incorrect input: Amount of laptops must be number!";
                wxMessageBox(msg, _("Error"));
                isOk = false;
                break;
            }
        }
        if(isOk)
        {
            Prod.Add(processor, videocard, storage_device, stoi(mat_cost), stoi(amount));
            Prod.ProdCost();

            int j = 0;
            for(auto i = Prod.list_products.begin(); i != Prod.list_products.end(); i++)
            {
                Info temp = *i;
                if (Prod.size > grid->GetNumberRows() )
                    grid->AppendRows(1);

                grid->SetCellValue( j, 0, temp.name_proc );
                grid->SetCellValue( j, 1, temp.name_videocard );
                grid->SetCellValue( j, 2, temp.name_storage_device );
                grid->SetCellValue( j, 3, to_string(temp.material_cost) );
                grid->SetCellValue( j, 4, to_string(temp.prod_amount) );
                grid->SetCellValue( j, 5, to_string(temp.fin_cost) );
                j++;
            }
            grid->AutoSize();

            Close();
        }
    }
}

void InputDialog::OnCancelClick(wxCommandEvent& event) //Cancel
{
    Close();
}

