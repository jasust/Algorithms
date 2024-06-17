{ispisati spiralnu matricu dimenzije MxN}
program p1;
var a:array[1..100,1..100] of integer;
    m,k,t,n,i,j,b,c:integer;
procedure ram(var x,y:integer);
var i:integer;
begin
  for i:=1 to y do begin a[t+1,i+t]:=k; k:=k+1; end;
  for i:=2 to x do begin a[i+t,y+t]:=k; k:=k+1; end;
  for i:=y-1 downto 1 do begin a[x+t,i+t]:=k; k:=k+1; end;
  for i:=x-1 downto 2 do begin a[i+t,t+1]:=k; k:=k+1; end;
end;
begin
  readln(m,n); b:=m; c:=n; k:=1;
  while (m>0) and (n>0) do begin ram(m,n); m:=m-2; n:=n-2; t:=t+1; end;
  for i:=1 to b do
  begin
   for j:=1 to c do write(a[i,j],' ');
   writeln;
  end;
end.
