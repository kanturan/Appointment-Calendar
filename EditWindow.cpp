//---------------------------------------------------------------------------
#include <vcl.h>
#include <time.h>
#pragma hdrstop

#include "EditWindow.h"
#include "Appointment.h"
#include "IOFile.h"

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{   //changes label 2 to current selected date
	time_t current = time(0);
	tm currentDate = *localtime(&current);
	Form3->Label2->Caption = IntToStr(currentDate.tm_mday) + "/"
								 + IntToStr(currentDate.tm_mon + 1) + "/"
								 + IntToStr(currentDate.tm_year + 1900);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{   //closes edit window
	Form3->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Appointment a;
	IOFile io;

	io.openFileInOut();
	io.fileClear();
	io.filePointerToStart();
	a = io.fileRead( a );

	bool AppointmentExists = false;

    while ( !io.eof() )
	{
		if ( a.getDate().compare( Label2->Caption.t_str() ) == 0 )
		{
			if ( a.getDescription().compare( Edit1->Text.t_str() ) == 0 )
			{
				AppointmentExists = true;
			}
		}
		a = io.fileRead( a );
	}

	if ( AppointmentExists == false )
	{
		ShowMessage( "Appointment does not exist!" );
	}

	else
		if( a.getDescription().compare( Edit1->Text.t_str() ) == 0 )
		{
			io.openFileAppend();
			io.fileClear();

			string e = '\0';
			string st = '\0';
			string et = '\0';
			string d = '\0';

			a.setAppointment( e, st, et, d );

			io.fileWrite( a );
			io.closeFile();
			ShowMessage( "Your Appointment has been edited!" );
		}
}
//---------------------------------------------------------------------------
