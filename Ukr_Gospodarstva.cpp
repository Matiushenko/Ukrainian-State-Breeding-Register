//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Poroda.cpp", fPoroda);
USEFORM("Report.cpp", fReport);
USEFORM("Oblast.cpp", fOblast);
USEFORM("Main.cpp", fMain_);
USEFORM("Dovidka.cpp", fDovidka);
USEFORM("Svidotc.cpp", fSvidotc);
USEFORM("Min_vumoga.cpp", fMin_vumoga);
USEFORM("Author.cpp", fAuthor);
USEFORM("Dodatku.cpp", fDodatku);
USEFORM("Authorisation.cpp", fAuthorisation);
USEFORM("DataModul.cpp", DM); /* TDataModule: File Type */
USEFORM("Anketa.cpp", fAnketa);
USEFORM("Prav_forma.cpp", fPravForm);
USEFORM("Galuz.cpp", fGaluz);
USEFORM("ReportO.cpp", fReportO);
USEFORM("Analituk.cpp", fAnalituk);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TfMain_), &fMain_);
		Application->CreateForm(__classid(TfAuthorisation), &fAuthorisation);
		Application->CreateForm(__classid(TfPoroda), &fPoroda);
		Application->CreateForm(__classid(TfAnketa), &fAnketa);
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TfOblast), &fOblast);
		Application->CreateForm(__classid(TfGaluz), &fGaluz);
		Application->CreateForm(__classid(TfPravForm), &fPravForm);
		Application->CreateForm(__classid(TfReport), &fReport);
		Application->CreateForm(__classid(TfMin_vumoga), &fMin_vumoga);
		Application->CreateForm(__classid(TfDodatku), &fDodatku);
		Application->CreateForm(__classid(TfAuthor), &fAuthor);
		Application->CreateForm(__classid(TfDovidka), &fDovidka);
		Application->CreateForm(__classid(TfSvidotc), &fSvidotc);
		Application->CreateForm(__classid(TfReportO), &fReportO);
		Application->CreateForm(__classid(TfAnalituk), &fAnalituk);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
