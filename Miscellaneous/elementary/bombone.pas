program bombone;
var a:array[1..100000] of longint;
    i,j,k,l,s:longint; sol:int64;  n:integer;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  if n=1 then writeln(1) else
  begin
  sol:=3*n-3;
  for i:=4 to n do
   for j:=1 to n-i+1 do
   begin
     s:=0;
     for k:=j to j+i-2 do
      for l:=k+1 to j+i-1 do
       if a[k]=a[l] then begin s:=s+1; break; end;
     if i-s<4 then sol:=sol+1;
   end;
  writeln(sol);
  end;
end.