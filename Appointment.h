//---------------------------------------------------------------------------
#include <string>
#ifndef AppointmentH
#define AppointmentH

using namespace std;
//---------------------------------------------------------------------------
class Appointment
{
	public:
		string values();
		string getDate();
		string getDescription();
		string getStartTime();
		string getEndTime();
		void setAppointment( string , string , string , string );

	private:
		string description;
		string startTime;
		string endTime;
		string date;
};
#endif
