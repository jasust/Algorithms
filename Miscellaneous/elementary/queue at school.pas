program p1;
var n,t,i,j:integer; p:char;
    a:array[1..50] of char;
begin
  readln(n,t);
  for i:=1 to n do read(a[i]);
  for j:=1 to t do
  begin
    i:=n;
    while i>=2 do
    begin
      if (a[i]='G') and (a[i-1]='B') then
      begin
        a[i-1]:='G';
        a[i]:='B';
        dec(i,2);
      end else dec(i);
    end;
  end;
  for i:=1 to n do write(a[i]);
end.
