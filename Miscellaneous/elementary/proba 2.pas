program p1;
var a:array[1..100,1..100] of integer;
    x,y,k,i,j:integer;
begin
  readln(x,y); a[x,y]:=1;
  readln(x,y); a[x,y]:=2;
  while not(eoln()) do begin read(x,y); k:=k+1; a[x,y]:=3; end;
  writeln;
  while not(eoln()) do begin read(x,y); a[x,y]:=4; end;
  for i:=1 to 8 do      begin writeln;
  for j:=1 to 8 do write(a[i,j]); end;
end.