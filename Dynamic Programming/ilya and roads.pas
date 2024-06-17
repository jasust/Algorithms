program roads;
const maxn=1000000000000000;
var f,g:array[0..301,0..301] of int64;
    i,j,k,t,m,n,s,l,r:integer; c:longint;

function min(a,b:int64):int64;
begin
  if a<b then min:=a else min:=b;
end;

begin
  readln(n,m,k);
  for i:=0 to n+1 do
   for j:=0 to n+1 do
   begin
     f[i,j]:=maxn;
     g[i,j]:=maxn;
   end;

  for i:=1 to m do
  begin
    readln(l,r,c);
    f[l,r]:=min(f[l,r],c);
  end;
  for j:=n-2 downto 0 do
   for i:=1 to n-j do
   begin
     s:=i+j;
     f[i,s]:=min(f[i,s],min(f[i-1,s],f[i,s+1]));
   end;
  for j:=1 to n-1 do
   for i:=1 to n-j do
   begin
     s:=i+j;
     for t:=i to s-1 do f[i,s]:=min(f[i,s],f[i,t]+f[t+1,s]);
   end;
  g[0,0]:=0;
  for i:=1 to n do
   for j:=0 to min(k,i) do
   begin
     g[i,j]:=g[i-1,j];
     for s:=i-j to i-1 do g[i,j]:=min(g[i,j],g[s,j-(i-s)]+f[s+1,i]);
   end;
  if g[n,k]<>maxn then writeln(g[n,k]) else writeln(-1);
end.
