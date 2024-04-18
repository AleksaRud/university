#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

//(*Headers(DeleteDialog)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
//*)

class DeleteDialog: public wxDialog
{
	public:

		DeleteDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DeleteDialog();

		//(*Declarations(DeleteDialog)
		wxButton* Cancel;
		wxButton* Okey;
		wxChoice* Choice1;
		wxStaticBox* StaticBox1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(DeleteDialog)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBOX1;
		static const long ID_CHOICE1;
		static const long ID_OKEY;
		static const long ID_CANCEL;
		//*)

	private:

		//(*Handlers(DeleteDialog)
		void OnOkeyClick(wxCommandEvent& event);
		void OnCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
