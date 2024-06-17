{koristeci red liste dodati broj na kraj liste sa brisanjem}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p,pom:^slog;
begin
  new(t); pom:=t;
  while not(eoln) do
  begin
    new(p);
    read(t^.inf);
    t^.sl:=p;
    t:=p;
  end;
  t:=pom;
  while t^.sl^.sl<>nil do t:=t^.sl;
  read(t^.inf);
  while pom^.sl<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.