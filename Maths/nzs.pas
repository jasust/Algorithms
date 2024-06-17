{Rekurzija za NZS 2 broja}

Program p7;
var a,b,nzd:longint;

procedure f(x,y:longint);
begin
if x mod y=0 then writeln(x)
 else f(x+a,y);
end;

begin
read (a,b);
f(a,b);
end.
