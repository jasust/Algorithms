Program p1;
var d,s:array[1..1001] of longint;
    m,k,g,v,i,max,j:longint;
begin
  readln(m,k);
  for i := 1 to m do read(d[i]);
  for i := 1 to m do read(s[i]);
  for i := 1 to m do
  begin
    g:=g+s[i]-d[i];
    while g<0 do
    begin
      for j:=1 to i do if s[j]>max then max:=s[j];
      inc(g,max);
      inc(v,k);
    end;
    inc(v,d[i]);
  end;
  writeln(v);
end.
