//---------------------------------------------------------------------------
#ifndef GUIH
#define GUIH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMonthCalendar *MonthCalendar1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TListBox *ListBox1;
	TLabel *Label4;
	TTimer *ChangeCurrentDateTime;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ChangeCurrentDateTimeTimer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall MonthCalendar1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
