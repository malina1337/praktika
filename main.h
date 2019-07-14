//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton7;
        TToolButton *ToolButton4;
        TToolBar *ToolBar3;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TDBGrid *DBGrid1;
        TToolBar *ToolBar2;
        TDBNavigator *DBNavigator1;
        TActionList *ActionList1;
        TAction *FindFam;
        TAction *FindAdres;
        TAction *FindTel;
        TAction *Quit;
        TAction *SortFam;
        TAction *SortAdr;
        TAction *ShowAllRec;
        TDataSource *DataSource1;
        TADOTable *ADOTable1;
        TADOConnection *ADOConnection1;
        TToolButton *ToolButton8;
        TAction *SortTel;
        TADOQuery *ADOQuery1;
        void __fastcall QuitExecute(TObject *Sender);
        void __fastcall SortFamExecute(TObject *Sender);
        void __fastcall SortAdrExecute(TObject *Sender);
        void __fastcall FindFamExecute(TObject *Sender);
        void __fastcall ShowAllRecExecute(TObject *Sender);
        void __fastcall FindAdresExecute(TObject *Sender);
        void __fastcall FindTelExecute(TObject *Sender);
        void __fastcall SortTelExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
