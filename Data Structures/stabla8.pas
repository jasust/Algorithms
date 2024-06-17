{43.b i c) napraviti balansirano stablo pomocu procedure koja na prethodno balansirano
           stablo dodaje 1 clan tako da ono ostane balansirano i ispisati ga LKD}
program p8i9;
type pok=^slog;
     slog=record inf:integer; l,d:pok; end;
var  novi,koren:pok; n:integer;

function broj(koren:pok):integer;
begin
  if koren=nil then broj:=0
   else broj:=1+broj(koren^.l)+broj(koren^.d);
end;

procedure balansiraj(n:integer; var koren:pok);
begin
  if koren=nil then
  begin
    new(koren);
    koren^.inf:=n;
    koren^.l:=nil;
    koren^.d:=nil;
  end else
   if broj(koren^.l)<broj(koren^.d) then balansiraj(n,koren^.l)
    else balansiraj(n,koren^.d);
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
    read(n);
    balansiraj(n,koren);
  end;
  ispisLKD(koren);
end.