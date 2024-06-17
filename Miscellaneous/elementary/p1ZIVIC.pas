program p1;
var y,n,max2,i,j:integer;
a,b:array[0..100,0..100] of integer;

function max(a,b,c:integer):integer;
begin
  max:=a;
  if b>max then max:=b;
  if c>max then max:=c;
end;

begin
  readln(y);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  b[1,y]:=a[1,y];
  for i:=2 to n do
    for j:=1 to n do if i+j>=1+y then
    if i-j>=1-y then b[i,j]:=max(b[i-1,j],b[i-1,j-1],b[i-1,j+1])+a[i,j]
    else b[i,j]:=0;
  max2:=b[n,1];
  for i:=2 to n do if b[n,i]>max2 then max2:=b[n,i];
  writeln(max2);
end.