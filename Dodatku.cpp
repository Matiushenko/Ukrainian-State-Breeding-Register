//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dodatku.h"
#include "Main.h"
#include "DataModul.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfDodatku *fDodatku;
//---------------------------------------------------------------------------
__fastcall TfDodatku::TfDodatku(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

 int selIndex = -1;






void __fastcall TfDodatku::StringGridClick(TObject *Sender)
{
/*
TGridRect myRect;
myRect.Left = 320;
myRect.Top = 1;
myRect.Right = 1;
myRect.Bottom = 2;
StringGrid->Selection = myRect;   */


}
//---------------------------------------------------------------------------







//---------------------------------------------------------------------------


void __fastcall TfDodatku::Button1Click(TObject *Sender)
{
/*DM->ADOTest->Active=false;
DM->ADOTest->Parameters->ParamByName("@PZ020101")->Value=StrToFloat(Edit1->Text);
DM->ADOTest->ExecProc();
//DM->ADOTest->Active=true;
if(DM->ADOTest->Parameters->ParamByName("@RETURN_VALUE")->Value)
Edit2->Text="Hello";
else
Edit2->Text="buy guy"; */
}
//---------------------------------------------------------------------------

void __fastcall TfDodatku::FormCreate(TObject *Sender)
{
// string grid
StringGridPokazn->ColWidths[0]=490;
StringGridPokazn->ColWidths[1]=38;
StringGridPokazn->ColWidths[2]=91;
StringGridPokazn->Cells[0][0]="Назва показника";
StringGridPokazn->Cells[1][0]="Код";
StringGridPokazn->Cells[2][0]="Значення";
int x=0;
 AnsiString sql = "Select * From indeks where id_dodatok = 'D05'";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		StringGridPokazn->RowCount = DM->ADOQuery->RecordCount;
		StringGridPokazn->RowCount++;
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			StringGridPokazn->Cells[0][i] = DM->ADOQuery->FieldByName("name_indeks")->AsString;
			//StringGridPokazn->Cells[1][i] = DM->ADOQuery->FieldByName("kod_indeks")->AsString;
				if (i < DM->ADOQuery->RecordCount)   {
				DM->ADOQuery->FindNext();
				x++;  }
		}
		StringGridPokazn->Cells[1][1] = "010";
		StringGridPokazn->Cells[1][2] = "";
		StringGridPokazn->Cells[1][3] = "020";
		StringGridPokazn->Cells[1][4] = "030";
		StringGridPokazn->Cells[1][5] = "040";
		StringGridPokazn->Cells[1][6] = "050";
		StringGridPokazn->Cells[1][7] = "060";
		StringGridPokazn->Cells[1][8] = "";
		StringGridPokazn->Cells[1][9] = "070";
		StringGridPokazn->Cells[1][10] = "080";
		StringGridPokazn->Cells[1][11] = "090";
		StringGridPokazn->Cells[1][12] = "100";
		StringGridPokazn->Cells[1][13] = "";
		StringGridPokazn->Cells[1][14] = "110";
		StringGridPokazn->Cells[1][15] = "120";
		StringGridPokazn->Cells[1][16] = "130";
		StringGridPokazn->Cells[1][17] = "";
		StringGridPokazn->Cells[1][18] = "";
		StringGridPokazn->Cells[1][19] = "140";
		StringGridPokazn->Cells[1][20] = "150";
		StringGridPokazn->Cells[1][21] = "160";

	}
 for (int i = 0; i <= x; i++) {
  AnsiString sql1 = "Select * From pokaznuk p, indeks i where kod_indeks='";
  sql1+= StringGridPokazn->Cells[1][i];
  sql1+= "' and id_dodatok='D05' and i.id_ind=p.id_ind";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql1);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
	StringGridPokazn->Cells[2][i] = DM->ADOQuery->FieldByName("fakt_znach")->AsString;
										  }  }
		StringGridPokazn->Cells[2][1] = "229";
		StringGridPokazn->Cells[2][2] = "";
		StringGridPokazn->Cells[2][3] = "12";
		StringGridPokazn->Cells[2][4] = "10";
		StringGridPokazn->Cells[2][5] = "160";
		StringGridPokazn->Cells[2][6] = "90";
		StringGridPokazn->Cells[2][7] = "70";
		StringGridPokazn->Cells[2][8] = "";
		StringGridPokazn->Cells[2][9] = "21";
		StringGridPokazn->Cells[2][10] = "19";
		StringGridPokazn->Cells[2][11] = "15";
		StringGridPokazn->Cells[2][12] = "3.4";
		StringGridPokazn->Cells[2][13] = "";
		StringGridPokazn->Cells[2][14] = "1.8";
		StringGridPokazn->Cells[2][15] = "120";
		StringGridPokazn->Cells[2][16] = "130";
		StringGridPokazn->Cells[2][17] = "";
		StringGridPokazn->Cells[2][18] = "";
		StringGridPokazn->Cells[2][19] = "140";
		StringGridPokazn->Cells[2][20] = "150";
		StringGridPokazn->Cells[2][21] = "160";
	//lisy box oblast
	sql = "";
	sql = "Select * from Oblast";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql);
		DM->ADOQuery->Active=true;
ListBoxDod->Items->Clear();
	if (DM->ADOQuery->RecordCount > 0) {
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			ListBoxDod->Items->Add(DM->ADOQuery->FieldByName("name_obl")->AsString);
				if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
				}
		}
		// list box gospodarstva
sql = "";
sql = "Select * from gospodarstvo where id_obl = '02'";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql);
		DM->ADOQuery->Active=true;
	ListBox1->Items->Clear();
	if (DM->ADOQuery->RecordCount > 0) {
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			ListBox1->Items->Add(DM->ADOQuery->FieldByName("skoroch_nazva")->AsString);
				if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
				}
		}
}
//---------------------------------------------------------------------------



void __fastcall TfDodatku::BitBtn1Click(TObject *Sender)
{
DM->ADOStoredProcD02->Active=false;
DM->ADOStoredProcD02->Parameters->ParamByName("@P020101")->Value=StrToFloat(StringGridPokazn->Cells[2][1]);
DM->ADOStoredProcD02->Parameters->ParamByName("@P021401")->Value=StrToFloat(StringGridPokazn->Cells[2][6]);
DM->ADOStoredProcD02->Parameters->ParamByName("@P025201")->Value=StrToFloat(StringGridPokazn->Cells[2][15]);
DM->ADOStoredProcD02->ExecProc();
if(DM->ADOStoredProcD02->Parameters->ParamByName("@RETURN_VALUE")->Value==1)
ShowMessage("Племінний репродуктор");
if(DM->ADOStoredProcD02->Parameters->ParamByName("@RETURN_VALUE")->Value==2)
ShowMessage("Племінний завод");
else
ShowMessage("Показники не відповідають статусу");
}
//---------------------------------------------------------------------------





