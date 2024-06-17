{n) odrediti zbir listova stabla}
program p6;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  br:integer; novi,koren:pok;

procedure ubaci(novi:pok; var koren:pok);
begin
  if koren=nil then
  begin
    koren:=novi;
    novi^.l:=nil;
    novi^.d:=nil;
  end else
  if novi^.inf<koren^.inf then ubaci(novi,koren^.l)
   else ubaci(novi,koren^.d);
end;

procedure odredi(var k:pok);
begin
  if (k^.l=nil) and (k^.d=nil) then inc(br,k^.inf) else
  begin
   if k^.l<>nil then odredi(k^.l);
   if k^.d<>nil then odredi(k^.d);
  end;
end;

begin
  koren:=nil;
  while not eoln do
  begin
    new(novi);
    read(novi^.inf);
    ubaci(novi,koren);
  end;
  odredi(koren);
  writeln(br);
end.
