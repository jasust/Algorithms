program p3;
var n,s,i,j:longint;
    st:ansistring;
begin
  readln(n);
  for i:=1 to 10 do
  begin
    readln(st);
    s:=0;
    for j:=1 to length(st) do
     s:=((10*s mod n)+((ord(st[j])-ord('0')) mod n)) mod n;
    if s=0 then writeln('DA') else writeln('NE');
  end;
end.