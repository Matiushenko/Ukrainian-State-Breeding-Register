//---------------------------------------------------------------------------

#ifndef AuthorH
#define AuthorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfAuthor : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label4;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label2;
	TButton *Button1;
private:	// User declarations
public:		// User declarations
	__fastcall TfAuthor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAuthor *fAuthor;
//---------------------------------------------------------------------------
#endif
