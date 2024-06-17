program particije;
var dp:array[1..50,1..50] of integer;
    i,j,n:integer;
begin
  read(n);
  for i:=1 to n do
  begin
    dp[1,i] := 1;
    dp[i,1] := 1;
  end;
  for i:=2 to n do
  for j:=2 to n do
  if ( i <= j ) then
  dp[i,j] := dp[i,i-1] + 1
  else dp[i,j] :=dp [i-j,j] + dp[i,j-1];
  writeln(dp[n,n]);
end.
