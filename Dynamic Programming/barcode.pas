{Od zadate matrice od . i # treba napraviti matricu u kojoj su clanovi u kolonama isti pri
 tom broj istih kolone ne sme da bude manji od x,ni veci od y.Odrediti najmanji broj poteza}
Program p1;
var  n,m,x,y,i,j,x1,x2:longint;
     c:array[1..1000,1..1000]of char;
     a,b,f,g:array[0..1000]of longint;

function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;

begin
  readln(m,n,x,y);
  for i:=1 to m do
  begin
    for j:=1 to n do read(c[i,j]);
    readln;
  end;
  for i:=1 to n do
  begin
    x1:=0; x2:=0;
    for j:=1 to m do if c[j,i]='.' then inc(x1) else inc(x2);
    a[i]:=a[i-1]+x1;
    b[i]:=b[i-1]+x2;
  end;
  fillchar(f,sizeof(f),127);
  fillchar(g,sizeof(g),127);
  f[0]:=0; g[0]:=0;
  for i:=x to n do
   for j:=x to min(i,y) do
   begin
     f[i]:=min(f[i],b[i]-b[i-j]+g[i-j]);
     g[i]:=min(g[i],a[i]-a[i-j]+f[i-j]);
   end;
  writeln(min(f[n],g[n]));
end.
