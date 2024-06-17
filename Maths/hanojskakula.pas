program p1;
var b:integer;

procedure prebaci(n,sa,na,pom:integer);
begin
  if n>0 then
  begin
    prebaci(n-1,sa,pom,na);
    writeln(sa,'->',na);
    prebaci(n-1,pom,na,sa);
  end;
end;

begin
  readln(b);
  prebaci(b,1,3,2);
end.

