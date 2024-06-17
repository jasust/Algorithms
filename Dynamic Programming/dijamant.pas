program dijamant;
var a:array[0..1000,0..1000] of integer;
b:array[0..1999,0..1999] of char;
n,m,i,j,max:integer;
function f(x,y:integer):integer;
var min:integer;
begin
  min:=maxint;
  if a[x-1,y]<min then min:=a[x-1,y];
  if a[x,y-1]<min then min:=a[x,y-1];
  if a[x,y+1]<min then min:=a[x,y+1];
  if a[x+1,y]<min then min:=a[x+1,y];
  f:=min;
end;
begin
  fillchar(a,sizeof(a),0);
  readln(n,m);
  for i:=1 to 2*n-1 do
  for j:=1 to m do begin read(b[1,j]); if b[i,j]='#' then a[(i div 2)+1,j]:=1; end;
  for i:=1 to n do
  for j:=1 to m do if a[i,j]<>0 then a[i,j]:=a[i,j]+f(i,j);
  for i:=1 to n do
  for j:=1 to m do if a[i,j]>max then max:=a[i,j];
  writeln(max);
end.