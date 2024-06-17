program zakon;
var a:array[1..100] of longint;
    n,i,j,p,s:integer;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if a[i]>a[j] then
    begin
      p:=a[i];
      a[i]:=a[j];
      a[j]:=p;
    end;
  for i:=1 to (n div 2)+1 do s:=s+(a[i] div 2)+1;
  writeln(s);
end.
