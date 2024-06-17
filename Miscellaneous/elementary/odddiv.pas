program odddivisor;
var a,b,k:longint;
    sol:qword;
begin
  readln(a,b);
  k:=trunc(sqrt(a));
  if trunc(sqrt(a))<>sqrt(a) then inc(k);
  while k*k<=b do
  begin
    inc(sol,k*k);
    inc(k);
  end;
  writeln(sol);
end.
