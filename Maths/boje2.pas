program BOJE;
var n,b:longint;
begin
  readln(n);
  b:=(n*n*n*n-6*n*n*n+23*n*n-18*n+24) div 24;
  writeln(b);
end.