/***************************************************************
 * Name:      CostCalcMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-10-27
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef COSTCALCMAIN_H
#define COSTCALCMAIN_H

//(*Headers(CostCalcFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
//*)

class CostCalcFrame: public wxFrame
{
    public:

        CostCalcFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CostCalcFrame();

    private:

        //(*Handlers(CostCalcFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnHelp(wxCommandEvent& event);
        void OnNewList(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnDelete(wxCommandEvent& event);
        void OnSortAmount(wxCommandEvent& event);
        void OnSortCost(wxCommandEvent& event);
        void OnChoice(wxCommandEvent& event);
        void OnKeyboard(wxCommandEvent& event);
        void OnGenMinMax(wxCommandEvent& event);
        //*)

        //(*Identifiers(CostCalcFrame)
        static const long ID_PANEL1;
        static const long idMenuNewList;
        static const long idMenuSave;
        static const long idMenuQuit;
        static const long idAddChoose;
        static const long idAddKeyboard;
        static const long ID_MENUITEM1;
        static const long idEditDelete;
        static const long idSortAmount;
        static const long idSortProdCost;
        static const long idEditSort;
        static const long idGenMinMaxCost;
        static const long idMenuAbout;
        static const long idMenuHelp;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(CostCalcFrame)
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenu* MenuItem5;
        wxMenu* MenuItem9;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItem12;
        wxMenuItem* MenuItem13;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)


        DECLARE_EVENT_TABLE()
};

#endif // COSTCALCMAIN_H
