//---------------------------------------------------------------------------

#ifndef ReportOH
#define ReportOH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfReportO : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBoxZv;
	TButton *Button1;
	TLabel *Label1;
	TButton *Вийти;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfReportO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfReportO *fReportO;
//---------------------------------------------------------------------------
#endif
