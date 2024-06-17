{Odrediti koliko ima odlicnih brojeva duzine n<=10^6.Broj je odlican akko su
 on i zbir njegovih cifara lepi. Broj je lep akko se sastoji od cifara a i b.}
program beautiful;
const m=1000000007;     //resenje stampati po modulu 10^9+7
var a,b,n,i,j:longint;  //algoritam je slozenosti O(n*log(modul))
    ans,bin,inv:int64;
    d:array[0..1000000]of int64;

function Check(x:longint):boolean; //ova procedura proverava da li je broj lep
begin                              //proveravajuci mu sve cifre
  while x>0 do
  begin
    if (x mod 10 <> a) and (x mod 10 <> b) then
    begin
      Check:=false;
      exit;
    end;
    x:=x div 10;
  end;
  Check:=true;
end;

function step(a:int64;n:longint):int64;   //procedura za brzo stepenovanje
var res:int64;
begin
  res:=1;
  while n>=1 do
  begin
    if n mod 2 = 1 then res:=res*a mod m;
    a:=a*a mod m;
    n:=n div 2;
  end;
  step:=res;
end;

begin
  readln(a,b,n);     //niz d nam drzi vrednosti faktorijela po modulu m
  d[0]:=1; d[1]:=1;
  if (a=b) then   //ako je a=b samo jedan broj je lep,
  begin           // pa proveravamo da li je i odlican
    if Check(n*a) then writeln('1') else writeln('0');
    exit;
  end;
  for i:=2 to n do d[i]:=(d[i-1]*i) mod m;
  for i:=0 to n do
   if Check(i*a+(n-i)*b) then //ako broj sadrzi i cifara a tada ima n-i cifara b
   begin                      //ako je jedan broj tog oblika odlican tada su i
     bin:=d[i]*d[n-i] mod m;  //svi ostali odlicni.Takvih brojeva ima n 'nad' i
     inv:=step(bin,m-2);
     ans:=(ans + (d[n]*inv mod m)) mod m;
   end;
  writeln(ans);
end.
