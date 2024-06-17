program p6;
type slog=record inf:integer; sl:^slog; end;
var t,p,pom:^slog; e1,e2:integer;
begin
  read(e1,e2);
  new(t); pom:=t;
  new(t); pom^.sl:=t;
  while not(eof) do
  begin
    read(t^.inf);
    new(p);
    t^.sl:=p;
    t:=p;
  end;
  t:=pom;
  while t^.sl<>nil do
  if t^.sl^.inf=e1 then
  begin
    p:=t^.sl;
    t^.sl:=t^.sl^.sl;
    dispose(p);
  end else
  if t^.sl^.inf=e2 then
  begin
    new(p); p^.inf:=e2;
    p^.sl:=t^.sl^.sl;
    t^.sl^.sl:=p;
    t:=p;
  end else t:=t^.sl;
  pom:=pom^.sl;
  while pom^.sl<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.