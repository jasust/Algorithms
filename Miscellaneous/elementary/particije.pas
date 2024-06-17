program p1;
var n,s,i,j:integer;
begin
  readln(n);
  s:=2;
  for i:=2 to n do s:=s*2;
  for i:=1 to s do
   for j:=1 to n-1 do if (i and shl(j)) then writeln(i);
end.
