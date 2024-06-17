{Zadata je matrica nxm i broj x<=m koji oznacava pocetni polozaj u prvom redu.
Covek se krece dole, dole-levo i dole-desno do poslednjeg reda tako da zbir
polja po kojima se krece bude najveci moguci. Koliko on iznosi?}
program p1;
var n,m,i,j,x,max:integer;
    o:array[0..100,0..100] of boolean;
    a,dp:array[0..100,0..100] of integer;
begin
  readln(n,m);
  for i:=1 to n do
   for j:=1 to m do read(a[i,j]);
  dp:=a; readln(x);
  for i:=1 to m do
   for j:=1 to abs(i-x) do begin dp[j,i]:=0; o[j,i]:=true; end;
  for i:=2 to n do
   for j:=1 to m do if not(o[i,j]) then
  if (dp[i-1,j-1]>dp[i-1,j]) and (dp[i-1,j-1]>dp[i-1,j+1]) then
  dp[i,j]:=dp[i,j]+dp[i-1,j-1] else if (dp[i-1,j]>dp[i-1,j+1]) then
  dp[i,j]:=dp[i,j]+dp[i-1,j] else dp[i,j]:=dp[i,j]+dp[i-1,j+1];
  for i:=1 to m do if dp[n,i]>max then max:=dp[n,i];
  writeln(max);
end.
