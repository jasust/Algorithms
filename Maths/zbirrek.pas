{Od data tri niza odrediti koji ima najveci zbir preko rekurzije}
program p1;
type niz=array[1..100] of integer;
var n,i,s,max:integer;
a,b,c:niz;

function zbr(a:niz;n:integer):integer;
var j:integer;
begin
  if n>0 then zbr:=a[n]+zbr(a,n-1)
  else zbr:=0;
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do read(c[i]);
  max:=zbr(a,n);
  s:=1;
  if zbr(b,n)>max then
  begin
    max:=zbr(b,n);
    s:=2;
  end;
  if zbr(c,n)>max then
  begin
    max:=zbr(c,n);
    s:=3;
  end;
  writeln(s,' ',max);
end.
