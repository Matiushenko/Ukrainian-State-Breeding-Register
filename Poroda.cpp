//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Poroda.h"
#include "Main.h"
#include "DataModul.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfPoroda *fPoroda;
extern AnsiString buf;
//---------------------------------------------------------------------------
__fastcall TfPoroda::TfPoroda(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TfPoroda::ListBoxPrdClick(TObject *Sender)
{
		AnsiString sql1="Select id_poroda From Poroda where name_poroda='";
		sql1+=ListBoxPrd->Items->Strings[ListBoxPrd->ItemIndex];
		sql1+="'";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql1);
		DM->ADOQuery->Active=true;
id_prd->Text=DM->ADOQuery->FieldByName("id_poroda")->AsString;
name_prd->Lines->Clear();
name_prd->Lines->Add(ListBoxPrd->Items->Strings[ListBoxPrd->ItemIndex]);
}
//---------------------------------------------------------------------------


void __fastcall TfPoroda::ComboBoxPrdChange(TObject *Sender)
{
TabSheet1->Caption=ComboBoxPrd->Text.Trim();
AnsiString sql1="Select * From Poroda where id_galuz=(select id_galuz from galuz where name_galuz='";
		sql1+=ComboBoxPrd->Text.Trim();
		sql1+="')";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql1);
		DM->ADOQuery->Active=true;
		if (DM->ADOQuery->RecordCount>0) {
ListBoxPrd->Items->Clear();
DM->ADOQuery->FindFirst();
for (int i=1;i<=DM->ADOQuery->RecordCount; i++) {
AnsiString list;
list=DM->ADOQuery->FieldByName("name_poroda")->AsString;
ListBoxPrd->Items->Add(list);
if (i<DM->ADOQuery->RecordCount)
DM->ADOQuery->FindNext();}}
TabSheet1->Caption=ComboBoxPrd->Text.Trim();
		sql1="Select id_poroda From Poroda where name_poroda='";
		sql1+=ListBoxPrd->Items->Strings[0];
		sql1+="'";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql1);
		DM->ADOQuery->Active=true;
id_prd->Text=DM->ADOQuery->FieldByName("id_poroda")->AsString;
name_prd->Lines->Clear();
name_prd->Lines->Add(ListBoxPrd->Items->Strings[0]);
}
//---------------------------------------------------------------------------

void __fastcall TfPoroda::SpeedButton6Click(TObject *Sender)
{
//exit
Close();
}
//---------------------------------------------------------------------------

void __fastcall TfPoroda::SpeedButton2Click(TObject *Sender)
{
//select
name_prd->Enabled=true;
id_prd->Enabled=true;
id_prd->Text="";
name_prd->Text="";
SpeedButton2->Hide();
SpeedButton3->Hide();
SpeedButton6->Hide();
SpeedButton5->Hide();
SpeedButton1->Show();
SpeedButton4->Show();

}
//---------------------------------------------------------------------------

void __fastcall TfPoroda::SpeedButton1Click(TObject *Sender)
{
//insert
AnsiString SQLQwery,SQLSelect;
if(name_prd->Text=="" || id_prd->Text==""){
Application->MessageBox(L"Поля для вводу не можуть бути порожніми!", L"Помилка", MB_OK);
return;}
if(id_prd->Text>=0 && id_prd->Text<=9){
Application->MessageBox(L"Код породи не може містити цифр!", L"Помилка", MB_OK);
return;}
SQLSelect="SELECT * from Poroda where id_poroda='";
SQLSelect+=id_prd->Text.Trim();
SQLSelect+="' or name_poroda='";
SQLSelect+=name_prd->Text.Trim();
SQLSelect+="'";
DM->ADOQuery->Active=false;
DM->ADOQuery->SQL->Clear();
DM->ADOQuery->SQL->Add(SQLSelect);
DM->ADOQuery->Active=true;
if (DM->ADOQuery->RecordCount>0) {
 Application->MessageBox(L"Порода з таким ідентифікатором або іменем вже існує!", L"Помилка", MB_OK);
 return;
 }
SQLQwery="INSERT into Poroda values ('";
SQLQwery+=id_prd->Text.Trim();
SQLQwery+="','";
SQLQwery+=name_prd->Text.Trim();
SQLQwery+="','";
AnsiString idprd;
idprd="SELECT id_galuz from Galuz where name_galuz='";
idprd+=ComboBoxPrd->Text.Trim();
idprd+="'";
DM->ADOQuery->Active=false;
DM->ADOQuery->SQL->Clear();
DM->ADOQuery->SQL->Add(idprd);
DM->ADOQuery->Active=true;
SQLQwery+=DM->ADOQuery->FieldByName("id_galuz")->AsString;
SQLQwery+="')";
DM->ADOQuery->Active=false;
DM->ADOQuery->SQL->Clear();
DM->ADOQuery->SQL->Add(SQLQwery);
try{
DM->ADOQuery->ExecSQL();
Application->MessageBox(L"Нова порода додана!", L"Успіх", MB_OK);}
catch(...){
Application->MessageBox(L"Невдалось додати нову породу!", L"Помилка", MB_OK);}
AnsiString sql1="Select * From Poroda where id_galuz=(select id_galuz from galuz where name_galuz='";
		sql1+=fPoroda->ComboBoxPrd->Text.Trim();
		sql1+="')";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql1);
		DM->ADOQuery->Active=true;
		if (DM->ADOQuery->RecordCount>0) {
ListBoxPrd->Items->Clear();
DM->ADOQuery->FindFirst();
for (int i=1;i<=DM->ADOQuery->RecordCount; i++) {
AnsiString list;
list=DM->ADOQuery->FieldByName("name_poroda")->AsString;
ListBoxPrd->Items->Add(list);
if (i<DM->ADOQuery->RecordCount)
DM->ADOQuery->FindNext();}}
	  AnsiString sql2="Select id_poroda From Poroda where name_poroda='";
		sql2+=fPoroda->ListBoxPrd->Items->Strings[0];
		sql2+="'";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql2);
		DM->ADOQuery->Active=true;
id_prd->Text=DM->ADOQuery->FieldByName("id_poroda")->AsString;
name_prd->Lines->Clear();
name_prd->Lines->Add(ListBoxPrd->Items->Strings[0]);
SpeedButton1->Hide();
SpeedButton4->Hide();
SpeedButton2->Show();
SpeedButton3->Show();
SpeedButton6->Show();
SpeedButton5->Show();
name_prd->Enabled=false;
id_prd->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TfPoroda::SpeedButton4Click(TObject *Sender)
{
//cancel
name_prd->Enabled=false;
id_prd->Enabled=false;
ComboBoxPrd->ItemIndex=0;
	  AnsiString sql1="Select id_poroda From Poroda where name_poroda='";
		sql1+=fPoroda->ListBoxPrd->Items->Strings[0];
		sql1+="'";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql1);
		DM->ADOQuery->Active=true;
id_prd->Text=DM->ADOQuery->FieldByName("id_poroda")->AsString;
name_prd->Lines->Clear();
name_prd->Lines->Add(ListBoxPrd->Items->Strings[0]);
SpeedButton1->Hide();
SpeedButton4->Hide();
SpeedButton2->Show();
SpeedButton3->Show();
SpeedButton6->Show();
SpeedButton5->Show();

}
//---------------------------------------------------------------------------

void __fastcall TfPoroda::SpeedButton5Click(TObject *Sender)
{
//Delete
AnsiString SQLDelete,SQLSelect;
SQLDelete="Delete from Poroda where id_poroda='";
SQLDelete+=id_prd->Text.Trim();
SQLDelete+="'";
DM->ADOQuery->Active=false;
DM->ADOQuery->SQL->Clear();
DM->ADOQuery->SQL->Add(SQLDelete);
try{
DM->ADOQuery->ExecSQL();
Application->MessageBox(L"Порода видалена!", L"Успіх", MB_OK);}
catch(...){
Application->MessageBox(L"Не вдалося видалити породу!", L"Помилка", MB_OK);}

AnsiString sql1="Select * From Poroda where id_galuz=(select id_galuz from galuz where name_galuz='";
		sql1+=fPoroda->ComboBoxPrd->Text.Trim();
		sql1+="')";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql1);
		DM->ADOQuery->Active=true;
		if (DM->ADOQuery->RecordCount>0) {
fPoroda->ListBoxPrd->Items->Clear();
DM->ADOQuery->FindFirst();
for (int i=1;i<=DM->ADOQuery->RecordCount; i++) {
AnsiString list;
list=DM->ADOQuery->FieldByName("name_poroda")->AsString;
fPoroda->ListBoxPrd->Items->Add(list);
if (i<DM->ADOQuery->RecordCount)
DM->ADOQuery->FindNext();}}
}
//---------------------------------------------------------------------------

void __fastcall TfPoroda::SpeedButton3Click(TObject *Sender)
{
//select update
name_prd->Enabled=true;
id_prd->Enabled=true;
SpeedButton2->Hide();
SpeedButton3->Hide();
SpeedButton6->Hide();
SpeedButton5->Hide();
SpeedButton1->Hide();
SpeedButton4->Show();
SaveUpdate->Show();
buf=id_prd->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfPoroda::SaveUpdateClick(TObject *Sender)
{
//update
AnsiString SQLQwery,SQLSelect;
if(name_prd->Text=="" || id_prd->Text==""){
Application->MessageBox(L"Поля для вводу не можуть бути порожніми!", L"Помилка", MB_OK);
return;}
if(id_prd->Text>=0 && id_prd->Text<=9){
Application->MessageBox(L"Код породи не може містити цифр!", L"Помилка", MB_OK);
return;}
SQLSelect="SELECT * from min_vumoga where id_poroda='";
SQLSelect+=id_prd->Text.Trim();
SQLSelect+="'";
DM->ADOQuery->Active=false;
DM->ADOQuery->SQL->Clear();
DM->ADOQuery->SQL->Add(SQLSelect);
DM->ADOQuery->Active=true;
if (DM->ADOQuery->RecordCount>0) {
 Application->MessageBox(L"Неможливо змінити породу, яка вже використовується!", L"Помилка", MB_OK);
 return;
 }

SQLQwery="Update Poroda set id_poroda='";
SQLQwery+=id_prd->Text.Trim();
SQLQwery+="', name_poroda='";
SQLQwery+=name_prd->Text.Trim();
SQLQwery+="', id_galuz='";
AnsiString idprd;
idprd="SELECT id_galuz from Galuz where name_galuz='";
idprd+=ComboBoxPrd->Text.Trim();
idprd+="'";
DM->ADOQuery->Active=false;
DM->ADOQuery->SQL->Clear();
DM->ADOQuery->SQL->Add(idprd);
DM->ADOQuery->Active=true;
SQLQwery+=DM->ADOQuery->FieldByName("id_galuz")->AsString;
SQLQwery+="' where id_poroda='";
SQLQwery+=buf;
SQLQwery+="';";
DM->ADOQuery->Active=false;
DM->ADOQuery->SQL->Clear();
DM->ADOQuery->SQL->Add(SQLQwery);
try{
DM->ADOQuery->ExecSQL();
Application->MessageBox(L"Порода змінена!", L"Успіх", MB_OK);}
catch(...){
Application->MessageBox(L"Невдалось змінити породу!", L"Помилка", MB_OK);}
AnsiString sql1="Select * From Poroda where id_galuz=(select id_galuz from galuz where name_galuz='";
		sql1+=fPoroda->ComboBoxPrd->Text.Trim();
		sql1+="')";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql1);
		DM->ADOQuery->Active=true;
		if (DM->ADOQuery->RecordCount>0) {
ListBoxPrd->Items->Clear();
DM->ADOQuery->FindFirst();
for (int i=1;i<=DM->ADOQuery->RecordCount; i++) {
AnsiString list;
list=DM->ADOQuery->FieldByName("name_poroda")->AsString;
ListBoxPrd->Items->Add(list);
if (i<DM->ADOQuery->RecordCount)
DM->ADOQuery->FindNext();}}
	  AnsiString sql2="Select id_poroda From Poroda where name_poroda='";
		sql2+=fPoroda->ListBoxPrd->Items->Strings[0];
		sql2+="'";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql2);
		DM->ADOQuery->Active=true;
id_prd->Text=DM->ADOQuery->FieldByName("id_poroda")->AsString;
name_prd->Lines->Clear();
name_prd->Lines->Add(ListBoxPrd->Items->Strings[0]);
SaveUpdate->Hide();
SpeedButton4->Hide();
SpeedButton2->Show();
SpeedButton3->Show();
SpeedButton6->Show();
SpeedButton5->Show();
name_prd->Enabled=false;
id_prd->Enabled=false;
}
//---------------------------------------------------------------------------

