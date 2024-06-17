{koristeci red liste dodati broj na pocetak liste sa brisanjem}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p,pom:^slog;
begin
  new(t); pom:=t;
  while not(eoln) do
  begin
    read(t^.inf);
    new(p);
    t^.sl:=p;
    t:=p;
  end;
  read(pom^.inf);
  while pom^.sl<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.