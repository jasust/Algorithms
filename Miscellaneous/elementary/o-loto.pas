program loto;
var n,k,i:integer; s:extended;
begin
  read(k,n); s:=1;
  for i:=1 to k do s:=s*(n-i+1)/i;
  writeln(round(s));
end.