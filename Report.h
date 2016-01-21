//---------------------------------------------------------------------------

#ifndef ReportH
#define ReportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfReport : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RadioGroup1;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfReport *fReport;
//---------------------------------------------------------------------------
#endif
