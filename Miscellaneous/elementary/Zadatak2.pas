{Data je sahovska tabla NxM i k slogova a.x,a.y koji predstavljaju koordinate
        a) dama   b) skakaca
    ispitati koliko parova se tuku i koliko ima polja iste boje izmedju figura
    kao sto je prvo polje a[1].x,a[1].y ?}
Program Z1;
var n,m,k,i,j,b:longint;
a:array [1..1000] of record x,y:longint; end;
begin
  readln(n,m,k);
  for i:=1 to k do read(a[i].x,a[i].y);
  for i:=1 to k-1 do
   for j:=i+1 to k do
    if ((abs(a[i].x-a[j].x)=2) and (abs(a[i].y-a[j].y)=1)) or ((abs(a[i].x-a[j].x)=1) and (abs(a[i].y-a[j].y)=2)) then
    begin
      writeln(a[i].x,',',a[i].y,'  ',a[j].x,',',a[j].y,'   ');
    end;
end.
