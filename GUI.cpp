//---------------------------------------------------------------------------
#include <vcl.h>
#include <time.h>
#include <string>
#pragma hdrstop

#include "GUI.h"
#include "AddWindow.h"
#include "Appointment.h"
#include "IOFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeCurrentDateTimeTimer(TObject *Sender)
{	//changes time of Label 2 and 3 to the current time
	time_t current = time(0);
	tm currentTime = *localtime(&current);

	Label3->Caption = IntToStr(currentTime.tm_hour) + ":"
					  + IntToStr(currentTime.tm_min);
	Label2->Caption = IntToStr(currentTime.tm_mday)  + "/"
					  + IntToStr((currentTime.tm_mon) + 1 ) + "/"
					  + IntToStr((currentTime.tm_year) + 1900);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MonthCalendar1Click(TObject *Sender)
{
	TMonthCalendar* tmc = ( TMonthCalendar* ) Sender;
	TDateTime tdt = tmc->Date;
	//changes date of the newly opened window to the selected date
	Form2->Label6->Caption = tdt.DateString();

	ListBox1->Clear();

	Appointment a;
	IOFile io;

	io.openFileInOut();
	io.fileClear();
	io.fileSeekG();
	a = io.fileRead(a);
	bool haveAppointments = false;

	while ( !io.eof() )
	{
		if ( a.getDate().compare( tdt.DateString().t_str() ) == 0 )
		{
			//adds the values in the listbox
			ListBox1->Items->Append( a.values().c_str() );

			haveAppointments = true;

			if ( haveAppointments == true )
			{
				Label4->Visible = true;
			}
		}
		else
		{
			haveAppointments == false;
		}
		a = io.fileRead(a);
	}
	io.closeFile();

	ListBox1->Sorted = true;

	if ( haveAppointments == false )
	{
		ListBox1->Items->Append("There are no Appointments on  " + tdt.DateString());
		Label4->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{   //creates a file when form1 is created
	IOFile io;
	io.createFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{	//opens add window
	Form2->Visible = true;
	Form2->Button1->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	//deletes the items in the listbox
	ListBox1->DeleteSelected();
	ShowMessage("Your Appointment has been Deleted!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{   //closes the form
	Close();
}
//----------------------------------------------------------------- ----------

