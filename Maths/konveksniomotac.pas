program p1;
var n,i,j,k:integer;p:array [1..50,1..50] of boolean;
    levo,desno:boolean;x,y:array [1..50] of integer;
    o:array [1..50] of boolean;

function levoskr(x3,y3,x1,y1,x2,y2:integer):boolean;
begin
  if ((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1)>=0) then levoskr:=true else levoskr:=false;
end;

begin
  readln(n);
  for i:=1 to n do read(x[i],y[i]);
  writeln('Tacke koje predstavljaju temena konveksnog mnogougla su tacke sa rednim brojevima:');
  for i:=1 to n do
   for j:=1 to n do
    if i<>j then
    begin
      p[i,j]:=true; desno:=false; levo:=false;
      for k:=1 to n do
      if (k<>i) and (k<>j) then
      if not(levoskr(x[k],y[k],x[i],y[i],x[j],y[j])) then
      begin
        desno:=true;
        if levo=true then
        begin
          p[i,j]:=false;
          break;
        end;
      end else
      begin
        levo:=true;
        if desno=true then
        begin
          p[i,j]:=false;
          break;
        end;
      end;
      if p[i,j]  then
      begin
        if not o[i] then write(i,' ');
        if not o[j] then write(j,' ');
        o[i]:=true;
        o[j]:=true;
      end;
    end;
end.
