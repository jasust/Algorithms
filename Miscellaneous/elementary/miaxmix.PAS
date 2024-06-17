Program p1;
var n,x,i,max,mix,a,b:integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(x);
    if x=max then a:=a+1;
    if x=mix then b:=b+1;
    if x>max then
    begin
      mix:=max;
      max:=x;
      b:=a;
      a:=1;
    end;
    if (x<max) and (x>mix) then
    begin
      mix:=x;
      b:=1;
    end;
  end;
  write(mix,' ',b);
end.