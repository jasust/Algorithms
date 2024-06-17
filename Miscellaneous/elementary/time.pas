program time;
var n,d,i,x,y,x1,y1,t:longint; sol,p:int64;
    a:array[1..105] of longint;
begin
  readln(n,d);
  for i:=2 to n-1 do read(a[i]);
  readln(x,y);
  for i:=2 to n do
  begin
    readln(x1,y1);
    p:=d*(abs(x1-x)+abs(y1-y));
    if t<p then begin sol:=sol+p-t; t:=0; end
     else t:=t-p;
    x:=x1; y:=y1;
    inc(t,a[i]);
  end;
  writeln(sol);
end.

