program p1;
type niz=array[1..50] of integer;
var n,m,sum,k,i,j,t:integer;
    a:niz;
begin
  readln(n,m,k);
  for i:=1 to n do
  begin
    read(a[i]);
    dec(a[i]);
    inc(sum,a[i]);
  end;
  inc(sum,k);
  if sum<m then
  begin
    writeln('-1');
    halt(0);
  end;
  sum:=k;
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if a[i]<a[j] then
     begin t:=a[i]; a[i]:=a[j]; a[j]:=t; end;
  i:=1;
  while sum<m do
  begin
    inc(sum,a[i]);
    inc(i);
  end;
  writeln(i-1);
end.
