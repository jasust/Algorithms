{koristeci red liste dodati broj na pocetak liste}
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
  new(t);
  read(t^.inf);
  t^.sl:=pom;
  while t^.sl<>nil do
  begin
    write(t^.inf,' ');
    t:=t^.sl;
  end;
end.