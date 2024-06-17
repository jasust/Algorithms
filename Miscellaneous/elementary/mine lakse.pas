program mine1;
var a,d:array[0..50,0..50] of integer;
    n,m,i,j,k,l,x,y:integer;
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
    a[1,i]:=1; l:=0;
    for j:=2 to n do
     for k:=1 to m do
     begin
      y:=d[j-1,k]-a[j-1,k]-a[j-1,k+1]-a[j-1,k-1]-a[j-2,k];
      if (j=2) and (k=m) then y:=y+a[1,m+1];
      if not((y>1) or (y<0)) then begin a[j,k]:=y; inc(l); end;
     end;  writeln(l);
    for j:=1 to m-1 do if a[n,j]=d[n,j]-a[n-1,j]-a[n,j+1]-a[n,j-1] then inc(l);
    if a[n,m]=d[n,m]-a[n-1,m]-a[n,j-1] then inc(l);
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
  if x=0 then writeln('Ne postoji takvo minsko polje');
end.
