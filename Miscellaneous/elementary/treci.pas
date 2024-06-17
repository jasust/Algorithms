program p3;
var a:array[1..100,1..100] of integer;
    d:array [1..100] of integer;
    n,i,j,p,k:integer;
begin
  readln(n);
  for i:=1 to n do
   for j:=1 to n do
   begin
     read(a[i,j]);
     if i+j>=n+3 then begin k:=k+1; d[k]:=a[i,j]; end;
   end;
  for i:=1 to k-1 do
   for j:=i+1 to k do
    if d[i]>d[j] then begin p:=d[i]; d[i]:=d[j]; d[j]:=p; end;
  for i:=1 to k do write(d[i],' ');
end.