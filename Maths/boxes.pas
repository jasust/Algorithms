program boxes;
var x1,x2,z1,y1,y2,z2:integer;
procedure razmeni(var a,b:integer);
var p:integer;
begin
  p:=a;
  a:=b;
  b:=p;
end;
begin
  readln(x1,y1,z1);
  if x1>y1 then razmeni(x1,y1);
  if x1>z1 then razmeni(x1,z1);
  if y1>z1 then razmeni(y1,z1);
  readln(x2,y2,z2);
  if x2>y2 then razmeni(x2,y2);
  if x2>z2 then razmeni(x2,z2);
  if y2>z2 then razmeni(y2,z2);
  if ((x1>x2) and (y1>y2) and (z1>z2)) or ((x1<x2) and (y1<y2) and (z1<z2)) then
   writeln('DA') else writeln('NE');
end.
