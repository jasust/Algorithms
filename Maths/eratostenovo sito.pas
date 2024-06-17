//   O(N)   //
program esito;
const N=10000000;
var i,j,k:longint;
    lp,pr:array[0..10000000] of longint;
begin
  for i:=2 to N do
  begin
    if lp[i]=0 then
    begin
      lp[i]:=i;
      inc(k);
      pr[k]:=i;
      write(i,' ');
    end;
    j:=0;
    while (j<=k) and (pr[j]<=lp[i]) and (i*pr[j]<=N) do
    begin
      lp[i*pr[j]]:=pr[j];
      inc(j);
    end;
  end;
end.
