{ispisati niz brojeva u obrnutom poretku koristeci liste}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p:^slog;
begin
  new(p);
  while not(eof) do
  begin
    new(t);
    read(t^.inf);
    t^.sl:=p;
    p:=t;
  end;
  while t^.sl<>nil do
  begin
    write(t^.inf,' ');
    t:=t^.sl;
  end;
end.