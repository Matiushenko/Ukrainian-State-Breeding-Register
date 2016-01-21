//---------------------------------------------------------------------------

#ifndef PorodaH
#define PorodaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfPoroda : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBoxPrd;
	TListBox *ListBoxPrd;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label1;
	TEdit *id_prd;
	TLabel *Label2;
	TMemo *name_prd;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SaveUpdate;
	void __fastcall ListBoxPrdClick(TObject *Sender);
	void __fastcall ComboBoxPrdChange(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SaveUpdateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfPoroda(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfPoroda *fPoroda;
//---------------------------------------------------------------------------
#endif
