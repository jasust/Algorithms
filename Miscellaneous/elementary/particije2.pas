program particije;
var a:array[0..100] of integer;
    n,i,j:integer;
begin
  readln(n);
  repeat
  begin
    i:=1;
    while a[i]<>0 do
    begin
      a[i]:=0;
      inc(i);
    end;
    a[i]:=1;
    for j:=n downto 1 do write(a[j]);
    writeln;
  end;
  until a[n+1]=1;
end.