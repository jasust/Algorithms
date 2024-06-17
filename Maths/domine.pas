program p1;
var n,i,j,s,k:longint;
b:array[1..100000] of integer;
begin
  readln(n);
  k:=1;
  for i:=1 to n do read(b[i]);
  for i:=2 to n do
  begin
    s:=0;
    for j:=i-1 downto 1 do
    begin
      if b[j]>i-j then
      begin k:=k+1; break; end;
      s:=s+1;
    end;
    if s+1=i then break;
  end;
  writeln(k);
end.


