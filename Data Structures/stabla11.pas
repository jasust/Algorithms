{Formirati red listu od koeficijanata polinoma i izracunati njen k-ti stepen}
program p2;
type pok=^slog;
     slog=record inf:integer; sl:pok; end;
var t,p,pom:pok;

procedure brzstep(k:integer);
begin
  if k>1 then
  begin
    brzstep(k shr 1);
    kvadrat;
    if odd(k) then pomnozi;
  end;
end;

begin
  new(t); pom:=t;
  while not(eof) do
  begin
    read(t^.inf);
    new(p);
    t^.sl:=p;
    t:=p;
  end;
  readln(k);
  brzstep(k);
  while pom^.sl<>nil do
  begin
    write(pom^.inf,' ');
    pom:=pom^.sl;
  end;
end.
