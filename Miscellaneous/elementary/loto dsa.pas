program loto;
var a,b:array[1..7] of integer; i,j,k:integer;
procedure razmeni(var x,y:integer);
var p:integer;
begin
  p:=x;
  x:=y;
  y:=p;
end;
begin
  for i:=1 to 7 do read(a[i]);
  for i:=1 to 7 do read(b[i]);
  for i:=1 to 6 do
   for j:=i+1 to 7 do
   begin
     if a[i]>a[j] then razmeni(a[i],a[j]);
     if b[i]>b[j] then razmeni(b[i],b[j]);
   end;
  for i:=1 to 7 do if a[i]=b[i] then k:=k+1;
  if k=7 then writeln('Win') else writeln('Lose');
end.