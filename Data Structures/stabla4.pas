{l)ispisati stablo po nivoima}
program p4;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  a,i,max:integer; novi,koren:pok;

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
  if a=i then write(k^.inf,' ');
  if (k^.l<>nil) and (a<i) then begin inc(a); ispis(k^.l); end;
  if (k^.d<>nil) and (a<i) then begin inc(a); ispis(k^.d); end;
  dec(a);
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
  odredi(koren);
  for i:=0 to max do begin a:=0; ispis(koren); writeln; end;
end.