//---------------------------------------------------------------------------

#ifndef DataModulH
#define DataModulH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnect;
	TADOQuery *ADOQueryS;
	TADOQuery *ADOQuery;
	TfrxReport *frxReportObl;
	TfrxDBDataset *frxDBDataset1;
	TADOQuery *ADOQueryT;
	TADOQuery *ADOQueryF;
	TADOStoredProc *ADOStoredProcD02;
	TfrxReport *frxReportSvidoctvo;
	TfrxReport *frxReportGaluz;
	TfrxReport *frxReportYearVud;
	TfrxReport *frxReportZemRes;
	TADOStoredProc *ADOStoredProcD10;
	TADOStoredProc *ADOStoredProcD07;
	TADOStoredProc *ADOStoredProcD09;
	TADOStoredProc *ADOStoredProcD11;
	TADOStoredProc *ADOStoredProcD08;
	TADOStoredProc *ADOStoredProcD04;
	TADOStoredProc *ADOStoredProcD03;
	TADOStoredProc *ADOStoredProcBackUp;
	TADOStoredProc *ADOStoredProcRestore;
private:	// User declarations
public:		// User declarations
	__fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
bool __fastcall GetConnectionString(AnsiString & cs);
  int  __fastcall ActiveQuery(AnsiString TextWhere,TADOQuery* ADOQAll);
    void ConnectDB();
  AnsiString __fastcall ComposeConnectionString(AnsiString StringFromWizard, AnsiString UserID, AnsiString Pass);
  void  __fastcall SplitLine(AnsiString line, TCHAR delimiter, AnsiString & first_part, AnsiString & last_part);

//---------------------------------------------------------------------------
#endif
