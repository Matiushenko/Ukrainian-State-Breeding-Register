//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>

#include "Authorisation.h"
#include "DataModul.h"
#include "Main.h"
#include "Anketa.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAuthorisation *fAuthorisation;
//---------------------------------------------------------------------------
__fastcall TfAuthorisation::TfAuthorisation(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAuthorisation::ButtonEntryClick(TObject *Sender)
{
if(EditLogin->Text==""){
	MessageDlg("Не вірний формат введення!", mtError, TMsgDlgButtons() << mbOK, 0);
	return;}

AnsiString CS,CSNEW;

if(!GetConnectionString(CS)){
	MessageDlg("Помилка авторизації!", mtError, TMsgDlgButtons() << mbOK, 0);
	return;}

DM->ADOConnect->Connected = false;

if(!DM->ADOConnect->Connected){
	CSNEW = ComposeConnectionString(CS,EditLogin->Text,EditPassword->Text);
	DM->ADOConnect->ConnectionString = CSNEW;
try{
	DM->ADOConnect->Connected=true;
	Hide();
	fMain_->Show();

}catch(...){
	MessageDlg("Помилка авторизації!", mtError, TMsgDlgButtons() << mbOK, 0);
	return;
}}
EditLogin->Text="";
EditPassword->Text="";
}

//---------------------------------------------------------------------------

void __fastcall TfAuthorisation::ButtonExitClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------



