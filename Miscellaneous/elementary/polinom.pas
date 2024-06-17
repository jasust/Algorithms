program ap;
var n,i,j,k:integer; p,sol:extended;
    a:array[0..126] of integer;
begin
  readln(n);
  for i:=n downto 0 do read(a[i]);
  for i:=1 to a[0] do if a[0] mod i=0 then
   for j:=1 to a[n] do if a[n] mod j=0 then
    begin
      p:=0;
      for k:=n downto 0 do p:=p*(i/j)+a[k];
      if p=0 then sol:=sol+(i*i)/(j*j);
      p:=0;
      for k:=n downto 0 do p:=-p*(i/j)+a[k];
      if p=0 then sol:=sol+(i*i)/(j*j);
    end;
  writeln(sol);
end.

