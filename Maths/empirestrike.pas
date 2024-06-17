{Za zadatih k (k<10^6) brojeva manjih od 10^7 odrediti najmanji broj n takav da
 je p/q prirodan broj, gde je p=n!, a q=a1!*a2!..ak!}
program empire;
const maxn=10000010;
      maxans:int64=9999998000005; //ocigledno je upper bound za n a1+a2+..+ak
var m,cm:int64; n,i,j,x:longint;
    ca,p:array[0..maxn+10] of longint; //slozenost algoritma je maxn*log(maxn)
    kol:array[0..maxn+10] of int64;
    a:array[0..1000500] of longint;

function calc(x,t:int64):int64;
var res:int64;
begin
  res:=0;
  while (x>0)do           // funkcija racuna broj pojavljivanja t u x! //
  begin
    x:=x div t;
    res:=res+x;
  end;
  calc:=res;
end;

function find(x,t:int64):int64;
var mid,ll,rr:int64;
begin                        // binarna pretraga najmanjeg x takvog da t|x!
  ll:=1; rr:=maxans;
  while (ll<rr-1)do
  begin
    mid:=(ll+rr) shr 1;
    if (calc(mid,x)>=t) then rr:=mid else ll:=mid;
  end;
  if (calc(ll,x)>=t) then find:=ll else find:=rr;
end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to maxn do
  begin
    p[i]:=i;
    kol[i]:=0;
    ca[i]:=0;
  end;
  for i:=2 to maxn do
   if p[i]=i then               //broj p[i] drzi najveci prosti delioc broja i
    for j:=i to maxn div i do p[i*j]:=i;
  for i:=1 to n do inc(ca[a[i]]);
  for i:=1 to maxn do   //niz ca nam govori o broju pojavljivanja clanova niza
  begin
    if n=0 then break;
    x:=i;
    while (x>1) do
    begin               //broj kol[i] nam govori koliko puta se i sadrzi u q
      inc(kol[p[x]],n);
      x:=x div p[x];
    end;
    dec(n,ca[i]);
  end;
  m:=1;
  for i:=1 to maxn do
   if (kol[i]<>0) then
   begin
     cm:=find(i,kol[i]);
     if cm>m then m:=cm;  //broj koji zadovoljava sve uslove je resenje
   end;
  writeln(m);
end.
