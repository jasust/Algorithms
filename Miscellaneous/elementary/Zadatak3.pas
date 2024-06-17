{Data je datoteka sa NxM matricom, ispisati sumu po vrstama}
Program Z1;
var n,m,x,z,i,j:longint;
    ul,iz:text;
begin
  assign(ul,'Zadatak 021112 1.in');
  assign(iz,'Zadatak 021112 1.out');
  reset(ul); rewrite(iz);
  readln(ul,n,m);
  for i:=1 to n do
  begin
    z:=0;
    for j:=1 to m do
    begin
      read(ul,x);
      inc(z,x);
    end;
    write(iz,z,' ');
  end;
  close(ul); close(iz);
end.
