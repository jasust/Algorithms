program pp;
var a,b,c,sol:longint;
begin
  b:=2; a:=2;
  while a<=1000000 do
  begin
    c:=2;
    while (a mod c=0) and (c<=b) do
    begin
      inc(c);
      if c=b then sol:=a;
    end;
    inc(a);
    if a=(b+1)*(b+1)*(b+1) then inc(b);
  end;
  writeln(sol);
end.