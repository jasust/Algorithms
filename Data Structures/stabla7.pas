{43.a) da li je stablo perfektno balansirano}
program p7;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  novi,koren:pok;

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

function broj(koren:pok):integer;
begin
  if koren=nil then broj:=0
   else broj:=1+broj(koren^.l)+broj(koren^.d);
end;

function balansirano(koren:pok):boolean;
begin
  if koren=nil then balansirano:=true
   else if abs(broj(koren^.l)-broj(koren^.d))<=1 then
    balansirano:=balansirano(koren^.l) and balansirano(koren^.d)
     else balansirano:=false;
end;

begin
  koren:=nil;
  while not eoln do
  begin
    new(novi);
    read(novi^.inf);
    ubaci(novi,koren);
  end;
  if balansirano(koren) then writeln('jeste') else writeln('nije');
end.