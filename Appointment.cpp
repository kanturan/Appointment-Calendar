//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Appointment.h"
#include "IOFile.h"

using namespace std;
//---------------------------------------------------------------------------
string Appointment::values()
{
	return description  + "                                                         " + startTime  + "                     " + endTime;
}
//---------------------------------------------------------------------------
string Appointment::getDate()
{
	return date;
}
//---------------------------------------------------------------------------
string Appointment::getDescription()
{
	return description;
}
//---------------------------------------------------------------------------
string Appointment::getStartTime()
{
	return startTime;
}
//---------------------------------------------------------------------------
string Appointment::getEndTime()
{
	return endTime;
}
//---------------------------------------------------------------------------
void Appointment::setAppointment( string de, string st, string et, string d )
{
	description = de;
	startTime = st;
	endTime = et;
	date = d;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
