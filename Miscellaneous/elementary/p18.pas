{18)a-broj razlicitih cifara broja n
    b-stampati u rastucem poretku sve cifre koje ne ulaze u sastav datog broja}
program p18;
var n:longint; i,k:integer;
    a:array[0..10] of boolean;
begin
  readln(n);
  while n>0 do
  begin
    if not(a[n mod 10]) then begin a[n mod 10]:=true; k:=k+1; end;
    n:=n div 10;
  end;
  writeln('ima ',k,' razlicitih cifara');
  writeln('cifre koje se ne pojavljuju su: ');
  for i:=0 to 9 do if not(a[i]) then write(i,' ');
end.
