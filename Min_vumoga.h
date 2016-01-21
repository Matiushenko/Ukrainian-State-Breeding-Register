//---------------------------------------------------------------------------

#ifndef Min_vumogaH
#define Min_vumogaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfMin_vumoga : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TComboBox *ComboBoxDod;
	TListBox *ListBoxDod;
	TComboBox *ComboBoxId;
	TLabel *Label2;
	TMemo *Memo1;
	TLabel *Показник;
	TStringGrid *StringGrid;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall ComboBoxDodChange(TObject *Sender);
	void __fastcall ListBoxDodClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfMin_vumoga(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMin_vumoga *fMin_vumoga;
//---------------------------------------------------------------------------
#endif
