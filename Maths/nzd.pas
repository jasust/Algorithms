{ Napisati rekurzivnu proceduru za izracunavanje nzd 2 broja. }
program b5;
var n, m : integer;

function nzd(x, y : integer) : integer;
begin
        if(x = 0) then nzd:=y
        else nzd:=nzd(y mod x, x);
end;

begin
        readln(n, m);
        writeln(nzd(n, m));
end.
