//---------------------------------------------------------------------------
#pragma hdrstop
#include <fstream>
#include <string>
#include "Appointment.h"
#include "IOFile.h"
//---------------------------------------------------------------------------
void IOFile::createFile()
{
	fstream MyFile( FILE_PATH, ios :: binary | ios :: in | ios :: out );
	if (!MyFile)
	{
		fstream MyFile( FILE_PATH, ios :: binary | ios :: out );
		MyFile.close();
	}
}
//---------------------------------------------------------------------------
void IOFile::openFileAppend()
{
	MyFile.open( FILE_PATH, ios :: binary | ios :: app );
}
//---------------------------------------------------------------------------
void IOFile::openFileInOut()
{
	MyFile.open( FILE_PATH, ios :: binary | ios :: in | ios :: out );
}
//---------------------------------------------------------------------------
void IOFile::closeFile()
{
	MyFile.close();
}
//---------------------------------------------------------------------------
void IOFile::fileClear()
{
	MyFile.clear();
}
//---------------------------------------------------------------------------
void IOFile::fileSeekG()
{
	MyFile.seekg( 0, ios :: beg );
}
//---------------------------------------------------------------------------
void IOFile::fileWrite( Appointment a )
{
	MyFile.write( ( char* ) &a, sizeof( Appointment )) ;
}
//---------------------------------------------------------------------------
Appointment IOFile::fileRead( Appointment a )
{
	MyFile.read( ( char* ) &a, sizeof( Appointment ) );

	return a;
}
//---------------------------------------------------------------------------
bool IOFile::eof()
{
	if ( !MyFile.eof() )
		return false;
	else
		return true;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
