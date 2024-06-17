Program spirals;
var a:array[1..200,1..200] of integer;
    b:array[1..100] of integer;
    t,i,k,c,m,q,w:integer;
procedure ram(var x:integer);
var i:integer;
begin
  for i:=1 to x do begin a[m+1,i+m]:=k; k:=k+1; end;
  for i:=2 to x do begin a[i+m,x+m]:=k; k:=k+1; end;
  for i:=x-1 downto 1 do begin a[x+m,i+m]:=k; k:=k+1; end;
  for i:=x-1 downto 2 do begin a[i+m,m+1]:=k; k:=k+1; end;
end;
begin
  readln(t);
  for i:=1 to t do readln(b[i]);
  for i:=1 to t do
  begin
    k:=1; c:=b[i]; m:=0;
    while c>0 do begin ram(c); c:=c-2; m:=m+1; end;
    for q:=1 to b[i] do
    begin
      for w:=1 to b[i] do write(a[q,w],' ');
      writeln;
    end;
    writeln;
  end;
end.

