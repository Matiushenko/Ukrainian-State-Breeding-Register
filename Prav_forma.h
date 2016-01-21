//---------------------------------------------------------------------------

#ifndef Prav_formaH
#define Prav_formaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfPravForm : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid;
private:	// User declarations
public:		// User declarations
	__fastcall TfPravForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfPravForm *fPravForm;
//---------------------------------------------------------------------------
#endif
