{koristeci red liste dodati broj na k-to mesto u listi}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p,pom:^slog; k,i:integer;
begin
  new(t); pom:=t;
  while not(eoln) do
  begin
    read(t^.inf);
    new(p);
    t^.sl:=p;
    t:=p;
  end;
  new(p); t:=pom;
  read(p^.inf,k);
  for i:=1 to k-2 do t:=t^.sl;
  p^.sl:=t^.sl;
  t^.sl:=p;
  while pom^.sl<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.