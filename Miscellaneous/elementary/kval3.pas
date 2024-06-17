program p1;
var n,q,i,x:longint; min,max:int64;
    b:array[0..100001] of int64;
begin
  read(n,q);
  for i:=1 to n do
  begin
    read(x);
    b[i]:=b[i-1]+x;
  end;
  for i:=1 to n do
  begin
    min:=b[i];
    if b[n]-b[i]<b[i] then min:=b[n]-b[i];
    if min>max then max:=min;
  end;
  for i:=1 to q do
  begin
    read(x);
    if max<=x then writeln('n') else writeln('d');
  end;
end.
