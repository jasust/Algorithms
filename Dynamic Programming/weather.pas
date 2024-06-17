{Dato je n celih brojeva.Koliko najmanje brojeva treba da promenis da bi prvi
deo niza cinili samo negativni,a drugi samo pozitivni brojevi}
Program p1;
var f,t:array [0..1000000] of longint;
    a,res,n,i:longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a);
    f[i]:=f[i-1];
    t[i]:=t[i-1];
    if a>=0 then inc(f[i]);
    if a<=0 then inc(t[i]);
  end;
  res:=maxint;
  for i:=1 to n-1 do if f[i]+t[n]-t[i]<res then res:=f[i]+t[n]-t[i];
  writeln(res);
end.
