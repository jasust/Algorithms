uses SysUtils,DateUtils;
var t1,t2:TDateTime;
    a,b,c:longint;
begin
  readln(a,b);
  t1:=TimeOf(Now);
  //c:=a- (b mod 3)- (b div 3);
  writeln(a- (b mod 3)- (b div 3));
  t2:=TimeOf(Now);
  writeln('Vreme rada programa je: ',(MilliSecondsBetween(t1,t2)/1000):0:4,' sekundi');
end.
