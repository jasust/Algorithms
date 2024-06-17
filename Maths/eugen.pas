program p1;
var n,m,x,l,r,i,neg,poz:longint;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    read(x);
    if x=-1 then inc(neg) else inc(poz);
  end;
  for i:=1 to m do
  begin
    readln(l,r);
    if ((r-l+1) mod 2 = 0) and (neg>=(r-l+1) shr 1) and (poz>=(r-l+1) shr 1)
     then writeln(1) else writeln(0);
  end;
end.