program p1;
var n,k,i:integer;
    a:array[1..100] of char;
begin
  readln(n); read(a[1]);
  for i:=2 to n do
  begin
    read(a[i]);
    if a[i]=a[i-1] then inc(k);
  end;
  writeln(k);
end.
