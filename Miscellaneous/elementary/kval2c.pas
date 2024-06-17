program kval3b;
var a,b:ansistring;
    i,br:longint;
begin
  readln(a);
  readln(b);
  if a[1]<>b[1] then br:=1;
  for i:=2 to length(a) do
   if (a[i]<>b[i]) and (a[i-1]=b[i-1]) then inc(br);
  writeln(br);
end.

