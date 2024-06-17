Program p1;
var a:array[0..1001,0..1001] of integer;
    max,m,n,i,j:integer; x:char;

function min(a,b,c,d:integer):integer;
var l:integer;
begin
l:=a; if l>b then l:=b; if l>c then l:=c; if l>d then l:=d; min:=l;
end;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do
      begin
        read(x);
        if x='#'then a[i,j]:=1;
      end;
    readln
  end;
  for i:=n downto 1 do
   for j:=1 to m do
    if a[i,j]=1 then
      begin
        a[i,j]:=a[i,j]+min(a[i+1,j],a[i+1,j+1],a[i+1,j-1],a[i+2,j]);
        if a[i,j]>max then max:=a[i,j];
      end;
  writeln(max);
end.