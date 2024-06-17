program heksadec;
var n:integer;
procedure pisi(n:integer);
begin
  if n>=10 then write(chr(ord('A')+n-10))
           else write(n);
end;
begin
  readln(n);
  pisi(n);
end.