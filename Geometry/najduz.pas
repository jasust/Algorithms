{ako je dato n tacaka odrediti najduzu duz odredjenu njima}
program p1;
var a,b:array[1..100] of integer;
    n,i,j,x,y:integer; r,max:real;
begin
  readln(n);
  for i:=1 to n do read(a[i],b[i]);
  for i:=1 to n-1 do
   for j:=i+1 to n do
   begin
     r:=sqrt(sqr(a[i]-a[j])+sqr(b[i]-b[j]));
     if r>max then begin max:=r; x:=i; y:=j; end;
   end;
  writeln('najveca duzina je:',max:0:2,' izmedju tacaka ',x,' i ',y);
end.
