{ispisati niz brojeva u normalnom poretku koristeci liste}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p,pom:^slog;
begin
  new(t); pom:=t;
  while not(eof) do
  begin
    read(t^.inf);
    new(p);
    t^.sl:=p;
    t:=p;
  end;
  while pom^.sl<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.