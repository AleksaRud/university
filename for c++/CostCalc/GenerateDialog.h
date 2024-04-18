#ifndef GENERATEDIALOG_H
#define GENERATEDIALOG_H

//(*Headers(GenerateDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class GenerateDialog: public wxDialog
{
	public:

		GenerateDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~GenerateDialog();

		//(*Declarations(GenerateDialog)
		wxButton* Cancel;
		wxButton* Okey;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(GenerateDialog)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBOX1;
		static const long ID_STATICBOX2;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_OKEY;
		static const long ID_CANCEL;
		//*)

	private:

		//(*Handlers(GenerateDialog)
		void OnOkeyClick(wxCommandEvent& event);
		void OnCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
