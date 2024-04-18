#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

//(*Headers(InputDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class InputDialog: public wxDialog
{
	public:

		InputDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~InputDialog();

		//(*Declarations(InputDialog)
		wxButton* Cancel;
		wxButton* Okey;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticBox* StaticBox3;
		wxStaticBox* StaticBox4;
		wxStaticBox* StaticBox5;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		//*)

	protected:

		//(*Identifiers(InputDialog)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBOX1;
		static const long ID_STATICBOX2;
		static const long ID_STATICBOX3;
		static const long ID_STATICBOX4;
		static const long ID_STATICBOX5;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_OKEY;
		static const long ID_CANCEL;
		//*)

	private:

		//(*Handlers(InputDialog)
		void OnCancelClick(wxCommandEvent& event);
		void OnOkeyClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
