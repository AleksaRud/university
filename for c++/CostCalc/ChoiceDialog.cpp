#include "ChoiceDialog.h"
#include <wx/msgdlg.h>
#include "CalcFunc.h"
#include <wx/grid.h>
//(*InternalHeaders(ChoiceDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
extern Product Prod;
extern wxGrid* grid;
//(*IdInit(ChoiceDialog)
const long ChoiceDialog::ID_OKEY = wxNewId();
const long ChoiceDialog::ID_STATICBOX1 = wxNewId();
const long ChoiceDialog::ID_STATICTEXT1 = wxNewId();
const long ChoiceDialog::ID_STATICBOX2 = wxNewId();
const long ChoiceDialog::ID_STATICBOX3 = wxNewId();
const long ChoiceDialog::ID_CHOICE1 = wxNewId();
const long ChoiceDialog::ID_CHOICE2 = wxNewId();
const long ChoiceDialog::ID_CHOICE3 = wxNewId();
const long ChoiceDialog::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(ChoiceDialog,wxDialog)
	//(*EventTable(ChoiceDialog)
	//*)
END_EVENT_TABLE()

ChoiceDialog::ChoiceDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(ChoiceDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(337,282));
	Okey = new wxButton(this, ID_OKEY, _("Okey"), wxPoint(208,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OKEY"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Micro processor"), wxPoint(8,32), wxSize(320,56), 0, _T("ID_STATICBOX1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Choose from lists"), wxPoint(112,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Videocard"), wxPoint(8,88), wxSize(320,56), 0, _T("ID_STATICBOX2"));
	StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, _("Storage device"), wxPoint(8,144), wxSize(320,56), 0, _T("ID_STATICBOX3"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(16,56), wxSize(304,28), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(16,112), wxSize(304,28), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice3 = new wxChoice(this, ID_CHOICE3, wxPoint(16,168), wxSize(304,28), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	Cancel = new wxButton(this, ID_CANCEL, _("Cancel"), wxPoint(32,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));

	Connect(ID_OKEY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ChoiceDialog::OnOkeyClick);
	Connect(ID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ChoiceDialog::OnCancelClick);
	//*)

	for(auto i = Prod.processor.begin(); i!=Prod.processor.end(); i++)
    {
        Info temp = *i;
        Choice1->Append(_(temp.name_proc));
    }
	for(auto i = Prod.videocard.begin(); i!=Prod.videocard.end(); i++)
    {
        Info temp = *i;
        Choice2->Append(_(temp.name_videocard));
    }
    for(auto i = Prod.storage_device.begin(); i!=Prod.storage_device.end(); i++)
    {
        Info temp = *i;
        Choice3->Append(_(temp.name_storage_device));
    }
}

ChoiceDialog::~ChoiceDialog()
{
	//(*Destroy(ChoiceDialog)
	//*)
}

void ChoiceDialog::OnOkeyClick(wxCommandEvent& event) //Okey
{
    int num = Choice1->GetSelection();
    Prod.ChooseProcessor(num);

    num = Choice2->GetSelection();
    Prod.ChooseVideocard(num);

    num = Choice3->GetSelection();
    Prod.ChooseStorageDevice(num);

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

void ChoiceDialog::OnCancelClick(wxCommandEvent& event) //Cancel
{
    Close();
}
