//---------------------------------------------------------------------------

#ifndef AuthorisationH
#define AuthorisationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <pngimage.hpp>
//---------------------------------------------------------------------------
class TfAuthorisation : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonEntry;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditLogin;
	TEdit *EditPassword;
	TButton *ButtonExit;
	TLabel *Label4;
	TImage *Image1;
	TImage *Image2;
	void __fastcall ButtonEntryClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfAuthorisation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAuthorisation *fAuthorisation;
//---------------------------------------------------------------------------
#endif
