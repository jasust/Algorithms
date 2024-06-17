{Dat je niz zgrada zadate visine koje treba rasporediti u ne opadajuci niz
spajanjem susednih zgrada. Koliko najmanje operacija treba izvrsiti.}
program towers;
var n,i,j:longint;
    a,f:array[0..5000]of longint;
    sum,d:array[0..5000]of int64;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do sum[i]:=sum[i-1]+a[i];
  f[1]:=0; d[1]:=a[1];
  for i:=2 to n do
  begin
    j:=i-1;
    while sum[i]-sum[j]<d[j] do dec(j);
    f[i]:=f[j]+i-j-1;
    d[i]:=sum[i]-sum[j];
  end;
  writeln(f[n]);
end.

