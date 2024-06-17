{koristeci stek liste dodati broj na pocetak sa brisanjem}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p:^slog;
begin
  new(p);
  while not(eoln) do
  begin
    new(t);
    read(t^.inf);
    t^.sl:=p;
    p:=t;
  end;
  read(t^.inf);
  while p^.sl<>nil do
  begin
    write(p^.inf,' ');
    p:=p^.sl;
  end;
end.
