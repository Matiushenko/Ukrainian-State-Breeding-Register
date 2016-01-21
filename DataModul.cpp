//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <iostream>
#include <stdio.h>
#pragma hdrstop

#include "DataModul.h"
#include "Authorisation.h"
#include "Main.h"
#include "Poroda.h"
#include "Anketa.h"
#include "Report.h"
#include "Svidotc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TDM *DM;


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

bool __fastcall GetConnectionString(AnsiString & CS)
 {
  char  Str[1024];
	 FILE *f;
	 if((f=fopen("c:\\DBConnectionString", "rt")) == NULL){
	 CS = "";
	 return false;}
		else{
				if(!fgets(Str, 1024, f)){
				   CS = "";
				   fclose(f);
				   return false;
				   }
				   else{
				   CS = Str;
				   fclose(f);
				   return true;
				   }
		}
  }
//---------------------------------------------------------------------------

AnsiString __fastcall ComposeConnectionString(AnsiString StringFromWizard, AnsiString UserID, AnsiString Pass)
{
AnsiString Provider,Password,Persist_Security_Info,User_ID,Initial_Catalog,
		   Data_Source;
AnsiString ConnStr,tmp,tmp1;

SplitLine(StringFromWizard, ';', Provider, tmp);
if(tmp.Pos("Password="))
SplitLine(tmp, ';', Password, tmp);
SplitLine(tmp, ';', Persist_Security_Info, tmp);
SplitLine(tmp, ';', User_ID, tmp);
SplitLine(tmp, ';', Initial_Catalog, Data_Source);
//SplitLine(tmp, ';', Initial_Catalog, tmp);

User_ID = "User ID="+UserID;
Password = "Password="+Pass;

ConnStr = (AnsiString)Provider+";"+Password+";"+Persist_Security_Info+";"+User_ID+";"+Initial_Catalog+";"+Data_Source;
return ConnStr;
}

 void  __fastcall SplitLine(AnsiString line, TCHAR delimiter, AnsiString & first_part, AnsiString & last_part)
{
int pos = line.AnsiPos(delimiter);
if(!pos){
 first_part = "";
 last_part = "";
 return;
}
 first_part = line.SubString(0, pos-1).Trim();
 last_part = line.SubString(pos+1, line.Length()- pos).Trim();
}


 int  __fastcall ActiveQuery(AnsiString TextWhere,TADOQuery* ADOQAll)
  {  try{
		 if(ADOQAll->Active)
		 ADOQAll->Close();
		 ADOQAll->SQL->Clear();
		 ADOQAll->SQL->Add(TextWhere);
		 ADOQAll->Open();
		 return ADOQAll->RecordCount;
		}
	 catch(...) {MessageDlg("Error", mtError, TMsgDlgButtons() << mbOK, 0);
                 return 0;
                 }
   }




