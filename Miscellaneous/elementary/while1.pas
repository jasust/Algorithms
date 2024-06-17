Program P1;
var n,S:longint;
begin
  read(n);
  S:=0;
  while n>0 do
  begin
    S:=S+(n mod 10);
    n:=n div 10;
  end;
  writeln(S);
end.