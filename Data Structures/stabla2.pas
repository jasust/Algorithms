{44. Formirati kopiju zadatog binarnog stabla}
program p10;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  koren,novi_koren,novi:pok;

procedure kopi(koren:pok; var novi_koren:pok);
begin
  if koren=nil then novi_koren:=nil else
  begin
    new(novi_koren);
    novi_koren^.inf:=koren^.inf;
    novi_koren^.l:=nil;
    novi_koren^.d:=nil;
    kopi(koren^.l,novi_koren^.l);
    kopi(koren^.d,novi_koren^.d);
  end;
end;

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

procedure ispisLKD(koren:pok);
begin
  if koren<>nil then
  begin
    ispisLKD(koren^.l);
    write(koren^.inf,' ');
    ispisLKD(koren^.d);
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
  new(novi_koren);
  kopi(koren,novi_koren);
  ispisLKD(koren);
  writeln;
  ispisLKD(novi_koren);
end.
