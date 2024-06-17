Program sortniz2;
var n,min,max,k,j,i:integer;
    a,b:array[1..50] of integer;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    max:=a[1];
    min:=a[1];
    b[a[1]]:=1;
    for i:=2 to n do
    begin
      b[a[i]]:=b[a[i]]+1;
      if a[i]>max then max:=a[i];
      if a[i]<min then min:=a[i];
    end;
    for i:=min to max do
     for j:=1 to b[i] do
     begin
       k:=k+1;
       a[k]:=i;
     end;
    for i:=1 to n do write(a[i],' ');
end.