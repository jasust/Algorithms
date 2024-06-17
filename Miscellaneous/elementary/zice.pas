program zice;
var a,b,min:extended;
    k,l,pom:longint;
begin
  read(a,b);
  min:=a;
  while (a>(b/3)) do
  begin
    if a>b then
    begin
      a:=a/3;
      inc(k);
      inc(l);
    end else
    if l>0 then begin a:=2*a; dec(l); end else break;
    if abs(a-b)<abs(min-b) then begin min:=a; pom:=k; end;
  end;
  writeln(pom);
  write(min:0:5);
end.
