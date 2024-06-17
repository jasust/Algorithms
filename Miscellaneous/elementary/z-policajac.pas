program policajac;
var n,l,r,i,duz,max:longint;
    a:array[0..1000005] of integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(l,r);
    inc(a[l]);
    dec(a[r+1]);
    if r>duz then  duz:=r;
  end;
  for i:=1 to duz+1 do
  begin
    a[i]:=a[i-1]+a[i];
    if a[i]>max then max:=a[i];
  end;
  writeln(max);
end.