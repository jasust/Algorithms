Program P5;
var n,a,m,z,x:longint;
begin
  read(n);
  a:=1;
  m:=n;
  z:=n mod 10;
  while n>=10 do
  begin
    n:=n div 10;
    a:=a*10;
  end;
  x:=m-n*a-z+z*a+n;
  write(x);
end.