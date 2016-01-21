//---------------------------------------------------------------------------

#ifndef AnketaH
#define AnketaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfAnketa : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBoxGsp;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TPanel *Panel1;
	TPageControl *TabSheet;
	TComboBox *ComboBoxObl;
	TComboBox *ComboBoxGal;
	TComboBox *ComboBoxPrd;
	TComboBox *ComboBoxStat;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButtonSearch;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TLabel *Label5;
	TEdit *CountGosp;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *EditScor;
	TMemo *MemoPovn;
	TEdit *EditId;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TEdit *EditInd;
	TLabel *Label14;
	TLabel *Label15;
	TComboBox *ComboBoxOblast;
	TComboBox *ComboBoxRaj;
	TComboBox *ComboBoxNasel;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TEdit *EditTel1;
	TEdit *EditTel2;
	TEdit *EditFax;
	TEdit *EditMail;
	TLabel *Label20;
	TEdit *EditAdr;
	TEdit *EditDr;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TComboBox *ComboBoxPrav;
	TComboBox *ComboBoxVlasn;
	TEdit *EditProc;
	TLabel *Label26;
	TMemo *MemoDir;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TEdit *EditZem;
	TEdit *EditRill;
	TEdit *EditPasov;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TEdit *EditNomd;
	TEdit *EditDv;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label36;
	TComboBox *ComboBoxGal1;
	TComboBox *ComboBoxPrd1;
	TComboBox *ComboBoxNapr;
	TMemo *MemoStat;
	TLabel *Label37;
	TLabel *Label38;
	TLabel *Label39;
	TEdit *EditDst;
	TEdit *EditNn;
	TLabel *Label40;
	TLabel *Label41;
	TLabel *Label42;
	TEdit *EditDa;
	TEdit *EditNa;
	TLabel *Label43;
	TLabel *Label44;
	TLabel *Label45;
	TLabel *Label46;
	TEdit *EditNs;
	TEdit *EditDrs;
	TEdit *EditSs;
	TLabel *Label47;
	TLabel *Label48;
	TLabel *Label49;
	TEdit *EditDs;
	TEdit *EditNomn;
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall ListBoxGspClick(TObject *Sender);
	void __fastcall SpeedButtonSearchClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfAnketa(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAnketa *fAnketa;
//---------------------------------------------------------------------------
#endif
