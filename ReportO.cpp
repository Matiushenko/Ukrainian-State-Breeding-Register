//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReportO.h"
#include "Report.h"
#include "DataModul.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfReportO *fReportO;
//---------------------------------------------------------------------------
__fastcall TfReportO::TfReportO(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfReportO::Button1Click(TObject *Sender)
{

	AnsiString sql8 = "select skoroch_nazva, name_obl, adresa, name_vlasn, tel1 from gospodarstvo,oblast,form_vlasn where gospodarstvo.id_obl =(select id_obl from oblast where name_obl='";
	sql8+="Полтавська";
    //	sql8+=ComboBoxZv->Text.Trim();
	sql8+="') and gospodarstvo.id_obl=oblast.id_obl and gospodarstvo.id_vlasn=form_vlasn.id_vlasn";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql8);
	DM->ADOQuery->Active = true;
	//DM->frxReport1->LoadFromFile("C:\\Ukr_Gospodarstva\galuz.fr3");
	//DM->frxReport1->ShowPreparedReport();
	DM->frxReportObl->ShowReport();
}
//---------------------------------------------------------------------------
