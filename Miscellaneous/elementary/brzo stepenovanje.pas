program brzostep;
var n,k,b:longint;

procedure step(baza,eksponent:longint);
begin
  if eksponent>1 then
  if odd(eksponent) then
  begin
    step(baza,eksponent div 2);
    b:=b*b;
    b:=b*baza;
  end else
  begin
    step(baza,eksponent div 2);
    b:=b*b;
  end;
end;

begin
  read(n,k);
  b:=n;
  step(n,k);
  write(b);
end.