#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

//(*Headers(SaveDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
//*)

class SaveDialog: public wxDialog
{
	public:

		SaveDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SaveDialog();

		//(*Declarations(SaveDialog)
		wxButton* Cancel;
		wxButton* Okey;
		wxStaticBox* StaticBox1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(SaveDialog)
		static const long ID_STATICBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_OKEY;
		static const long ID_CANCEL;
		//*)

	private:

		//(*Handlers(SaveDialog)
		void OnCancelClick(wxCommandEvent& event);
		void OnOkeyClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
