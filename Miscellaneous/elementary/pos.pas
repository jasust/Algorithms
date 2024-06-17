{Ucitati u datoteci nizove brojeva i ispisati koliko 9 ima u svakom}
program p1;
var f,g:text; s:string; i,j:integer;
    a:array[1..100] of integer;
begin
  assign(f,'ulaz.in');
  assign(g,'izlaz.out');
  reset(f); rewrite(g);
  while not(eof(f)) do
  begin
    readln(f,s); inc(i);
    while pos('9',s)>0 do begin inc(a[i]); delete(s,pos('9',s),1); end;
  end;
  for j:=1 to i do write(g,a[j],' ');
  close(f); close(g);
end.
