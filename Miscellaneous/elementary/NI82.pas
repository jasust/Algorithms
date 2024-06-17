Program ni82;
var a,b:longint;
begin
  read(a,b);
  while (a mod 100<>11) and (a mod 100<>39) and (a mod 100<>61) and (a mod 100<>89) do inc(a);
  while a<=b do
  begin
    if sqr(a) mod 10000=2121 then
    begin
      writeln('MOGUCE');
      break;
    end;
    if a mod 10=9 then inc(a,22) else inc(a,28);
  end;
  if a>b then writeln('NEMOGUCE');
end.
