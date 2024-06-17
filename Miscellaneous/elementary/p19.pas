{19)u niz spakovati sve delitelje brojeva od 1 do 100}
program p1;
var a:array[1..100] of set of 1..100;
    i,j:integer;
begin
  for i:=1 to 100 do
   for j:=1 to i div 2 do
   if i mod j=0 then a[i]:=a[i]+[j];
  for i:=1 to 100 do
  begin
    write(i,':'); for j:=1 to i div 2 do
    if j in a[i] then write(j,' '); writeln(i);
  end;
end.