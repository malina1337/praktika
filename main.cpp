//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
class TelBook
  {
    private:
      AnsiString f,
      fn,
      sn;
      TDateTime dr;
      AnsiString adr;
      AnsiString tel;
    public:
      TelBook();
      TelBook(AnsiString f1,
      AnsiString fn1,AnsiString sn1, TDateTime dr1,
      AnsiString adr1, AnsiString tel1);
      AnsiString FilterFIO(AnsiString f1,AnsiString i1,AnsiString o1);
      AnsiString FilterAdr(AnsiString s);
      AnsiString FilterTel(AnsiString s);
  };
TelBook::TelBook()
{
}  
TelBook::TelBook(AnsiString f1,
      AnsiString fn1,AnsiString sn1, TDateTime dr1,
      AnsiString adr1, AnsiString tel1)
{
  f = f1;
  fn = fn1;
  sn = sn1;
  dr = dr1;
  adr = adr1;
  tel = tel1;
}
AnsiString TelBook::FilterFIO(AnsiString f,AnsiString i,AnsiString o)
{
AnsiString s;
  s = "fam Like " + QuotedStr(f + "%");
  if (i != "")
    s = s + " and fname=" + QuotedStr(i);
  if (o != "")
    s = s + " and sname=" + QuotedStr(o);
  return s;  
}
AnsiString TelBook::FilterAdr(AnsiString s)
{
  return "adres Like " + QuotedStr(s + "%");
}
AnsiString TelBook::FilterTel(AnsiString s)
{
  return "tel Like " + QuotedStr(s + "%");
}
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int __fastcall PosEx(AnsiString _find, AnsiString str, int Offset)
{
  str = str.Delete(1,Offset);
  int pos = str.Pos(_find);
  if(pos) return pos+Offset;
  else return 0;
}

void __fastcall TForm1::QuitExecute(TObject *Sender)
//выход из программы
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SortFamExecute(TObject *Sender)
//сортировка по фамилии
{
  ADOTable1->IndexFieldNames = "fam";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SortAdrExecute(TObject *Sender)
//сортировка по адресу
{
  ADOTable1->IndexFieldNames = "adres";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FindFamExecute(TObject *Sender)
//поиск по фамилии
{
AnsiString  s, f, i, o;
TelBook tb;
  s = InputBox("¬вод", "¬ведите фамилию, им€ и отчество", "");
  if (s.Pos(" ") != 0)
    {
      f = s.SubString(1, s.Pos(" ") - 1);
      s = s.Delete(1, s.Pos(" "));
      if (s.Pos(" ") != 0)
        {
          i = s.SubString(1, s.Pos(" ") - 1);
          s = s.Delete(1, s.Pos(" "));
          o = s;
        }
      else
        {
          i = s;
          o = "";
        }
    }
  else
    {
      f = s;
      i = "";
      o = "";
    }
  tb=TelBook(f,i,o,TDateTime("01.01.2011"),"","");
  s=tb.FilterFIO(f,i,o);
  DataSource1->DataSet = NULL;
  DataSource1->DataSet = ADOQuery1;
  ADOQuery1->Close();
  ADOQuery1->SQL->Clear();
  ADOQuery1->SQL->Add("SELECT *");
  ADOQuery1->SQL->Add("FROM data");
  ADOQuery1->SQL->Add("WHERE " + s);
  ADOQuery1->SQL->Add("ORDER BY " + ADOTable1->IndexFieldNames);
  ADOQuery1->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShowAllRecExecute(TObject *Sender)
//показать все записи
{
  ADOQuery1->Close();
  DataSource1->DataSet = ADOTable1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FindAdresExecute(TObject *Sender)
//поиск по адресу
{
AnsiString s;
TelBook tb;
  s = InputBox("¬вод", "¬ведите адрес", "");
  tb = TelBook();
  s=tb.FilterAdr(s);
  DataSource1->DataSet = NULL;
  DataSource1->DataSet = ADOQuery1;
  ADOQuery1->Close();
  ADOQuery1->SQL->Clear();
  ADOQuery1->SQL->Add("SELECT *");
  ADOQuery1->SQL->Add("FROM data");
  ADOQuery1->SQL->Add("WHERE " + s);
  ADOQuery1->SQL->Add("ORDER BY " + ADOTable1->IndexFieldNames);
  ADOQuery1->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FindTelExecute(TObject *Sender)
//поиск по телефону
{
AnsiString s;
TelBook tb;
  s = InputBox("¬вод", "¬ведите телефон", "");
  tb = TelBook();
  s=tb.FilterTel(s);
  DataSource1->DataSet = NULL;
  DataSource1->DataSet = ADOQuery1;
  ADOQuery1->Close();
  ADOQuery1->SQL->Clear();
  ADOQuery1->SQL->Add("SELECT *");
  ADOQuery1->SQL->Add("FROM data");
  ADOQuery1->SQL->Add("WHERE " + s);
  ADOQuery1->SQL->Add("ORDER BY " + ADOTable1->IndexFieldNames);
  ADOQuery1->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SortTelExecute(TObject *Sender)
//сортировка по телефону
{
  ADOTable1->IndexFieldNames = "tel";
}
//---------------------------------------------------------------------------

