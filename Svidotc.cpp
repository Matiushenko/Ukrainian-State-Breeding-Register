//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Svidotc.h"
#include "Main.h"
#include "DataModul.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfSvidotc *fSvidotc;
//---------------------------------------------------------------------------
__fastcall TfSvidotc::TfSvidotc(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfSvidotc::SpeedButton1Click(TObject *Sender)
{


	//DM->frxReport1->LoadFromFile("C:\\Ukr_Gospodarstva\galuz.fr3");
	//DM->frxReport1->ShowPreparedReport();
TfrxMemoView * MemoR1 = dynamic_cast <TfrxMemoView *> (DM->frxReportSvidoctvo->FindObject("Memo1"));
MemoR1->Text = Memo1->Text;
TfrxMemoView * MemoR2 = dynamic_cast <TfrxMemoView *> (DM->frxReportSvidoctvo->FindObject("Memo21"));
MemoR2->Text = Memo2->Text;
TfrxMemoView * MemoR3 = dynamic_cast <TfrxMemoView *> (DM->frxReportSvidoctvo->FindObject("Memo22"));
MemoR3->Text = Edit1->Text;
TfrxMemoView * MemoR4 = dynamic_cast <TfrxMemoView *> (DM->frxReportSvidoctvo->FindObject("Memo23"));
MemoR4->Text = Edit3->Text;
TfrxMemoView * MemoR5 = dynamic_cast <TfrxMemoView *> (DM->frxReportSvidoctvo->FindObject("Memo24"));
MemoR5->Text = Edit4->Text;
TfrxMemoView * MemoR6 = dynamic_cast <TfrxMemoView *> (DM->frxReportSvidoctvo->FindObject("Memo25"));
MemoR6->Text = Edit5->Text;
	DM->frxReportSvidoctvo->ShowReport();
}
//---------------------------------------------------------------------------


