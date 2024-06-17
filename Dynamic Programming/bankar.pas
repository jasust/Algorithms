program p5;
var dp:array[0..50005] of longint;
    a:array[-1..100] of longint;
    i,k,n,min,j:longint;
begin
  readln(n,k);
  for i:=1 to n do readln(a[i]);
  dp[0]:=0;
  for i:=1 to k do
  begin
    min:=2000000000;
    for j:=1 to n do if (a[j]<=i) then
    if (1+dp[i-a[j]]<min) then min:=1+dp[i-a[j]];
    dp[i]:=min;
  end;
  if (dp[k]<2000000000) then writeln(dp[k]) else writeln('-1');
end.
