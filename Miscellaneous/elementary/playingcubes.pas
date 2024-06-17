program b;
var n,m:longint;
begin
  read(n,m);
  if m=n then begin write(n-1,' ',n); halt(0); end;
  if (m>n) then write(m-1,' ',n)
   else write(n-1,' ',m);
end.