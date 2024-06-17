Program Z2;
var k:longint;
    c:char; ul,iz:text;
begin
  assign(ul,'Zadatak 021112 2.in');
  assign(iz,'Zadatak 021112 2.out');
  reset(ul); rewrite(iz);
  while not eof(ul) do
  begin
    while not eoln(ul) do
    begin
      readln(ul,c);
      if c>='0' then inc(k);
    end;
    writeln (iz,k);
    k:=0;
    readln(ul,c);
  end;
  close(ul); close(iz);
end.
