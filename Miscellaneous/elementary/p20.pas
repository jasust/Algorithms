{20)matrica[1..10,1..10] of real i skup set of 1..10; izracunati zbir
    onih clanova matrice M ciji zbir kordinata pripadaju skupovima s1 i s2}
program p20;
var x:string; i,j,k,y,n,m,z,code:integer;
    s1,s2:set of 0..10;
begin
  readln(x); for i:=1 to length(x) do begin val(x[i],z,code); s1:=s1+[z]; end;
  readln(x); for i:=1 to length(x) do begin val(x[i],z,code); s2:=s2+[z]; end;
  readln(n,m);
  for i:=1 to n do
   for j:=1 to m do
    begin read(y); if (i+j in s1) and (i+j in s2) then k:=k+y; end;
  writeln(k);
end.

