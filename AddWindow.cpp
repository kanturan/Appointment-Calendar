//---------------------------------------------------------------------------
#include <vcl.h>
#include <time.h>
#pragma hdrstop

#include "AddWindow.h"
#include "Appointment.h"
#include "IOFile.h"

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{   //changes label 6 to current selected date
	time_t current = time(0);
	tm currentDate = *localtime(&current);
	Form2->Label6->Caption = IntToStr(currentDate.tm_mday) + "/"
								 + IntToStr(currentDate.tm_mon + 1) + "/"
								 + IntToStr(currentDate.tm_year + 1900);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{   //adds constraints
	string sh = Edit2->Text.t_str();
	string sm = Edit3->Text.t_str();
	string eh = Edit4->Text.t_str();
	string em = Edit5->Text.t_str();
	string co = Label2->Caption.t_str();
	string cl = Label4->Caption.t_str();
	string startTime = sh + co + sm;
	string endTime = eh + cl + em;

	if ( Edit1->Text == "" )
	{
		ShowMessage( "Appointment Description should not be blank." );
	}
	else if ( Edit2->Text == "")
	{
		ShowMessage( "Start Hour should not be blank." );
	}
	else if ( Edit2->Text < "0" || Edit2->Text >= "23" )
	{
		ShowMessage( "Hours are only from 00 to 23." );
	}
	else if ( Edit3->Text == "")
	{
		ShowMessage( "Start Minute should not be blank." );
	}
	else if ( Edit3->Text < "0" || Edit3->Text >= "60" )
	{
		ShowMessage( "Minutes are only from 00 to 59." );
	}
	else if ( Edit4->Text == "")
	{
		ShowMessage( "End Hour should not be blank." );
	}
	else if ( Edit4->Text < "0" || Edit4->Text >= "24" )
	{
		ShowMessage( "Hours are only from 00 to 23." );
	}
	else if ( Edit5->Text == "" )
	{
		ShowMessage( "End Minute should not be blank." );
	}
	else if ( Edit5->Text < "0" || Edit5->Text >= "60" )
	{
		ShowMessage( "Minutes are only from 00 to 59." );
	}
	else if ( startTime >= endTime )
	{
		ShowMessage( "The End Time should not be earlier or the same as Start Time" );
	}
	else
	{
		Appointment a;
		IOFile io;

		io.openFileInOut();
		io.fileClear();
		io.fileSeekG();
		a = io.fileRead( a );

		bool AppointmentExists = false;

		while ( !io.eof() )
		{
			if ( a.getDate().compare( Label6->Caption.t_str() ) == 0 )
			{
				if ( a.getDescription().compare( Edit1->Text.t_str() ) == 0 )
				{
					if ( a.getStartTime().compare( startTime ) == 0 )
					{
						AppointmentExists = true;
					}
				}
			}
			a = io.fileRead( a );
		}

		io.fileClear();
		io.fileSeekG();
		a = io.fileRead( a );

		bool timeOccupied = false;

		while ( !io.eof() )
		{
			if ( a.getDate().compare( Label6->Caption.t_str() ) == 0 )
			{
				if ( a.getStartTime().compare( startTime ) <= 0
					&& a.getEndTime().compare( startTime ) > 0 )
				{
					timeOccupied = true;
				}
			}
			a = io.fileRead( a );
		}
		io.closeFile();

		if ( AppointmentExists == true )
		{
			ShowMessage( "Appointment already exists!" );
		}
		else
		{
			if ( timeOccupied == true )
			{
				ShowMessage( "You already have an Appointment at that time!" );
			}
			else
			{
				io.openFileAppend();
				io.fileClear();

				string e = Edit1->Text.t_str();
				string st = startTime;
				string et = endTime;
				string d = Label6->Caption.t_str();

				//adds appointments to the file
				a.setAppointment( e, st, et, d );

				io.fileWrite( a );
				io.closeFile();
				ShowMessage( "Your Appointment has been added!" );
			}
		}
	}
	Form2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{   //closes add window
	Form2->Visible = false;
}
//---------------------------------------------------------------------------
