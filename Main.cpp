// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Svidotc.h"
#include "Author.h"
#include "Dovidka.h"
#include "DataModul.h"
#include "Authorisation.h"
#include "Anketa.h"
#include "Poroda.h"
#include <string.h>
#include "Oblast.h"
#include "Galuz.h"
#include "Prav_forma.h"
#include "Report.h"
#include "Min_vumoga.h"
#include "Dodatku.h"
#include "Analituk.h"

AnsiString buf, buf1, x;

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain_ *fMain_;

// ---------------------------------------------------------------------------
__fastcall TfMain_::TfMain_(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton1Click(TObject *Sender) {
	// gospodarstvo
	AnsiString sql1 = "Select * From Gospodarstvo";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql1);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fAnketa->ListBoxGsp->Items->Clear();
		// fAnketa->ComboBoxObl->Items->Clear();
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			AnsiString list;
			list = DM->ADOQuery->FieldByName("skoroch_nazva")->AsString;
			fAnketa->ListBoxGsp->Items->Add(list);
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	// fAnketa->TabSheet->Canvas->Brush->Color=clRed;
	// fAnketa->TabSheet->Canvas->FillRect(Rect);

	AnsiString sql9 = "Select * From Gospodarstvo where skoroch_nazva='";
	sql9 += fAnketa->ListBoxGsp->Items->Strings[0];
	sql9 += "'";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql9);
	DM->ADOQuery->Active = true;
	// edit
	fAnketa->EditScor->Text = DM->ADOQuery->FieldByName("skoroch_nazva")->AsString;
	fAnketa->EditId->Text = DM->ADOQuery->FieldByName("id_gosp")->AsString;
	fAnketa->EditTel1->Text = DM->ADOQuery->FieldByName("tel1")->AsString;
	fAnketa->EditTel2->Text = DM->ADOQuery->FieldByName("tel2")->AsString;
	fAnketa->EditFax->Text = DM->ADOQuery->FieldByName("fax")->AsString;
	fAnketa->EditMail->Text = DM->ADOQuery->FieldByName("email")->AsString;
	fAnketa->EditAdr->Text = DM->ADOQuery->FieldByName("adresa")->AsString;
	fAnketa->EditDr->Text = DM->ADOQuery->FieldByName("data_reestr_gosp")->AsString;
	fAnketa->EditNomd->Text = DM->ADOQuery->FieldByName("N_vet_dovidku")->AsString;
	fAnketa->EditDv->Text = DM->ADOQuery->FieldByName("data_vud_vet_dovidku")->AsString;

	AnsiString sqlcom = "Select * From nasel_punkt where id_nasel_punkt='";
	sqlcom += DM->ADOQuery->FieldByName("id_nasel_punkt")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->EditInd->Text = DM->ADOQueryS->FieldByName("posht_indeks")->AsString;
	sqlcom = "";
	sqlcom = "Select * From zem_nadil where id_gosp='";
	sqlcom += DM->ADOQuery->FieldByName("id_gosp")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->EditZem->Text = DM->ADOQueryS->FieldByName("zem_plosh")->AsString;
	sqlcom = "";
	sqlcom = "Select * From zem_nadil where id_gosp='";
	sqlcom += DM->ADOQuery->FieldByName("id_gosp")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->EditRill->Text = DM->ADOQueryS->FieldByName("rilla")->AsString;
	sqlcom = "";
	sqlcom = "Select * From zem_nadil where id_gosp='";
	sqlcom += DM->ADOQuery->FieldByName("id_gosp")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->EditPasov->Text = DM->ADOQueryS->FieldByName("pasov")->AsString;
	sqlcom = "";
	sqlcom = "Select * From zem_nadil where id_gosp='";
	sqlcom += DM->ADOQuery->FieldByName("id_gosp")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->EditProc->Text = DM->ADOQueryS->FieldByName("derz_mayno")->AsString;

	// memo
	fAnketa->MemoPovn->Lines->Clear();
	fAnketa->MemoPovn->Lines->Add(DM->ADOQuery->FieldByName("povna_nazva")->AsString);
	fAnketa->MemoDir->Lines->Clear();
	fAnketa->MemoDir->Lines->Add(DM->ADOQuery->FieldByName("director")->AsString);
	// combo_box
	sqlcom = "";
	sqlcom = "Select * From nasel_punkt where id_nasel_punkt='";
	sqlcom += DM->ADOQuery->FieldByName("id_nasel_punkt")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxNasel->Items->Add(DM->ADOQueryS->FieldByName("name_nasel_punkt")->AsString);
	fAnketa->ComboBoxNasel->ItemIndex = 0;
	sqlcom = "";
	sqlcom = "Select * From rajon where id_rajon='";
	sqlcom += DM->ADOQuery->FieldByName("id_rajon")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxRaj->Items->Add(DM->ADOQueryS->FieldByName("name_rajon")->AsString);
	fAnketa->ComboBoxRaj->ItemIndex = 0;
	sqlcom = "";
	sqlcom = "Select * From oblast where id_obl='";
	sqlcom += DM->ADOQuery->FieldByName("id_obl")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxOblast->Items->Add(DM->ADOQueryS->FieldByName("name_obl")->AsString);
	fAnketa->ComboBoxOblast->ItemIndex = 0;
	sqlcom = "";
	sqlcom = "Select * From form_vlasn where id_vlasn='";
	sqlcom += DM->ADOQuery->FieldByName("id_vlasn")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxVlasn->Items->Add(DM->ADOQueryS->FieldByName("name_vlasn")->AsString);
	fAnketa->ComboBoxVlasn->ItemIndex = 0;
	sqlcom = "";
	sqlcom = "Select * From pravova_forma where id_prav_form='";
	sqlcom += DM->ADOQuery->FieldByName("id_prav_form")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxPrav->Items->Add(DM->ADOQueryS->FieldByName("name_prav_form")->AsString);
	fAnketa->ComboBoxPrav->ItemIndex = 0;

	// prusvoj_stat
	AnsiString sql8 = "Select * From prusvoj_statusu where id_gosp='";
	sql8 += DM->ADOQuery->FieldByName("id_gosp")->AsString;
	sql8 += "'";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql8);
	DM->ADOQuery->Active = true;
	// edit
	fAnketa->EditDst->Text = DM->ADOQuery->FieldByName("dat_pr_stat")->AsString;
	fAnketa->EditNn->Text = DM->ADOQuery->FieldByName("N_nakazu")->AsString;
	fAnketa->EditDa->Text = DM->ADOQuery->FieldByName("dat_vud_atest")->AsString;
	fAnketa->EditNa->Text = DM->ADOQuery->FieldByName("N_atest")->AsString;
	fAnketa->EditNs->Text = DM->ADOQuery->FieldByName("reg_N_stada")->AsString;
	fAnketa->EditDrs->Text = DM->ADOQuery->FieldByName("dat_reestr_stada")->AsString;
	fAnketa->EditSs->Text = DM->ADOQuery->FieldByName("serija_N_svidoctva")->AsString;
	fAnketa->EditDs->Text = DM->ADOQuery->FieldByName("pozb_stat")->AsString;
	fAnketa->EditNomn->Text = DM->ADOQuery->FieldByName("N_nakaz_na_pozb_stat")->AsString;
	// memo
	sqlcom = "";
	sqlcom = "Select * From status where id_status='";
	sqlcom += DM->ADOQuery->FieldByName("id_status")->AsString;
	sqlcom += "'";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->MemoStat->Lines->Clear();
	fAnketa->MemoStat->Lines->Add(DM->ADOQueryS->FieldByName("name_status")->AsString);
	// combo_box
	sqlcom = "";
	sqlcom ="Select name_galuz From galuz where id_galuz=(select id_galuz from status where id_status='";
	sqlcom += DM->ADOQuery->FieldByName("id_status")->AsString;
	sqlcom += "')";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxGal1->Items->Add(DM->ADOQueryS->FieldByName("name_galuz")->AsString);
	fAnketa->ComboBoxGal1->ItemIndex = 0;

	sqlcom = "";
	sqlcom ="Select name_poroda From poroda where id_poroda=(select id_poroda from status where id_status='";
	sqlcom += DM->ADOQuery->FieldByName("id_status")->AsString;
	sqlcom += "')";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxPrd1->Items->Add(DM->ADOQueryS->FieldByName("name_poroda")->AsString);
	fAnketa->ComboBoxPrd1->ItemIndex = 0;

	sqlcom = "";
	sqlcom ="Select name_naprjam From naprjam where id_naprjam=(select id_naprjam from status where id_status='";
	sqlcom += DM->ADOQuery->FieldByName("id_status")->AsString;
	sqlcom += "')";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxNapr->Items->Add(DM->ADOQueryS->FieldByName("name_naprjam")->AsString);
	fAnketa->ComboBoxNapr->ItemIndex = 0;

	// enable
	fAnketa->EditScor->Enabled = false;
	fAnketa->MemoPovn->Enabled = false;
	fAnketa->EditId->Enabled = false;
	fAnketa->EditInd->Enabled = false;
	fAnketa->ComboBoxOblast->Enabled = false;
	fAnketa->ComboBoxRaj->Enabled = false;
	fAnketa->ComboBoxNasel->Enabled = false;
	fAnketa->EditTel1->Enabled = false;
	fAnketa->EditTel2->Enabled = false;
	fAnketa->EditFax->Enabled = false;
	fAnketa->EditMail->Enabled = false;
	fAnketa->EditAdr->Enabled = false;
	fAnketa->EditDr->Enabled = false;
	fAnketa->ComboBoxPrav->Enabled = false;
	fAnketa->ComboBoxVlasn->Enabled = false;
	fAnketa->EditProc->Enabled = false;
	fAnketa->MemoDir->Enabled = false;
	fAnketa->EditZem->Enabled = false;
	fAnketa->EditRill->Enabled = false;
	fAnketa->EditPasov->Enabled = false;
	fAnketa->EditNomd->Enabled = false;
	fAnketa->EditDv->Enabled = false;
	fAnketa->ComboBoxGal1->Enabled = false;
	fAnketa->ComboBoxPrd1->Enabled = false;
	fAnketa->ComboBoxNapr->Enabled = false;
	fAnketa->MemoStat->Enabled = false;
	fAnketa->EditDst->Enabled = false;
	fAnketa->EditNn->Enabled = false;
	fAnketa->EditDa->Enabled = false;
	fAnketa->EditNa->Enabled = false;
	fAnketa->EditNs->Enabled = false;
	fAnketa->EditDrs->Enabled = false;
	fAnketa->EditSs->Enabled = false;
	fAnketa->EditDs->Enabled = false;
	fAnketa->EditNomn->Enabled = false;

	fAnketa->CountGosp->Text = fAnketa->ListBoxGsp->Items->Count;
	fAnketa->ShowModal();

}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton1MouseEnter(TObject *Sender) {
	ToolButton1->ImageIndex = 6;

}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton1MouseLeave(TObject *Sender) {
	ToolButton1->ImageIndex = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton2MouseEnter(TObject *Sender) {
	ToolButton2->ImageIndex = 7;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton2MouseLeave(TObject *Sender) {
	ToolButton2->ImageIndex = 1;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton3MouseEnter(TObject *Sender) {
	ToolButton3->ImageIndex = 8;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton3MouseLeave(TObject *Sender) {
	ToolButton3->ImageIndex = 2;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton7MouseEnter(TObject *Sender) {
	ToolButton7->ImageIndex = 9;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton7MouseLeave(TObject *Sender) {
	ToolButton7->ImageIndex = 3;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton8MouseEnter(TObject *Sender) {
	ToolButton8->ImageIndex = 10;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton8MouseLeave(TObject *Sender) {
	ToolButton8->ImageIndex = 4;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton9MouseLeave(TObject *Sender) {
	ToolButton9->ImageIndex = 5;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton9MouseEnter(TObject *Sender) {
	ToolButton9->ImageIndex = 11;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton9Click(TObject *Sender) {
	if (MessageDlg("Ви впевнені що хочете вийти з програми?", mtConfirmation,TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes) {

		if (DM->ADOConnect->Connected) {
			DM->ADOConnect->Connected = false;
			if (!DM->ADOConnect->Connected) {
				DM->ADOConnect->ConnectionString = EmptyStr;
			}
		}
		Close();
		//Exit();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::N11Click(TObject *Sender) {
	// poroda
	AnsiString sql = "Select * From Galuz";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fPoroda->ComboBoxPrd->Items->Clear();
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			fPoroda->ComboBoxPrd->Items->Add(DM->ADOQuery->FieldByName("name_galuz")->AsString);
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	fPoroda->ComboBoxPrd->ItemIndex = 0;

	AnsiString sql1 ="Select * From Poroda where id_galuz=(select id_galuz from galuz where name_galuz='";
	sql1 += fPoroda->ComboBoxPrd->Text.Trim();
	sql1 += "')";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql1);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fPoroda->ListBoxPrd->Items->Clear();
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			AnsiString list;
			list = DM->ADOQuery->FieldByName("name_poroda")->AsString;
			fPoroda->ListBoxPrd->Items->Add(list);
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	fPoroda->TabSheet1->Caption = fPoroda->ComboBoxPrd->Text.Trim();
	sql1 = "Select id_poroda From Poroda where name_poroda='";
	sql1 += fPoroda->ListBoxPrd->Items->Strings[0];
	sql1 += "'";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql1);
	DM->ADOQuery->Active = true;
	fPoroda->id_prd->Text = DM->ADOQuery->FieldByName("id_poroda")->AsString;
	fPoroda->name_prd->Lines->Clear();
	fPoroda->name_prd->Lines->Add(fPoroda->ListBoxPrd->Items->Strings[0]);
	fPoroda->name_prd->Enabled = false;
	fPoroda->id_prd->Enabled = false;
	fPoroda->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::N17Click(TObject *Sender) {
	// oblast
	fOblast->StringGrid->Cells[0][0] = "Код області";
	fOblast->StringGrid->Cells[1][0] = "Назва області";
	AnsiString sql = "Select * From Oblast";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fOblast->StringGrid->RowCount = DM->ADOQuery->RecordCount;
		fOblast->StringGrid->RowCount++;
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			fOblast->StringGrid->Cells[0][i] = DM->ADOQuery->FieldByName("id_obl")->AsString;
			fOblast->StringGrid->Cells[1][i] = DM->ADOQuery->FieldByName("name_obl")->AsString;
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	fOblast->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::N14Click(TObject *Sender) {
	// galuz
	fGaluz->StringGrid->Cells[0][0] = "Код галузі";
	fGaluz->StringGrid->Cells[1][0] = "Назва галузі";
	AnsiString sql = "Select * From Galuz";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fGaluz->StringGrid->RowCount = DM->ADOQuery->RecordCount;
		fGaluz->StringGrid->RowCount++;
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			fGaluz->StringGrid->Cells[0][i] = DM->ADOQuery->FieldByName("id_galuz")->AsString;
			fGaluz->StringGrid->Cells[1][i] = DM->ADOQuery->FieldByName("name_galuz")->AsString;
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	fGaluz->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain_::N15Click(TObject *Sender) {
	// prav_form
	fPravForm->StringGrid->Cells[0][0] = "Код прав. форми";
	fPravForm->StringGrid->Cells[1][0] = "Назва прав. форми";
	AnsiString sql = "Select * From pravova_forma";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fPravForm->StringGrid->RowCount = DM->ADOQuery->RecordCount;
		fPravForm->StringGrid->RowCount++;
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			fPravForm->StringGrid->Cells[0][i] = DM->ADOQuery->FieldByName("id_prav_form")->AsString;
			fPravForm->StringGrid->Cells[1][i] = DM->ADOQuery->FieldByName("name_prav_form")->AsString;
			if (i < DM->ADOQuery->RecordCount)
				DM->ADOQuery->FindNext();
		}
	}
	fPravForm->ShowModal();
}
// ---------------------------------------------------------------------------
void __fastcall TfMain_::ToolButton7Click(TObject *Sender)
{
//zvit

	fReport->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TfMain_::N20Click(TObject *Sender)
{
	// Min_vumoga
	fMin_vumoga->StringGrid->ColWidths[0]=63;
	fMin_vumoga->StringGrid->ColWidths[1]=46;
	fMin_vumoga->StringGrid->ColWidths[2]=46;
	fMin_vumoga->StringGrid->ColWidths[3]=46;
	fMin_vumoga->StringGrid->ColWidths[4]=48;
	fMin_vumoga->StringGrid->ColWidths[5]=48;
	fMin_vumoga->StringGrid->ColWidths[6]=48;
	fMin_vumoga->StringGrid->ColWidths[7]=47;
	//записываем комбобокс
	AnsiString sql = "Select * From Dodatok";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fMin_vumoga->ComboBoxDod->Items->Clear();
		DM->ADOQuery->FindFirst();
		for (int i = 1; i <= DM->ADOQuery->RecordCount; i++) {
			fMin_vumoga->ComboBoxDod->Items->Add(DM->ADOQuery->FieldByName("dodatokN")->AsString+" - "+DM->ADOQuery->FieldByName("id_galuz")->AsString);
			if (i < DM->ADOQuery->RecordCount)
			DM->ADOQuery->FindNext();
		}
	}
	fMin_vumoga->ComboBoxDod->ItemIndex = 0;
	// Записываем листбокс
	AnsiString sql1 ="select LEFT(id_ind, 3)+id_naprjam as m from min_vumoga where LEFT(id_ind, 3)=(select id_dodatok from dodatok where dodatokN='";
	AnsiString sqlc,sss;
	sqlc=fMin_vumoga->ComboBoxDod->Text.Trim();
	sss.Insert(sqlc,0);
	sss.Delete(11,100);
	sql1 += sss.Trim();
	sql1 += "')";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql1);
	DM->ADOQuery->Active = true;
	if (DM->ADOQuery->RecordCount > 0) {
		fMin_vumoga->ListBoxDod->Items->Clear();
		DM->ADOQuery->FindFirst();
AnsiString sqls ="select id_ind from min_vumoga where LEFT(id_ind, 3)+id_naprjam='";
sqls+=DM->ADOQuery->FieldByName("m")->AsString;
sqls+="' group by id_ind";
DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqls);
	DM->ADOQueryS->Active = true;
	if (DM->ADOQueryS->RecordCount > 0) {
		fMin_vumoga->ListBoxDod->Items->Clear();
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
			fMin_vumoga->ListBoxDod->Items->Add(list);
			if (i < DM->ADOQueryS->RecordCount)
				DM->ADOQueryS->FindNext();
		}  }
	fMin_vumoga->Memo1->Lines->Add(DM->ADOQueryT->FieldByName("name_indeks")->AsString);
	fMin_vumoga->ComboBoxId->Items->Add(DM->ADOQueryT->FieldByName("kod_indeks")->AsString);
	fMin_vumoga->ComboBoxId->ItemIndex = 0;
	}

	//значения
DM->ADOQuery->FindFirst();
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
		fMin_vumoga->StringGrid->Cells[0][i-1] = DM->ADOQueryF->FieldByName("id_poroda")->AsString;
AnsiString sql7 ="select id_naprjam from min_vumoga where LEFT(id_ind, 3)+id_naprjam='";
sql7+=DM->ADOQuery->FieldByName("m")->AsString;
sql7+="'";
	DM->ADOQueryT->Active = false;
	DM->ADOQueryT->SQL->Clear();
	DM->ADOQueryT->SQL->Add(sql7);
	DM->ADOQueryT->Active = true;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ПЗ")
	fMin_vumoga->StringGrid->Cells[1][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
	if(DM->ADOQueryT->FieldByName("id_naprjam")->AsString=="ПР")
	fMin_vumoga->StringGrid->Cells[2][i-1] = DM->ADOQueryF->FieldByName("znach")->AsString;
			if (i < DM->ADOQueryF->RecordCount)
			DM->ADOQueryF->FindNext();
		}
	}
if (i < DM->ADOQuery->RecordCount)
DM->ADOQuery->FindNext();
}
	fMin_vumoga->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton2Click(TObject *Sender)
{
	fDodatku->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::N24Click(TObject *Sender)
{
	fAuthor->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::N25Click(TObject *Sender)
{
	fDovidka->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton3Click(TObject *Sender)
{
	 fSvidotc->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton8Click(TObject *Sender)
{
DM->ADOStoredProcBackUp->Active=false;
DM->ADOStoredProcBackUp->ExecProc();
if(DM->ADOStoredProcBackUp->Parameters->ParamByName("@RETURN_VALUE")->Value==0)
//ShowMessage("Резервне копіювання виконано!");
MessageDlg("Резервне копіювання виконано!", mtConfirmation,TMsgDlgButtons(), mbOK);
else
ShowMessage("Помилка. Резервне копіювання не виконано!");
}
//---------------------------------------------------------------------------


void __fastcall TfMain_::ToolButton14MouseLeave(TObject *Sender)
{
ToolButton14->ImageIndex = 12;
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton14MouseEnter(TObject *Sender)
{
ToolButton14->ImageIndex = 13;
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::ToolButton14Click(TObject *Sender)
{
fAnalituk->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain_::N8Click(TObject *Sender)
{
 ShellExecute(Handle,"open","http://localhost/ReportServer/Pages/ReportViewer.aspx?%2freport_project%2fReport3&rs:Command=Render",NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

