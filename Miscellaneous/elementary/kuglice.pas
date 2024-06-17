program p1;
var a:array[1..10000] of longint;
    n,m,max,i,j:longint;
procedure sort;
var p:longint;
begin
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if a[i]>a[j] then
    begin
      p:=a[i];
      a[i]:=a[j];
      a[j]:=p;
    end;
end;
begin
  read(n,m);
  readln;
  for i:=1 to n do read(a[i]);
  while m<>0 do
  begin
  sort;
  while (a[n]>a[n-i]) or (a[1]<a[n-1]) or (m<>0) do
  begin
    m:=m-1;
    a[n]:=a[n]-1;
    a[1]:=a[1]+1;
  end;
  end;
  max:=a[1];
  for i:=1 to n do if a[i]>max then max:=a[i];
  writeln(max);
end.




