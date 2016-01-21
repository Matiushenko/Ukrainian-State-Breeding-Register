//---------------------------------------------------------------------------

#ifndef GaluzH
#define GaluzH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfGaluz : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid;
private:	// User declarations
public:		// User declarations
	__fastcall TfGaluz(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfGaluz *fGaluz;
//---------------------------------------------------------------------------
#endif
