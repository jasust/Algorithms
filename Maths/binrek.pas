program binarni;
var n:integer;
procedure normalno(n:integer);
begin
  if n>1 then normalno(n div 2);
  write(n mod 2);
end;
procedure inverzno(n:integer);
begin
  write(n mod 2);
  if n>1 then inverzno(n div 2);
end;
begin
  readln(n);
  normalno(n);
  writeln;
  inverzno(n);
end.