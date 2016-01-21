//---------------------------------------------------------------------------

#ifndef DovidkaH
#define DovidkaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfDovidka : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TPanel *Panel1;
	TButton *Button1;
private:	// User declarations
public:		// User declarations
	__fastcall TfDovidka(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfDovidka *fDovidka;
//---------------------------------------------------------------------------
#endif
