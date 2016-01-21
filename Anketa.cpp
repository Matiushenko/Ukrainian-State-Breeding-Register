//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Anketa.h"
#include "Main.h"
#include "DataModul.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAnketa *fAnketa;
//---------------------------------------------------------------------------
__fastcall TfAnketa::TfAnketa(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TfAnketa::SpeedButton6Click(TObject *Sender)
{
fAnketa->Close();
}
//---------------------------------------------------------------------------






void __fastcall TfAnketa::ListBoxGspClick(TObject *Sender)
{

AnsiString	sql9="Select * From Gospodarstvo where skoroch_nazva='";
		sql9+=ListBoxGsp->Items->Strings[ListBoxGsp->ItemIndex];
		sql9+="'";
		DM->ADOQuery->Active=false;
		DM->ADOQuery->SQL->Clear();
		DM->ADOQuery->SQL->Add(sql9);
		DM->ADOQuery->Active=true;
//edit
EditScor->Text=DM->ADOQuery->FieldByName("skoroch_nazva")->AsString;
EditId->Text=DM->ADOQuery->FieldByName("id_gosp")->AsString;
EditTel1->Text=DM->ADOQuery->FieldByName("tel1")->AsString;
EditTel2->Text=DM->ADOQuery->FieldByName("tel2")->AsString;
EditFax->Text=DM->ADOQuery->FieldByName("fax")->AsString;
EditMail->Text=DM->ADOQuery->FieldByName("email")->AsString;
EditAdr->Text=DM->ADOQuery->FieldByName("adresa")->AsString;
EditDr->Text=DM->ADOQuery->FieldByName("data_reestr_gosp")->AsString;
EditNomd->Text=DM->ADOQuery->FieldByName("N_vet_dovidku")->AsString;
EditDv->Text=DM->ADOQuery->FieldByName("data_vud_vet_dovidku")->AsString;
ComboBoxGal1->Text="молочне і молочно-мясне скотарство";
ComboBoxPrd1->Text="червона степова";
ComboBoxNapr->Text="Племінний завод";

AnsiString sqlcom="Select * From nasel_punkt where id_nasel_punkt='";
 sqlcom+=DM->ADOQuery->FieldByName("id_nasel_punkt")->AsString;
 sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
EditInd->Text=DM->ADOQueryS->FieldByName("posht_indeks")->AsString;
sqlcom="";
sqlcom="Select * From zem_nadil where id_gosp='";
sqlcom+=DM->ADOQuery->FieldByName("id_gosp")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
EditZem->Text=DM->ADOQueryS->FieldByName("zem_plosh")->AsString;
sqlcom="";
sqlcom="Select * From zem_nadil where id_gosp='";
sqlcom+=DM->ADOQuery->FieldByName("id_gosp")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
EditRill->Text=DM->ADOQueryS->FieldByName("rilla")->AsString;
sqlcom="";
sqlcom="Select * From zem_nadil where id_gosp='";
sqlcom+=DM->ADOQuery->FieldByName("id_gosp")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
EditPasov->Text=DM->ADOQueryS->FieldByName("pasov")->AsString;
sqlcom="";
sqlcom="Select * From zem_nadil where id_gosp='";
sqlcom+=DM->ADOQuery->FieldByName("id_gosp")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
EditProc->Text=DM->ADOQueryS->FieldByName("derz_mayno")->AsString;

//memo
MemoPovn->Lines->Clear();
MemoPovn->Lines->Add(DM->ADOQuery->FieldByName("povna_nazva")->AsString);
MemoDir->Lines->Clear();
MemoDir->Lines->Add(DM->ADOQuery->FieldByName("director")->AsString);
//combo_box
ComboBoxNasel->Items->Clear();
sqlcom="";
sqlcom="Select * From nasel_punkt where id_nasel_punkt='";
sqlcom+=DM->ADOQuery->FieldByName("id_nasel_punkt")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
ComboBoxNasel->Items->Add(DM->ADOQueryS->FieldByName("name_nasel_punkt")->AsString);
ComboBoxNasel->ItemIndex=0;
ComboBoxRaj->Items->Clear();
sqlcom="";
sqlcom="Select * From rajon where id_rajon='";
sqlcom+=DM->ADOQuery->FieldByName("id_rajon")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
ComboBoxRaj->Items->Add(DM->ADOQueryS->FieldByName("name_rajon")->AsString);
ComboBoxRaj->ItemIndex=0;
ComboBoxOblast->Clear();
sqlcom="";
sqlcom="Select * From oblast where id_obl='";
sqlcom+=DM->ADOQuery->FieldByName("id_obl")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
ComboBoxOblast->Items->Add(DM->ADOQueryS->FieldByName("name_obl")->AsString);
ComboBoxOblast->ItemIndex=0;
ComboBoxVlasn->Clear();
sqlcom="";
sqlcom="Select * From form_vlasn where id_vlasn='";
sqlcom+=DM->ADOQuery->FieldByName("id_vlasn")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
ComboBoxVlasn->Items->Add(DM->ADOQueryS->FieldByName("name_vlasn")->AsString);
ComboBoxPrav->Items->Clear();
ComboBoxVlasn->ItemIndex=0;
sqlcom="";
sqlcom="Select * From pravova_forma where id_prav_form='";
sqlcom+=DM->ADOQuery->FieldByName("id_prav_form")->AsString;
sqlcom+="'";
		DM->ADOQueryS->Active=false;
		DM->ADOQueryS->SQL->Clear();
		DM->ADOQueryS->SQL->Add(sqlcom);
		DM->ADOQueryS->Active=true;
ComboBoxPrav->Items->Add(DM->ADOQueryS->FieldByName("name_prav_form")->AsString);
ComboBoxPrav->ItemIndex=0;



	// prusvoj_stat
	AnsiString sql8 = "Select * From prusvoj_statusu where id_gosp='";
	sql8 += DM->ADOQuery->FieldByName("id_gosp")->AsString;
	sql8 += "'";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(sql8);
	DM->ADOQuery->Active = true;
	// edit
	fAnketa->EditDst->Text = DM->ADOQuery->FieldByName("dat_pr_stat")
		->AsString;
	fAnketa->EditNn->Text = DM->ADOQuery->FieldByName("N_nakazu")->AsString;
	fAnketa->EditDa->Text = DM->ADOQuery->FieldByName("dat_vud_atest")
		->AsString;
	fAnketa->EditNa->Text = DM->ADOQuery->FieldByName("N_atest")
		->AsString;
	fAnketa->EditNs->Text = DM->ADOQuery->FieldByName("reg_N_stada")
		->AsString;
	fAnketa->EditDrs->Text = DM->ADOQuery->FieldByName("dat_reestr_stada")
		->AsString;
	fAnketa->EditSs->Text = DM->ADOQuery->FieldByName("serija_N_svidoctva")
		->AsString;
	fAnketa->EditDs->Text = DM->ADOQuery->FieldByName("pozb_stat")
		->AsString;
	fAnketa->EditNomn->Text = DM->ADOQuery->FieldByName
		("N_nakaz_na_pozb_stat")->AsString;
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
	fAnketa->MemoStat->Lines->Add(DM->ADOQueryS->FieldByName("name_status")
		->AsString);
	// combo_box
	sqlcom = "";
	sqlcom =
		"Select name_galuz From galuz where id_galuz=(select id_galuz from status where id_status='";
	sqlcom += DM->ADOQuery->FieldByName("id_status")->AsString;
	sqlcom += "')";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxGal1->Items->Add(DM->ADOQueryS->FieldByName("name_galuz")
		->AsString);
	fAnketa->ComboBoxGal1->ItemIndex = 0;

	sqlcom = "";
	sqlcom =
		"Select name_poroda From poroda where id_poroda=(select id_poroda from status where id_status='";
	sqlcom += DM->ADOQuery->FieldByName("id_status")->AsString;
	sqlcom += "')";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxPrd1->Items->Add(DM->ADOQueryS->FieldByName("name_poroda")
		->AsString);
	fAnketa->ComboBoxPrd1->ItemIndex = 0;

	sqlcom = "";
	sqlcom =
		"Select name_naprjam From naprjam where id_naprjam=(select id_naprjam from status where id_status='";
	sqlcom += DM->ADOQuery->FieldByName("id_status")->AsString;
	sqlcom += "')";
	DM->ADOQueryS->Active = false;
	DM->ADOQueryS->SQL->Clear();
	DM->ADOQueryS->SQL->Add(sqlcom);
	DM->ADOQueryS->Active = true;
	fAnketa->ComboBoxNapr->Items->Add(DM->ADOQueryS->FieldByName("name_naprjam")->AsString);
	fAnketa->ComboBoxNapr->ItemIndex = 0;

}
//---------------------------------------------------------------------------



void __fastcall TfAnketa::SpeedButtonSearchClick(TObject *Sender)
{
/* AnsiString src = "Select * From Anketa where id_gosp Like '%"+EditIdGosp->Text+
 "%' and skoroch_nazva Like '%"+EditSkorName->Text+"%'";
	DM->ADOQuery->Active = false;
	DM->ADOQuery->SQL->Clear();
	DM->ADOQuery->SQL->Add(src);
	DM->ADOQuery->Active = true;   */
}
//---------------------------------------------------------------------------



