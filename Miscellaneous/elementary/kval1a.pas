program kdelioci;
var n,i,c : longint;
k : longint; s : real;
begin
  readln(n);
  s:= n+1; c:= 2;
  for i:=2 to trunc(sqrt(n)) do
  begin
    if n mod i = 0 then
    begin
      c:= c + 1;
      if(n div i <> i) then
      begin
        s:= s + i + n div i;
        c:= c + 1;
      end
      else s:= s + i;
    end;
  end;
  writeln(s/c:2:2);
end.