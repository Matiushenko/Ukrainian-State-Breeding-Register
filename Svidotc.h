//---------------------------------------------------------------------------

#ifndef SvidotcH
#define SvidotcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
class TfSvidotc : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TPanel *Panel1;
	TLabel *Label1;
	TMemo *Memo1;
	TLabel *Label2;
	TMemo *Memo2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButtonSearch;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton1;
	TValueListEditor *ValueListEditor1;
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfSvidotc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfSvidotc *fSvidotc;
//---------------------------------------------------------------------------
#endif
