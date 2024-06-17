{Zadati broj ljudi n(3<=n<=48) koji je sigurno deljiv sa 3 podeliti u grupe od
 po 3 clana tako da su svih m zelja ispunjene. Ako nema resenja ispisati -1}
program coach;
var i,j,m,n,t,x,y:longint;            // algoritam je slozenosti n^2 sto
    a:array[0..50,0..50] of longint;  // je ujedno najbolje moguce resenje
    b,c,d:array[0..1001] of longint;  // ovog problema

procedure tt(x:longint);  // procedura tt kreira timove
var i:longint;
begin
  inc(d[t]);         //niz d[i] nam kazuje koliko clanova ima u i-tom timu
  if d[t]>3 then
  begin
    writeln(-1);    //ako u nekom timu ima vise od 3 clana tada nema resenja
    halt;
  end;
  c[x]:=t;         //niz c[i] nam kazuje u kom timu se nalazi i-ti covek
  for i:=1 to n do
   if (a[x,i]=1) and (c[i]=0) then tt(i);
end;

begin
  read(n,m);
  for i:=1 to m do
   begin
    read(x,y);
    a[x,y]:=1; //matrica a[i,j] predstavlja matricu povezanosti
    a[y,x]:=1;
    inc(b[x]); //niz b[i] nam govori sa koliko ljudi i-ti zeli da bude u timu
    inc(b[y]);
   end;
  for i:=1 to n do
   if (c[i]=0) and (b[i]>0) then
   begin
     inc(t);   //t je broj timova
     tt(i);
   end;
  if t>n div 3 then begin writeln(-1); halt; end; //ako ima vise timova od trecine
  t:=n div 3;                             //ukupnog broja ljudi ni tad nema resenja
  for i:=1 to t do                     //
  begin                                //
    for j:=1 to n do                   //
     if (c[j]=i) then write(j,' ');    //
    for j:=1 to n do                   //
     begin                             //            ispis
      if d[i]=3 then break;            //
      if c[j]>0 then continue;         //
      c[j]:=i; inc(d[i]); write(j,' ');//
     end;                              //
    writeln;                           //
  end;
end.
