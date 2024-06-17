program staza;
var b,d:array [1..4] of longint;
    isk:array [0..1000,1..4] of longint;
    pun:array [0..1000] of boolean;
    i,j,n:longint;
begin
  readln(n); pun[0]:=true;
  for i:=1 to 3 do read(d[i],b[i]);
  for i:=1 to n do
   for j:=1 to 3 do
    if (d[j]<=i) and (b[j]-isk[i-d[j],j]>0) then
     if pun[i-d[j]] then
     begin
       pun[i]:=true;
       isk[i]:=isk[i-d[j]];
       inc(isk[i,j]);
     end;
  if pun[n] then
  begin
    writeln('MOGUCE');
    for i:=1 to 3 do
     for j:=1 to isk[n,i] do write(i,' ');
  end else writeln('NEMOGUCE');
end.