{koristeci red liste dodati broj na k-to mesto u listi sa brisanjem}
program lista;
type slog=record inf:integer; sl:^slog; end;
var t,p,pom:^slog; k,i,n:integer;
begin
  new(t); pom:=t;
  while not(eoln) do
  begin
    read(t^.inf);
    new(p);
    t^.sl:=p;
    t:=p;
  end;
  t:=pom;
  read(n,k);
  for i:=1 to k-1 do t:=t^.sl;
  t^.inf:=n;
  while pom^.sl<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.