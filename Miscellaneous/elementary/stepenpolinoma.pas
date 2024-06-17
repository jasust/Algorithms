{Formirati pretrazivacko stablo i odredi koliko se puta dati element nalazi
 u stablu i procitati lkd}
program p4;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  a,br:integer; novi,koren:pok;

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

procedure ispis(var k:pok);
begin
  if k<>nil then
  begin
    ispis(k^.l);
    write(k^.inf,' ');
    ispis(k^.d);
  end;
end;

procedure odredi(var k:pok);
begin
  if k^.inf=a then inc(br);
  if k^.l<>nil then odredi(k^.l);
  if k^.d<>nil then odredi(k^.d);
end;

begin
  koren:=nil;
  while not eoln do
  begin
    new(novi);
    read(novi^.inf);
    ubaci(novi,koren);
  end;
  readln(a);
  odredi(koren);
  ispis(koren);
  writeln; write(br);
end.
