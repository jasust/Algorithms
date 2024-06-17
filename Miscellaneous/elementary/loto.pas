program loto;
var n,k,i:integer;
function fak(s:integer):qword;
var f:qword;
begin
  f:=1;
  for i:=1 to s do f:=f*i;
  fak:=f;
end;
begin
  read(k,n);
  if n<>k then
  writeln(fak(n)/(fak(k)*fak(n-k))) else write(1);
end.
