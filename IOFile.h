//---------------------------------------------------------------------------
#ifndef IOFileH
#define IOFileH
#include<fstream>
#include "Appointment.h"
//---------------------------------------------------------------------------
const char FILE_PATH[] = "d:\\iofile";
fstream MyFile( FILE_PATH, ios :: binary | ios :: in | ios :: out );
ifstream File;
class IOFile
{
	public:
		void createFile();
		void openFileAppend();
		void openFileInOut();
		void closeFile();
		void fileClear();
		void fileSeekG();
		void fileWrite( Appointment );
		Appointment fileRead( Appointment );
		bool IOFile::eof();
};
#endif
