{odredi gde se nalaze mine u minskom polju ako su date prva vrsta i kolona}
program p1;
var m,b:array[0..100,0..100]of integer;
    i,j,n:integer;
function sum(x,y:integer):integer;
begin
  sum:=b[x-1,y-1]+b[x,y-1]+b[x+1,y-1]+b[x+1,y]+b[x,y+1]+b[x-1,y+1]+b[x-1,y];
end;
begin
  fillchar(b,sizeof(b),0);
  readln(n);
  for i:=1 to n do read(b[1,i]);
  for i:=2 to n do read(b[i,1]);
  for i:=1 to n do
   for j:=1 to n do read(m[i,j]);
  for i:=2 to n do
   for j:=2 to n do b[i,j]:=m[i-1,j-1]-sum(i-1,j-1);
  for i:=1 to n do begin
   for j:=1 to n do write(' ',b[i,j]);  writeln; end;
end.
