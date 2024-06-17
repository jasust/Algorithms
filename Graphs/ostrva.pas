{Zadata je matrica nxm od 0 i 1. Odrediti koliko ima 'ostrva' od 1}
program p1;
var s,i,j,n,m:integer;
    o:array[0..100,0..100] of boolean;
    a:array[0..100,0..100] of integer;
procedure pored(q,w:integer);
begin
  o[q,w]:=true;
  if (a[q,w+1]=1) and not (o[q,w+1]) then pored(q,w+1);
  if (a[q+1,w]=1) and not (o[q+1,w]) then pored(q+1,w);
  if (a[q,w-1]=1) and not (o[q,w-1]) then pored(q,w-1);
  if (a[q-1,w]=1) and not (o[q-1,w]) then pored(q-1,w);
end;
begin
  readln(n,m);
  for i:=1 to n do
   for j:=1 to m do read(a[i,j]);
  for i:=1 to n do
   for j:=1 to m do
   if (a[i,j]=1) and not(o[i,j]) then begin pored(i,j); s:=s+1; end;
   writeln(s);
end.
