program menhetn;
var x,y:array[0..1000] of longint;
    n,i,j,min:integer;
begin
  readln(n);
  for i:=1 to n do read(x[i],y[i]);
  min:=maxint;
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if abs(x[i]-x[j])+abs(y[i]-y[j])<min then min:=abs(x[i]-x[j])+abs(y[i]-y[j]);
  writeln(min);
end.