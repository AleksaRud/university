#ifndef CHOICEDIALOG_H
#define CHOICEDIALOG_H

//(*Headers(ChoiceDialog)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
//*)

class ChoiceDialog: public wxDialog
{
	public:

		ChoiceDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~ChoiceDialog();

		//(*Declarations(ChoiceDialog)
		wxButton* Cancel;
		wxButton* Okey;
		wxChoice* Choice1;
		wxChoice* Choice2;
		wxChoice* Choice3;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticBox* StaticBox3;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(ChoiceDialog)
		static const long ID_OKEY;
		static const long ID_STATICBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICBOX2;
		static const long ID_STATICBOX3;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_CHOICE3;
		static const long ID_CANCEL;
		//*)

	private:

		//(*Handlers(ChoiceDialog)
		void OnOkeyClick(wxCommandEvent& event);
		void OnCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
