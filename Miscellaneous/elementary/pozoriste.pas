{m-broj glumaca,k-broj omiljenih glumaca,n-broj predstava,
 predstava je omiljena ako je broj omiljenih glumaca >= nego kod ostalih;
 ako je predstava sigurno omiljena stampati 0,ako sigurno nije 1,a u ostalim slucajevima 2}
program p1;
var m,k,x,i,n,j,b,bro,br0:integer;
    a:set of 0..100;
    min,max:array[1..100] of integer;
begin
  readln(m,k);
  for i:=1 to k do begin read(x); a:=a+[x]; end;
  readln(n);
  for i:=1 to n do
  begin
    br0:=0; bro:=0;
    readln(b);
    for j:=1 to b do
    begin
      read(x);
      if x=0 then inc(br0) else if x in a then inc(bro);
    end;
    if k-bro>=br0 then max[i]:=bro+br0 else max[i]:=k;
    if m-k-b+bro>=0 then min[i]:=bro else min[i]:=k-m+b;
  end;
  for i:=1 to n do
  begin
    br0:=0; bro:=0;
    for j:=1 to n do
     if i<>j then
     begin
      if max[i]<min[j] then inc(bro);
      if min[i]>=max[j] then inc(br0);
     end;
    if br0=n-1 then writeln(0) else if bro>0 then writeln(1) else writeln(2);
  end;
end.