{k mesta u desno}
program p5;
var a:array[1..100] of integer;
    n,k,i,j,p:integer;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to k do
   for j:=1 to n do
   begin
    p:=a[1];
    a[1]:=a[j];
    a[j]:=p;
   end;
  for i:=1 to n do write(a[i],' ');
end.