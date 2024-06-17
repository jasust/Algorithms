program trik;
var k,i:longint; n:int64;
begin
  readln(k);
  for i:=1 to k do
  begin
    read(n);
    if sqrt(n*8-7)=trunc(sqrt(n*8-7)) then write(1,' ') else write(0,' ');
  end;
end.