program  p4;
var max,i,j,n,s,idx:integer;
begin
  max:=-1;
  for i:=1 to 5 do
  begin
  s:=0;
  for j:=1 to 4 do
  begin
    read(n);
    s:=s+n;
  end;
  if s>max then begin max:=s; idx:=i; end;
  end;
  writeln(idx,' ',max);
end.

