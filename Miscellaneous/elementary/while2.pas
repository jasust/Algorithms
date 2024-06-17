Program P2;
var n,a,b:longint;
begin
  read(n);
  a:=0;
  while n>0 do
  begin
    b:=n mod 10;
    n:=n div 10;
    a:=a*10 + b
  end;
  writeln(a);
end.