//---------------------------------------------------------------------------

#ifndef AnalitukH
#define AnalitukH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfAnalituk : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
private:	// User declarations
public:		// User declarations
	__fastcall TfAnalituk(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAnalituk *fAnalituk;
//---------------------------------------------------------------------------
#endif
