program p1;
var x,y,smer,sol:integer; x1,y1:longint;
begin
  readln(x,y);
  x1:=0; y1:=0; smer:=2;
  while (x1<>x) or (y1<>y) do
  begin
    if (x1=y1) and (x1>0) then begin inc(sol); smer:=4; end;
    if (x1+y1=1) and (x1>0) then begin inc(sol); smer:=3; end;
    if (x1=y1) and (x1<0) then begin inc(sol); smer:=2; end;
    if (x1+y1=0) and (x1<0) then begin inc(sol); smer:=1; end;
    if smer=1 then dec(y1)
     else if smer=2 then inc(x1)
      else if smer=3 then inc(y1)
       else dec(x1);
  end;
  writeln(sol);
end.

