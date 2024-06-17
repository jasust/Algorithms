{k)ispisati elemente n-tog nivoa stabla}
program p3;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  a,n:integer; novi,koren:pok;

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
  if a=n then write(k^.inf,' ');
  if (k^.l<>nil) and (a<n) then begin inc(a); odredi(k^.l); end;
  if (k^.d<>nil) and (a<n) then begin inc(a); odredi(k^.d); end;
  dec(a);
end;

begin
  readln(n);
  koren:=nil;
  while not eoln do
  begin
    new(novi);
    read(novi^.inf);
    ubaci(novi,koren);
  end;
  odredi(koren);
end.
