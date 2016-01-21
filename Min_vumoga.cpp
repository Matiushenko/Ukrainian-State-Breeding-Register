//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Min_vumoga.h"
#include "Main.h"
#include "DataModul.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMin_vumoga *fMin_vumoga;
//---------------------------------------------------------------------------
__fastcall TfMin_vumoga::TfMin_vumoga(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfMin_vumoga::ComboBoxDodChange(TObject *Sender)
{
	// Записываем листбокс
	StringGrid->Cols[0]->Clear();
	StringGrid->Cols[1]->Clear();
	StringGrid->Cols[2]->Clear();
	StringGrid->Cols[3]->Clear();
	StringGrid->Cols[4]->Clear();
	StringGrid->Cols[5]->Clear();
	StringGrid->Cols[6]->Clear();
	StringGrid->Cols[7]->Clear();
	AnsiString sql1 ="select LEFT(id_ind, 3)+id_naprjam as m from min_vumoga where LEFT(id_ind, 3)=(select id_dodatok from dodatok where dodatokN='";
	AnsiString sqlc,sss;
	sqlc=ComboBoxDod->Text.Trim();
	sss.Insert(sqlc,0);
	sss.Delete(11,100);
	sql1 += sss.Trim();
	sql1 += "')";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql1);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
	ListBoxDod->Items->Clear();
	DM->ADOQuery->FindFirst();
AnsiString sqls ="select id_ind from min_vumoga where LEFT(id_ind, 3)+id_naprjam='";
sqls+=DM->ADOQuery->FieldByName("m")->AsString;
sqls+="' group by id_ind";
DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqls);
	DM->ADOQueryS->Active = true;
	if (DM->ADOQueryS->RecordCount > 0) {
		ListBoxDod->Items->Clear();
		DM->ADOQueryS->FindFirst();
		for (int i = 1; i <= DM->ADOQueryS->RecordCount; i++) {
AnsiString sqlt = "select * from indeks where id_ind='";
sqlt+=DM->ADOQueryS->FieldByName("id_ind")->AsString;
sqlt+="'";
	DM->ADOQueryT->Active = false;
	DM->ADOQueryT->SQL->Clear();
	DM->ADOQueryT->SQL->Add(sqlt);
	DM->ADOQueryT->Active = true;
			AnsiString list;
			list = DM->ADOQueryT->FieldByName("name_indeks")->AsString;
			ListBoxDod->Items->Add(list);
			if (i < DM->ADOQueryS->RecordCount)
			DM->ADOQueryS->FindNext();
		}  }
	Memo1->Lines->Add(DM->ADOQueryT->FieldByName("name_indeks")->AsString);
	ComboBoxId->Items->Clear();
	ComboBoxId->Items->Add(DM->ADOQueryT->FieldByName("kod_indeks")->AsString);
	ComboBoxId->ItemIndex = 0;
	}


}
//---------------------------------------------------------------------------

void __fastcall TfMin_vumoga::ListBoxDodClick(TObject *Sender)
{
		//значения

	StringGrid->Cols[0]->Clear();
	StringGrid->Cols[1]->Clear();
	StringGrid->Cols[2]->Clear();
	StringGrid->Cols[3]->Clear();
	StringGrid->Cols[4]->Clear();
	StringGrid->Cols[5]->Clear();
	StringGrid->Cols[6]->Clear();
	StringGrid->Cols[7]->Clear();
DM->ADOQuery->FindFirst();
AnsiString sqls ="select * from indeks where name_indeks='";
sqls+=ListBoxDod->Items->Strings[ListBoxDod->ItemIndex];
sqls+="'";
DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqls);
	DM->ADOQueryS->Active = true;
DM->ADOQueryS->FindFirst();
for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
AnsiString sql9 ="select * from min_vumoga where id_ind='";
sql9+=DM->ADOQueryS->FieldByName("id_ind")->AsString;
sql9+="' and LEFT(id_ind, 3)+id_naprjam='";
sql9+=DM->ADOQuery->FieldByName("m")->AsString;
sql9+="'";
	DM->ADOQueryF->Active = false;
	DM->ADOQueryF->SQL->Clear();
	DM->ADOQueryF->SQL->Add(sql9);
	DM->ADOQueryF->Active = true;
	if (DM->ADOQueryF->RecordCount > 0) {
		DM->ADOQueryF->FindFirst();
		for (int i = 1; i <= DM->ADOQueryF->RecordCount; i++) {
		StringGrid->Cells[0][i-1] = DM->ADOQueryF->FieldByName("id_poroda")->AsString;

AnsiString sql7 ="select id_naprjam from min_vumoga where LEFT(id_ind, 3)+id_naprjam='";
sql7+=DM->ADOQuery->FieldByName("m")->AsString;
sql7+="'";
	DM->ADOQueryT->Active = false;
	DM->ADOQueryT->SQL->Clear();
	DM->ADOQueryT->SQL->Add(sql7);
	DM->ADOQueryT->Active = true;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ПЗ")
	StringGrid->Cells[1][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ПР")
	StringGrid->Cells[2][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ППР1")
	StringGrid->Cells[3][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ППР2")
	StringGrid->Cells[4][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="КЗ")
	StringGrid->Cells[5][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ПП")
	StringGrid->Cells[6][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ПБР")
	StringGrid->Cells[7][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
			if (i < DM->ADOQueryF->RecordCount)
			DM->ADOQueryF->FindNext();
		}
	}
if (i < DM->ADOQuery->RecordCount)
DM->ADOQuery->FindNext();
}
	Memo1->Lines->Add(DM->ADOQueryS->FieldByName("name_indeks")->AsString);
	ComboBoxId->Items->Clear();
	ComboBoxId->Items->Add(DM->ADOQueryS->FieldByName("kod_indeks")->AsString);
	ComboBoxId->ItemIndex = 0;
}
//---------------------------------------------------------------------------

