{Centralna simetrija}

program centralna;
uses graph,crt;
var gd,gm:integer;
    Xa,Ya,Xc,Yc,Xac,Yac:integer;
begin
   read(Xa,Ya,Xc,Yc);
   Xac:=2*Xc-Xa;
   Yac:=2*Yc-Ya;

   gd:=detect;
   initgraph(gd,gm,'');
   putpixel(Xa,Ya,yellow);
   putpixel(Xc,Yc,red);
   putpixel(Xac,Yac,white);
   delay(10000);
   closegraph;
end.
