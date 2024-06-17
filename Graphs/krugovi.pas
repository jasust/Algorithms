{5.Dato je n koncentricnih krugova. Za svaki krug je dato m vrata a[i,j] predstavlja
 broj negativnih poena za izlazak iz i-tog kruga na j-tim vratima. Napisati
 put od tacno s poena, a ako ne postoji ispisati komentar}
program p1;
var n,m,s,i,j:integer; pos:boolean;
    a:array[1..1000,1..1000] of integer;
    d:array[1..1000] of integer;

procedure dfs(x,sum:integer);
var k:boolean; i:integer;
begin
  k:=true;
  if sum>s then k:=false;
  if x=n+1 then
  begin
    if sum=s then
    begin
      for i:=1 to n do writeln('krug: ',i,' vrata: ',d[i]);
      halt;
    end;
    k:=false;
  end;
  if k then
  for i:=1 to m do
  begin
    d[x]:=i;
    dfs(x+1,sum+a[x,i]);
  end;
end;

begin
  read(n,m);
  for i:=1 to n do
   for j:=1 to m do read(a[i,j]);
  read(s);
  pos:=false;
  for i:=1 to n do d[i]:=0;
  dfs(1,0);
  writeln('Ne postoji put');
end.
