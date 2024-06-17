program kval2a;
var a,b,c:longint;
begin
  read(a,b);
  c:=a-(b div 3) - (b mod 3);
  writeln(c);
end.
