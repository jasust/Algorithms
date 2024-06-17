{Napisati program koji formira dve stek liste. Formirati trecu koja sadrzi
 elemente koje se pojavljuju vise od jednom u prvoj od druge liste}
program p1;
type pok=^slog;
     slog=record inf:integer; sl:pok; end;
var t,p,s,pom,b:pok; k:integer;

procedure del(var s:pok);
begin
  b:=pom;
  if s=pom then
  begin
    pom:=pom^.sl;
    s:=pom;
    exit;
  end else
  begin
    while b^.sl<>s do b:=b^.sl;
    b^.sl:=s^.sl;
    dispose(s);
    s:=b^.sl;
  end;
end;

begin
  new(p); p:=nil;
  while not(eoln) do
  begin
    new(t);
    read(t^.inf);
    t^.sl:=p;
    p:=t;
  end;
  readln(); new(p); p:=nil;
  while not(eoln) do
  begin
    new(s);
    read(s^.inf);
    s^.sl:=p;
    p:=s;
  end;
  pom:=s; p:=t;
  while s<>nil do
  begin
    k:=0;
    while t<>nil do
    begin
      if t^.inf=s^.inf then inc(k);
      t:=t^.sl;
    end;
    if k<2 then del(s) else s:=s^.sl;
    t:=p;
  end;
  while pom<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.
