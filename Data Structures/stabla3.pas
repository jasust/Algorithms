{46.Formirati stablo ciji je svaki sledeci clan = prethodnom - poslednje slovo}
program p11;
type pok=^slog;
     slog=record inf:string; l,d:pok; end;
var koren:pok; s:string;

procedure unos(var koren:pok; s:string);
begin
  if length(s)>0 then
  begin
    new(koren);
    koren^.inf:=s;
    koren^.l:=nil;
    koren^.d:=nil;
    delete(s,length(s),1);
    unos(koren^.l,s);
    unos(koren^.d,s);
  end;
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
  readln(s);
  new(koren);
  unos(koren,s);
  ispisLKD(koren);
end.