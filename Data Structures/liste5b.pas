{koristeci stek liste dodati broj na kraj liste sa brisanjem}
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
  while p^.sl^.sl<>nil do p:=p^.sl;
  read(p^.inf);
  while t^.sl<>nil do
  begin
    write(t^.inf,' ');
    t:=t^.sl;
  end;
end.