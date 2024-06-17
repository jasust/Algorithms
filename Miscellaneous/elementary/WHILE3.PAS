Program P3;
var n,a,b:longint;
begin
  read(n);
  b:=0;
  while n>0 do
  begin
    a:=n mod 10;
    if a=3 then b:=b+1;
    n:=n div 10;
  end;
  writeln(b);
end.