program test;
var x:longint;
begin
  while not eof do
  begin
    readln(x);
    if x=42 then break;
    writeln(x);
  end;
end.