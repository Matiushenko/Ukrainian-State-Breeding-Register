//---------------------------------------------------------------------------

#ifndef OblastH
#define OblastH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfOblast : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid;
	void __fastcall StringGridClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfOblast(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfOblast *fOblast;
//---------------------------------------------------------------------------
#endif
