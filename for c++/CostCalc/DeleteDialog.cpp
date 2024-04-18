
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include "DeleteDialog.h"
#include "CalcFunc.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
//(*InternalHeaders(DeleteDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
extern Product Prod;
extern wxGrid* grid;
//(*IdInit(DeleteDialog)
const long DeleteDialog::ID_STATICTEXT1 = wxNewId();
const long DeleteDialog::ID_STATICBOX1 = wxNewId();
const long DeleteDialog::ID_CHOICE1 = wxNewId();
const long DeleteDialog::ID_OKEY = wxNewId();
const long DeleteDialog::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(DeleteDialog,wxDialog)
	//(*EventTable(DeleteDialog)
	//*)
END_EVENT_TABLE()

DeleteDialog::DeleteDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DeleteDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(337,188));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Choose number of laptop which you want to delete"), wxPoint(40,8), wxSize(248,40), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Laptop\'s number"), wxPoint(8,48), wxSize(320,56), 0, _T("ID_STATICBOX1"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(16,72), wxSize(304,28), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Okey = new wxButton(this, ID_OKEY, _("Okey"), wxPoint(208,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OKEY"));
	Cancel = new wxButton(this, ID_CANCEL, _("Cancel"), wxPoint(40,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));

	Connect(ID_OKEY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeleteDialog::OnOkeyClick);
	Connect(ID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeleteDialog::OnCancelClick);
	//*)

	for(int i = 1; i<=Prod.size; i++)
    {
        Choice1->Append(_(to_string(i)));
    }
}

DeleteDialog::~DeleteDialog()
{
	//(*Destroy(DeleteDialog)
	//*)
}


void DeleteDialog::OnOkeyClick(wxCommandEvent& event) //Okey
{
    Prod.Delete( Choice1->GetSelection() );
    grid->DeleteRows();

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

void DeleteDialog::OnCancelClick(wxCommandEvent& event) //Cancel
{
    Close();
}
