{Odrediti minimalnu stranicu matrice koja je simetricna i horizontalno i vertikalno
 u kojoj se jedinice ne dodiruju, i sadrzi zadati broj jedinica}
program p1;
var i,n:longint;
begin
  read(n);
  if n=3 then writeln(5) else
  begin
    i:=1;
    while (i*i+1) div 2<n do inc(i,2);
    writeln(i);
  end;
end.
