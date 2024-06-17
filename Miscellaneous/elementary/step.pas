{izracunati n-ti stepen broja a}

program p1;
var a,n:integer;
function step(b,m:integer):integer;
begin
  if m<0 then step:=1/(step(b,abs(m)))
  else if m>0 then step:=b*step(b,m-1)
  else step:=1;
end;
begin
  readln(a,n);
  writeln(step(a,n));
end.