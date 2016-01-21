//---------------------------------------------------------------------------

#ifndef DodatkuH
#define DodatkuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfDodatku : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBoxDod;
	TLabel *Label1;
	TListBox *ListBox1;
	TLabel *Label2;
	TListBox *ListBox2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TListBox *ListBox3;
	TLabel *Період;
	TStringGrid *StringGridPokazn;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton1;
	TBitBtn *BitBtn1;
	void __fastcall StringGridClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);







private:	// User declarations
public:		// User declarations
	__fastcall TfDodatku(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfDodatku *fDodatku;
//---------------------------------------------------------------------------
#endif
