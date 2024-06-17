program c2;
uses pokazivaci;
type pok=^slog;
     slog=record inf:integer; sl:pok; end;
var tren,p:pok; c,a:char; k:integer;

begin
  new(tren); tren:=nil; k:=1;
  while not eoln do
  begin
    read(c);
    if c='(' then zagrade(tren)
     else if c='*' then
     begin
       read(a);
       if a='(' then zagrade(tren) else push(a,k,tren);
       tren^.sl^.inf:=(tren^.sl^.inf-48)*(tren^.inf-48)+48;
       p:=tren; tren:=tren^.sl;
       dispose(p);
     end
    else push(c,k,tren);
  end;
  while tren^.sl<>nil do
  begin
    if tren^.sl^.inf=43 then inc(tren^.sl^.sl^.inf,tren^.inf-48)
     else dec(tren^.sl^.sl^.inf,tren^.inf-48);
    new(p); p:=tren;
    tren:=tren^.sl^.sl;
    dispose(p^.sl);
    dispose(p);
  end;
  writeln(tren^.inf-48);
end.