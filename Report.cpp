//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Report.h"
#include "DataModul.h"
#include "ReportO.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfReport *fReport;
//---------------------------------------------------------------------------
__fastcall TfReport::TfReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfReport::Button1Click(TObject *Sender)
{
   /* AnsiString sql7 = "select * from oblast";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql7);
	DM->ADOQuery->Active = true;
     	if (DM->ADOQuery->RecordCount > 0) {
		fReportO->ComboBoxZv->Items->Clear();
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			fReportO->ComboBoxZv->Items->Add(DM->ADOQuery->FieldByName("name_obl")->AsString);
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	fReportO->ComboBoxZv->ItemIndex = 0;
	fReportO->ShowModal();  */

}
//---------------------------------------------------------------------------

/*
	AnsiString rep1 = "select skoroch_nazva, name_obl,
	adresa, name_vlasn, tel1 from gospodarstvo,oblast,
	form_vlasn where gospodarstvo.id_obl =
	(select id_obl from oblast where name_obl='";
	rep1+=ComboBoxZv->Text.Trim();
	rep1+="') and gospodarstvo.id_obl=oblast.id_obl and
	gospodarstvo.id_vlasn=form_vlasn.id_vlasn";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(rep1);
	DM->ADOQuery->Active = true;
	DM->frxReport1->LoadFromFile("Ukr_Gospodarstva\galuz.fr3");
	DM->frxReport1->ShowReport();
	*/
//---------------------------------------------------------------------------



void __fastcall TfReport::SpeedButton1Click(TObject *Sender)
{
    AnsiString sql7 = "select * from oblast";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql7);
	DM->ADOQuery->Active = true;
     	if (DM->ADOQuery->RecordCount > 0) {
		fReportO->ComboBoxZv->Items->Clear();
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			fReportO->ComboBoxZv->Items->Add(DM->ADOQuery->FieldByName("name_obl")->AsString);
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	fReportO->ComboBoxZv->ItemIndex = 0;
	fReportO->ShowModal();
}
//---------------------------------------------------------------------------

