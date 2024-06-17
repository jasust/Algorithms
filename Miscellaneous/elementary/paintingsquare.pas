{Odrediti na koliko nacina se moze objiti kvadratna matrica duzine n<=10^9 u k<=1000
 poteza. Ima q<=10^5 upita. Jedan potez je biranje kvadratne podmatrice duzine
 bar 2 koja ne sadrzi nijedno obojeno polje i obojiti njen srednji red i kolonu.}
program painting;
const modul = 7340033;   //resenje stampati po modulu 734033
var n,t,i,j,k,u,v:longint;              //slozenost je konstantna O(64000000)
    F:array[0..32,0..1001,1..4] of longint;
                                       //                      F[i,j,k]
function cal(u:longint):longint;       //i-koliko poteza u dubinu je najvise moguce napraviti
begin                                  //j-koliko poteza pravimo
  if (u=1) or (u mod 2=0) then exit(0);//k-stepen matrice F[i,j]
  exit(cal(u shr 1) + 1) ;
end;   //funkcija cal rekurzivno racuna koliko poteza u dubinu mozemo da napravimo
       //parne matrice nemaju srednji red i kolonu,pa je tada cal=0
begin
  for i := 0 to 32 do F[i,0,4]:=1; //za 0 poteza postoji samo jedan nacin
  for i := 1 to 32 do
   for j := 1 to 1000 do
   begin                     //posto se svaka matrica deli na 4 dela tada je
     F[i,j,1]:=F[i-1,j-1,4]; //ukupan broj nacina za deljenje jednak broju nacina
     for t:=2 to 4 do        //deljenja jednog dela na cetvrti stepen
      for k:=0 to j do F[i,j,t]:=(F[i,j,t]+int64(F[i,j-k,t-1])*F[i-1,k,4]) mod modul;
   end;                    // stepenovanje matrice //
  read(n);
  for i := 1 to n do
  begin
    read(u,v);
    writeln(F[cal(u),v,4]);
  end;
end.
