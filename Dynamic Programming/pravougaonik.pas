program p4;
var n,i,j,Dx,Dy,Gx,Gy,Max,P:integer;
    a,DP,Dr,Dd:array[0..100,0..100] of integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do read(a[i,j]);
    readln;
  end;
  for i:=n downto 1 do
  for j:=n downto 1 do
  if (a[i,j]=0) then
  begin
    Dr[i,j]:=Dr[i,j+1]+1;
    Dd[i,j]:=Dd[i+1,j]+1;
  end
  else
   begin
    Dr[i,j]:=0;
    Dd[i,j]:=0;
   end;
  for i:=1 to n do
  for j:=1 to n do if (a[i,j]=1) then
  dp[i,j]:=dp[i-1,j]-dp[i-1,j-1]+dp[i,j-1]+1
  else dp[i,j]:=dp[i-1,j]-dp[i-1,j-1]+dp[i,j-1];
  for i:=1 to n do
  for j:=1 to n do
  if (dp[i+dd[i,j]-1,j+dr[i,j]-1]+dp[i-1,j-1]-dp[i+dd[i,j]-1,j-1]-dp[i-1,j+dr[i,j]-1]=0) then
    begin
     P:=Dd[i,j]*Dr[i,j];
     if (P>Max) then
      begin
       MaX:=P;  Gx:=i;   Gy:=j;  Dx:=i+dd[i,j]-1;  Dy:=j+dr[i,j]-1;
      end;
    end;
  writeln(MaX,' ',Gx,' ',Gy,' ',Dx,' ',Dy);
end.