Program P4;
var n,a,b0,b1,b2,b3,b4,b5,b6,b7,b8,b9:longint;
begin
  read(n);
  while n>0 do
  begin
    a:=n mod 10;
    n:=n div 10;
    case a of
    0:b0:=b0 + 1;
    1:b1:=b1 + 1;
    2:b2:=b2 + 1;
    3:b3:=b3 + 1;
    4:b4:=b4 + 1;
    5:b5:=b5 + 1;
    6:b6:=b6 + 1;
    7:b7:=b7 + 1;
    8:b8:=b8 + 1;
    9:b9:=b9 + 1;
   end;
  end;
  writeln('0:',b0);
  writeln('1:',b1);
  writeln('2:',b2);
  writeln('3:',b3);
  writeln('4:',b4);
  writeln('5:',b5);
  writeln('6:',b6);
  writeln('7:',b7);
  writeln('8:',b8);
  writeln('9:',b9);
end.