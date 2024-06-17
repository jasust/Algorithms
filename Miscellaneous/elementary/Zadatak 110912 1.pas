{1.Pomnozi 2 matrice koje se mogu pomnoziti}
Program Z1;
var n,m,k,i,j,s:integer;
    a,b,c:array [1..1000,1..1000] of longint;
begin
  readln (n,k,m);
  for i:=1 to n do
   for j:=1 to k do read(a[i,j]);
  for i:=1 to k do
   for j:=1 to m do read(b[i,j]);
  for i:=1 to n do
   for j:=1 to m do
    for s:=1 to k do inc(c[i,j],a[i,s]*b[s,j]);
  for i:=1 to n do
  begin for j:=1 to m do write(c[i,j],' '); writeln; end;
end.
