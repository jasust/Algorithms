{ Suma prvih n clanova fibonacijevog niza }
program b6;
var n : integer;
f : array[1..10000] of integer;

function fib(n : integer) : integer;
begin
        if(f[n] <> -1) then fib:=f[n];

        if(n = 1) or (n = 2) then f[n]:= 1
        else f[n]:= fib(n-1) + fib(n-2);

        fib:=f[n];
end;

function zb(n : integer) : integer;
begin
        if(n > 0) then zb:=fib(n) + zb(n-1)
        else zb:=0;
end;

begin
        readln(n);
        writeln(zb(n));
end.
