{Homotetija sa koeficijentom homotetije k}

program homotetija;
uses graph,crt;
var gd,gm:integer;
    Xa,Ya,Xh,Yh,Xah,Yah:integer;
    k:real;
begin
   read(Xa,Ya,Xh,Yh,k);
   Xah:=round(k*Xa+(1-k)*Xh);
   Yah:=round(k*Ya+(1-k)*Yh);

   gd:=detect;
   initgraph(gd,gm,'');
   putpixel(Xa,Ya,yellow);
   putpixel(Xh,Yh,red);
   putpixel(Xah,Yah,white);
   delay(10000);
   closegraph;
end.
