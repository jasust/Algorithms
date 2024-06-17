program sortniz1;
var i,j,p,n:integer;
    a:array[1..50] of integer;
begin
    read(n);
    for i:=1 to n do read(a[i]);
    for i:=1 to n-1 do
    for j:=i+1 to n do
    if a[i]>a[j] then
      begin
      p:=a[i];
      a[i]:=a[j];
      a[j]:=p;
    end;
    for i:=1 to n do write(a[i],' ');
end.


