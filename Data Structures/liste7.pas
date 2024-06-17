{koristeci stek liste dodati broj na k-to mesto u listi}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p,pom:^slog; i,k:integer;
begin
  new(p);
  while not(eoln) do
  begin
    new(t);
    read(t^.inf);
    t^.sl:=p;
    p:=t;
  end;
  new(pom);
  read(pom^.inf,k);
  for i:=1 to k-2 do t:=t^.sl;
  pom^.sl:=t^.sl;
  t^.sl:=pom;
  while p^.sl<>nil do
  begin
    write(p^.inf,' ');
    p:=p^.sl;
  end;
end.