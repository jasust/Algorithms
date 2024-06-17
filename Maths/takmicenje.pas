{na takmicenju ima n takmicara, sa datim brojem poena.
Odredi koliko tamicera ima nadprosecne rezultate}
program p1;
var a:array[1..1000]of integer;
    i,n,k:integer; p:real;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    p:=p+a[i];
  end;
  p:=p/n;
  for i:=1 to n do if a[i]>p then k:=k+1;
  writeln(k);
end.

