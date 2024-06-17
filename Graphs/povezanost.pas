{Ako ima n gradova i m veza izmedju njih koje se unose u obliku
 k1 j1
 k2 j2
 ...
 km jm
Rekurzivnom funkcijom dfs koja ispisuje da li su svi gradovi povezani sa unetim gradom odrediti
 a)dali su svi povezani b) koliko ima ostrva u grafu }

Program p3;
type mat=array [1..1000,1..1000] of boolean;
     niz=array [1..1000] of boolean;
var n,m,k,i,j,c:longint;
a:mat;
o:niz;

procedure dfs(x:longint);
var i:longint;
begin
 o[x]:=true;
 for i:=1 to n do
  if not(o[i]) and a[x,i] then dfs(i);
end;

begin
readln(n,m);
for i:=1 to m do
 begin
  readln(k,j);
  a[k,j]:=true; a[j,k]:=true;
 end;

dfs(1); c:=1;
for i:=1 to n do
 if not o[i] then
   begin
    dfs(i); inc(c);
   end;

if c=1 then writeln('Svi su povezani')
 else writeln('Nisu svi povezani, ima ',c,' ostrva.');
end.
