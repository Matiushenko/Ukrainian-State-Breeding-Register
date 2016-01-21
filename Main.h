//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <pngimage.hpp>
//---------------------------------------------------------------------------
class TfMain_ : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TImageList *ImageList;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TMainMenu *MainMenu;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TToolButton *ToolButton14;
	TToolButton *ToolButton16;
	TMenuItem *N26;
	TMenuItem *KPI1;
	TMenuItem *N27;
	TMenuItem *N28;
	TMenuItem *N29;
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton1MouseEnter(TObject *Sender);
	void __fastcall ToolButton1MouseLeave(TObject *Sender);
	void __fastcall ToolButton2MouseEnter(TObject *Sender);
	void __fastcall ToolButton2MouseLeave(TObject *Sender);
	void __fastcall ToolButton3MouseEnter(TObject *Sender);
	void __fastcall ToolButton3MouseLeave(TObject *Sender);
	void __fastcall ToolButton7MouseEnter(TObject *Sender);
	void __fastcall ToolButton7MouseLeave(TObject *Sender);
	void __fastcall ToolButton8MouseEnter(TObject *Sender);
	void __fastcall ToolButton8MouseLeave(TObject *Sender);
	void __fastcall ToolButton9MouseLeave(TObject *Sender);
	void __fastcall ToolButton9MouseEnter(TObject *Sender);
	void __fastcall ToolButton9Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N17Click(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall ToolButton7Click(TObject *Sender);
	void __fastcall N20Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N25Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ToolButton8Click(TObject *Sender);
	void __fastcall ToolButton14MouseLeave(TObject *Sender);
	void __fastcall ToolButton14MouseEnter(TObject *Sender);
	void __fastcall ToolButton14Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfMain_(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain_ *fMain_;
//---------------------------------------------------------------------------
#endif
