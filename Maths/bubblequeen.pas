program bubble;
var i,n,k:int64;
    s:real;
begin
  readln(n);
  i:=0;
  if (n=0) or (n=1) then writeln(0) else
    if n mod 2=0 then
     while i<=(n div 2) do
     begin
       k:=k+4*(n-1-2*i)*(3*n-3+2*i);
       i:=i+1;
       if n-2*i=2 then break;
     end
     else while i<=(n div 2)+1 do
     begin
       k:=k+4*(n-1-2*i)*(3*n-3+2*i);
       i:=i+1;
       if n-2*i=1 then break;
     end;
  if n mod 2=0 then k:=k+4*(4*n-5) else k:=k+4*n-4;
  s:=k/sqr(n);
  writeln(s:0:3);
end.