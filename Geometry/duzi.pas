Program duzi;
var x1,y1,x2,y2,x3,y3,x4,y4,Pa,Pb,Pc,Pd,k:integer;
    k1,k2,n1,n2,x,y:real;
begin
    readln(x1,y1,x2,y2,x3,y3,x4,y4);
    k:=0;
    Pa:=(y1-y3)*(x4-x3)-(y4-y3)*(x1-x3);
    Pb:=(y2-y3)*(x4-x3)-(y4-y3)*(x2-x3);
    if Pa*Pb<=0 then k:=k+1;
    Pc:=(y3-y1)*(x2-x1)-(y2-y1)*(x3-x1);
    Pd:=(y4-y1)*(x2-x1)-(y2-y1)*(x4-x1);
    if Pc*Pd<=0 then k:=k+1;
    if k=2 then
       begin
       k1:=(y2-y1)/(x2-x1);
       k2:=(y4-y3)/(x4-x3);
       n1:=y1-k1*x1;
       n2:=y3-k2*x3;
       x:=(n2-n1)/(k1-k2);
       y:=k1*x+n1;
       write('Duzi se seku u tacki x=',x,' ','y=',y);
       end
    else
    write('Duzi se seku')
end.