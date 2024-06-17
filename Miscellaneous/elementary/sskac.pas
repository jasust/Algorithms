{Kada plesac skoci na neko polje matrice od 0 i 1 sva ona polja koja imaju zajednicku
 straicu i samo to polje menjaju broj. Gde plesac treba da skoci da bi svuda bile jedinice}
program skakac;
var a,d,e:array[0..50,0..50] of integer;
    n,m,i,j,k,l,x:integer;
begin
  readln(n,m);
  for k:=1 to n do
   for j:=1 to m do read(d[k,j]);
  repeat
  begin
    i:=1;
    while a[1,i]<>0 do
    begin
      a[1,i]:=0;
      inc(i);
    end;
    a[1,i]:=1; e:=d; l:=0;
    for j:=1 to m-1 do if a[1,j]=1 then
    begin
      e[1,j-1]:=e[1,j-1]+1 mod 2;
      e[1,j]:=e[1,j]+1 mod 2;
      e[1,j+1]:=e[1,j+1]+1 mod 2;
      e[2,j]:=e[2,j]+1 mod 2;
    end;
    if a[1,m]=1 then begin e[1,m-1]:=e[1,m-1]+1 mod 2; e[1,m]:=e[1,m]+1 mod 2; e[2,m]:=e[2,m]+1 mod 2; end;
    for j:=2 to n do
     for k:=1 to m do if e[j-1,k]=0 then
     begin
       a[j,k]:=1;
       e[j-1,k]:=1;
       e[j,k-1]:=e[j,k-1]+1 mod 2;
       e[j,k]:=e[j,k]+1 mod 2;
       e[j,k+1]:=e[j,k+1]+1 mod 2;
       e[j+1,k]:=e[j+1,k]+1 mod 2;
     end else a[j,k]:=0;
    for j:=1 to n do
    for k:=1 to m do if e[j,k]=1 then inc(l);
    if l=m*n then
    begin
     inc(x); writeln(x,')');
     for j:=1 to n do
     begin
      for k:=1 to m do write(a[j,k],' ');
      writeln;
     end;
    end;
  end;
  until a[1,m+1]=1;
  if x=0 then writeln(-1);
end.
