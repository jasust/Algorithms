program faktorizacija;
const n=100000000;
var i,j,k,y,br,t:longint; x,dob:int64;
    lp,pr:array[0..100000000] of longint;
begin
  read(t);
  for i:=2 to n do
  begin
    if lp[i]=0 then
    begin
      lp[i]:=i;
      inc(k);
      pr[k]:=i;
    end;
    j:=0;
    while (j<=k) and(pr[j]<=lp[i])
           and (i*pr[j]<=n) do
    begin
      lp[i*pr[j]]:=pr[j];
      inc(j);
    end;
  end;
  for i:=1 to t do
  begin
    read(x,y); br:=1;
    while x mod pr[br]<>0 do inc(br);
    write(pr[br]);
    dob:=pr[br];
    while dob<x do begin inc(br,y+1); write('*',pr[br]); dob:=dob*pr[br]; end;
  end;
end.
end.
