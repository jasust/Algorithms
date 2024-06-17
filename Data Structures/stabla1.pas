{i)odrediti maximalnu dubinu stabla}
program p1;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  a,max:integer; novi,koren:pok;

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
  if a>max then max:=a;
  if k^.l<>nil then begin inc(a); odredi(k^.l); end;
  if k^.d<>nil then begin inc(a); odredi(k^.d); end;
  dec(a);
end;

begin
  koren:=nil;
  while not eoln do
  begin
    new(novi);
    read(novi^.inf);
    ubaci(novi,koren);
  end;
  //a:=1;
  odredi(koren);
  writeln(max);
end.

