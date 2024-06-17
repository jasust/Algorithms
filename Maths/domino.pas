program domino;
var n:integer;
    sol:longint;
begin
  read(n);
  sol:=(n*(n+1)*(n+2)) shr 1;
  write(sol);
end.