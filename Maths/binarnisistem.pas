program binarni;
var  n:integer;

procedure  nor(n:integer);
begin
   if n>1  then  nor(n div 2);
   write(n mod 2);
end;

procedure  inv(n:integer);
begin
   write(n mod 2);
   if n>1  then  inv(n div 2);
end;

begin
   readln(n);
   nor(n);
   writeln;
   inv(n);
end.
