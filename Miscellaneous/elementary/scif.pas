{izracunati zbir cifara broja n}

program p1;
var n:integer;
function scif(x:integer):integer;
begin
  if x=0 then scif:=0
  else scif:=(x mod 10) + scif(x div 10);
end;
begin
  readln(n);
  writeln(scif(n));
end.