{napisati rekurziju koja odredjuje x na n i rekurziju prvih n brojeva i
izracunati s=x/1 + x^2/1+2 ... x^n/1+2+..n}
program p3;
var x,i,n:integer; s:real;
function step(x,n:integer):longint;
begin
  if n=1 then step:=x else step:=x*step(x,n-1);
end;
function zbir(n:integer):integer;
begin
  if n=1 then zbir:=1 else zbir:=n+zbir(n-1);
end;
begin
  readln(x,n);
  for i:=1 to n do s:=s+step(x,i)/zbir(i);
  write(s);
end.