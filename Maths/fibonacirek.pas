{koliko se puta funkcija vraca za racun n-tog clana fibonacijevog niza}
program p4;
var n,k:integer;
function fib(n:integer):integer;
begin
  if (n=1) or (n=2) then fib:=1
  else begin
  fib:=fib(n-1)+fib(n-2);
  k:=k+1;
  end;
end;
begin
  readln(n);
  fib(n);
  writeln(k);
end.
