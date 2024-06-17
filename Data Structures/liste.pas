program p1;
type pok=^slog;
     slog=record inf:integer; sl:pok; end;
var tren,p:pok; c,a:char;

procedure push(a:char;var tren:pok);
begin
  new(p);
  p^.inf:=ord(a);
  p^.sl:=tren;
  tren:=p;
end;

begin
  new(tren); tren^.sl:=nil;
  while not eoln do begin read(c); push(c,tren); end;
  while tren^.sl<>nil do begin write(tren^.inf); tren:=tren^.sl; end;
end.