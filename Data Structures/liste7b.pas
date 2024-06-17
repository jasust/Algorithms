{koristeci stek liste dodati broj na k-to mesto u listi sa brisanjem}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p:^slog; i,k,n:integer;
begin
  new(p);
  while not(eoln) do
  begin
    new(t);
    read(t^.inf);
    t^.sl:=p;
    p:=t;
  end;
  read(n,k);
  for i:=1 to k-1 do t:=t^.sl;
  t^.inf:=n;
  while p^.sl<>nil do
  begin
    write(p^.inf,' ');
    p:=p^.sl;
  end;
end.