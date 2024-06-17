{Data je kvadratna matrica, izracunati determinantu matrice}
Program p1;
type matrica=array[1..100,1..100] of integer;
var n,i,j:integer; a:matrica;

function det(b:matrica; m:integer):integer;
var i,j,o,x,k:integer; c:matrica;
begin
  det:=0;
  fillchar(c,sizeof(c),0);
  if b[1,2]<>0 then
  begin
    k:=1; x:=0;
    for o:=1 to m do
    begin
      for i:=2 to m do
      begin
        for j:=1 to m do if (j<>o) then
        begin inc(x); c[i-1,x]:=b[i,j]; end;
        x:=0;
      end;
      inc(det,k*a[1,o]*det(c,m-1));
      k:=k*(-1);
    end;
  end
  else det:=b[1,1];
end;

begin
  readln(n);
  for i:=1 to n do
   for j:=1 to n do read(a[i,j]);
  writeln(det(a,n));
end.