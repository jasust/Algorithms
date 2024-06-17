program p1;
type pok=^slog;
     slog=record inf:integer; levo,desno:pok; end;
var koren,tekuci:pok;

procedure lkd(koren:pok);
begin
  if koren<>nil then
  begin
    lkd(koren^.levo);
    write(koren^.inf,' ');
    lkd(koren^.desno);
  end;
end;

procedure ubaci(novislog:pok; var koren:pok);
begin
  if koren=nil then
  begin
    koren:=novislog;
    novislog^.levo:=nil;
    novislog^.desno:=nil;
  end else
  if novislog^.inf<koren^.inf then ubaci(novislog,koren^.levo)
   else ubaci(novislog,koren^.desno);
end;

begin
  koren:=nil;
  while not eoln do
  begin
    new(tekuci);
    read(tekuci^.inf);
    ubaci(tekuci,koren);
  end;
  lkd(koren);
end.