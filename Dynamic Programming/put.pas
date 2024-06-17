Program dinamicko_programiranje;
var a,d:array[1..50,1..50] of integer;
    i,j,n,m:integer;
begin
  readln(n,m);
  for i:=1 to n do
   for j:=1 to m do read(a[i,j]);
  d[1,1]:=a[1,1];
  for j:=2 to m do d[1,j]:=d[1,j-1]+a[1,j];
  for i:=2 to n do d[i,1]:=d[i-1,1]+a[i,1];
  for j:=2 to m do
   for i:=2 to n do
    if d[i-1,j]>d[i,j-1] then d[i,j]:=d[i-1,j]+a[i,j] else d[i,j]:=d[i,j-1]+a[i,j];
  while (i<>1) or (j<>1) do
  begin
    if d[i,j-1]>d[i-1,j] then
    begin
      write('(',i,',',j,')',' ');
      j:=j-1;
    end
    else
    begin
      write('(',i,',',j,')',' ');
      i:=i-1;
    end;
  end;
  write('(1,1)');
end.
