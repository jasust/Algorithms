program pll;
var a:array[0..100005] of longint;
    n,m,i,c,t,mark,v:longint;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    readln(c,t);
    a[i]:=c*t+a[i-1];
  end;
  mark:=1;
  for i:=1 to m do
  begin
    read(v);
    while v>a[mark] do inc(mark);
    writeln(mark);
  end;
end.


