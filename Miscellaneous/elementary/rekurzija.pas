{Odrediti koliko puta se funkcija poziva rekurzivno}
program p1;
var n,k:integer;
function fib(n:integer):integer;
begin
   if (n=1) or (n=2) then fib:=1 else
   begin
      fib:=fib(n-1)+fib(n-2);
      k:=k+2;
   end;
end;

begin
   read(n);
   fib(n);
   writeln(k,' ',fib(n));
end.
