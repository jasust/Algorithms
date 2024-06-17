program p1;
type niz=array[0..200005] of int64;
var a,b:niz;
    l,r,i,n,q:longint; sol:int64;

procedure qsort(l,r:longint; var c:niz);
var i,j,x,y:longint;
begin
  i:=l;
  j:=r;
  x:=c[(l+r) div 2 ];
  repeat
    while c[i]>x do inc(i);
    while c[j]<x do dec(j);
    if i<=j then
    begin
      y:=c[i];
      c[i]:=c[j];
      c[j]:=y;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j,c);
  if i<r then qsort(i,r,c);
end;

begin
  readln(n,q);
  for i:=1 to n do read(a[i]);
  qsort(1,n,a);
  for i:=1 to q do
  begin
    read(l,r);
    inc(b[l]);
    dec(b[r+1]);
  end;
  for i:=2 to n do inc(b[i],b[i-1]);
  qsort(1,n,b);
  for i:=1 to n do inc(sol,b[i]*a[i]);
  writeln(sol);
end.
