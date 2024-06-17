{Izracunati x/1!-x^2/2!+x^3/3!-x^4/4!+...+(-1)^n+1*x^n/n!}
program p1;
var n,k,x,i,p:integer;
    s:real;
function na(n,k:integer):integer;
begin
  if k=0 then na:=1 else na:=n*na(n,k-1);
end;
function fac(n:integer):integer;
begin
   if n=1 then fac:=1 else fac:=n*fac(n-1);
end;

begin
  readln(x,n);
  for i:=1 to n do
  begin
     p:=na(x,i);
     k:=fac(i);
     if i mod 2=0 then s:=s-p/k
     else s:=s+p/k;
  end;
  write(s:0:2);
end.
