program p1;
var y,xa,xb:array[1..10000] of longint;
    i,j,m,n:longint;
procedure sort(a,b:longint);
var t:longint;
begin
  if b>a then begin t:=a; a:=b; b:=t; end;
end;
begin
  readln(n);
  m:=n;
  for i:=1 to n do read(y[i],xa[i],xb[i]);
  for i:=1 to n-1 do
   for j:=i+1 to n do
   begin
     sort(xa[i],xb[i]);  sort(xa[j],xb[j]);
     if ((y[i]=y[j]) and ((xa[i]>=xa[j]) and (xa[i]<=xb[j]))) then m:=m-1;
   end;
  writeln(m);
end.