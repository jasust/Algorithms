program peti;
var
procedure BFS(st:integer);
var i:integer;
begin
 o[st]:=true;
 red[1]:=st;
 p:=1;k:=1;
 while (p<=k) do
  begin
   for i:=1 to n do
    if (e[red[p],i] and not o[i]) then
     begin
      k:=k+1;
      red[k]:=i;
      o[i]:=true;
     end;
   p:=p+1;
  end;
end;
begin
  readln(n,m);
  for i:=1 to 2*n-1 do
  for j:=1 to 2*m-1 do begin read(a[i,j]); if a[i,j]<>' ' then e[i div 2 +1,j div 2 +1]:=a[i,j]; end;



