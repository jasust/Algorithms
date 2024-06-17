program boje2;
var n:longint;
function a(k:longint):int64;
var i:longint; s:int64;
begin
  if (k=1) then a:=1 else
   begin
     s:=0;
     for i:=1 to k-1 do s:=s+((i-1)*(k-1-i)+1);
     a:=s+a(k-1);
   end;
end;
begin
  readln(n);
  writeln(a(n));
end.