{Napisati program koji racuna vrednost matematickog izraza koji se sastoji
 iz '(', ')', '+', '-', '*' i jednocifrenih celih brojeva}
program p1;
type pok=^slog;
     slog=record inf:integer; sl:pok; end;
var tren,p:pok; c,a:char; k:integer;

procedure push(a:char;var k:integer;var tren:pok);
begin
  new(p);
  if (k=-1) and (a='+') then begin a:='-'; k:=-k; end
   else if (k=-1) and (a='-') then a:='+'
    else if a='-' then k:=-k;
  p^.inf:=ord(a);
  p^.sl:=tren;
  tren:=p;
end;

procedure zagrade(poc:pok);
var a:char; k:integer;
begin
  read(c); k:=1;
  while c<>')' do
  begin
    if (c='*') then
    begin
      read(a);
      if a='(' then zagrade(tren) else push(a,k,tren);
      tren^.sl^.inf:=(tren^.sl^.inf-48)*(tren^.inf-48)+48;
      p:=tren; tren:=tren^.sl;
      dispose(p);
    end
     else if c='(' then zagrade(tren)
      else push(c,k,tren);
    read(c);
  end;
  while tren^.sl<>poc do
  begin
    if tren^.sl^.inf=43 then inc(tren^.sl^.sl^.inf,tren^.inf-48)
     else dec(tren^.sl^.sl^.inf,tren^.inf-48);
    new(p); p:=tren;
    tren:=tren^.sl^.sl;
    dispose(p^.sl);
    dispose(p);
  end;
end;

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
