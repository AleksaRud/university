#include "GenerateDialog.h"
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include "CalcFunc.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
//(*InternalHeaders(GenerateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
extern Product Prod;
extern wxGrid* grid;
//(*IdInit(GenerateDialog)
const long GenerateDialog::ID_STATICTEXT1 = wxNewId();
const long GenerateDialog::ID_STATICBOX1 = wxNewId();
const long GenerateDialog::ID_STATICBOX2 = wxNewId();
const long GenerateDialog::ID_TEXTCTRL1 = wxNewId();
const long GenerateDialog::ID_TEXTCTRL2 = wxNewId();
const long GenerateDialog::ID_OKEY = wxNewId();
const long GenerateDialog::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(GenerateDialog,wxDialog)
	//(*EventTable(GenerateDialog)
	//*)
END_EVENT_TABLE()

GenerateDialog::GenerateDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(GenerateDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(337,228));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Input min and cost of laptop"), wxPoint(80,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Minimal cost"), wxPoint(8,32), wxSize(320,56), 0, _T("ID_STATICBOX1"));
	StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Maximum cost"), wxPoint(8,88), wxSize(320,56), 0, _T("ID_STATICBOX2"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxPoint(16,56), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxPoint(16,112), wxSize(304,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Okey = new wxButton(this, ID_OKEY, _("Okey"), wxPoint(192,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OKEY"));
	Cancel = new wxButton(this, ID_CANCEL, _("Cancel"), wxPoint(48,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));

	Connect(ID_OKEY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GenerateDialog::OnOkeyClick);
	Connect(ID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GenerateDialog::OnCancelClick);
	//*)
}

GenerateDialog::~GenerateDialog()
{
	//(*Destroy(GenerateDialog)
	//*)
}


void GenerateDialog::OnOkeyClick(wxCommandEvent& event) //Okey
{
    if(( TextCtrl1->IsEmpty() ) || ( TextCtrl2->IsEmpty() ) )
    {
        wxString msg = "All fields must be filled in!";
        wxMessageBox(msg, _("Error"));
    }
    else
    {
        string min_cost = string( TextCtrl1->GetValue() );
        string max_cost = string( TextCtrl2->GetValue() );

        bool isOk = true;

        for(int i=0; i<min_cost.length(); i++)
        {
            if((min_cost[i] > '9') || (min_cost[i]<'0'))
            {
                wxString msg = "Incorrect input: Material cost must be number!";
                wxMessageBox(msg, _("Error"));
                isOk = false;
                break;
            }
        }
        for(int i=0; i<max_cost.length(); i++)
        {
            if((max_cost[i] > '9') || (max_cost[i]<'0'))
            {
                wxString msg = "Incorrect input: Amount of laptops must be number!";
                wxMessageBox(msg, _("Error"));
                isOk = false;
                break;
            }
        }
        if(isOk)
        {
            for(int i = 0; i < Prod.prsize; i++)
            {
                for(int j = 0; j < Prod.vcsize; j++)
                {
                    for(int k = 0; k < Prod.sdsize; k++)
                    {
                        Prod.ChooseProcessor(i);
                        Prod.ChooseVideocard(j);
                        Prod.ChooseStorageDevice(k);
                    }
                }
            }
            Prod.ProdCost();

            int j = 0;
            for(auto i = Prod.list_products.begin(); i != Prod.list_products.end(); i++)
            {
                Info temp = *i;
                if ( (temp.fin_cost > stoi(max_cost)) || (temp.fin_cost < stoi(min_cost)) )
                {
                    Prod.Delete(j);
                    j--;
                }
                j++;
            }

            j = 0;
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


void GenerateDialog::OnCancelClick(wxCommandEvent& event) //Cancel
{
    Close();
}
