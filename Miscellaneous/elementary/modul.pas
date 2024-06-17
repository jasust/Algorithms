Program FindTheProduct;
Const modul = 1000000007;
Var Niz : Array [1..100000] of longint;
    i, x, y, N, Q : longint;
    Proizvod : int64;

Function stepen ( Baza, Eksponent : LongInt ) : LongInt;
Var Rezultat : Int64;
Begin
  Rezultat:=1;
  While Eksponent > 0 do
  begin
    If (Eksponent and 1 = 1) then Rezultat:=((Rezultat mod modul)*(Baza mod modul)) mod modul;
    Baza:=((Baza mod modul)*(Baza mod modul)) mod modul;
    Eksponent:=Eksponent shr 1;
  End;
  Stepen:=Rezultat mod modul;
End;

Function Podeli ( a, b, p : LongInt ) : Int64;
Begin
  Podeli:=((a mod p) * (stepen(b,p-2) mod p)) mod p;
End;

Begin
  ReadLn(N,Q);
  Proizvod:=1;
  For i:=1 to N Do
  Begin
    Read(Niz[i]);
    Proizvod:=((Proizvod mod modul)*(Niz[i] mod modul)) mod modul;
  End;
  For i:=1 to Q Do
  Begin
    ReadLn(x,y);
    Proizvod:=((Podeli(Proizvod,Niz[x],modul) mod modul) * (y mod modul)) mod modul;
    WriteLn(Proizvod);
    Niz[x]:=y;
  End;
End.