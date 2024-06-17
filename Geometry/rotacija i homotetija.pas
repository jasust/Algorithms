{2. Datu duz preslikati homotetijom , pa rotacijom.}
program homotetija;
uses graph,crt;
var gd,gm:integer;
    xa,ya,xb,yb,xh,yh,xr,yr,fi,xah,yah,xbh,ybh,xar,yar,xbr,ybr:integer;
    k:real;
begin
   read(xa,ya,xb,yb,xh,yh,k,xr,yr,fi);

   Xah:=round(k*Xa+(1-k)*Xh);
   Yah:=round(k*Ya+(1-k)*Yh);
   Xbh:=round(k*Xb+(1-k)*Xh);
   Ybh:=round(k*Yb+(1-k)*Yh);

   Xar:=round(Xah*cos(fi/57.295)-Yah*sin(fi/57.295)+Xr);
   Yar:=round(Xah*sin(fi/57.295)+Yah*cos(fi/57.295)+Yr);
   Xbr:=round(Xbh*cos(fi/57.295)-Ybh*sin(fi/57.295)+Xr);
   Ybr:=round(Xbh*sin(fi/57.295)+Ybh*cos(fi/57.295)+Yr);

   gd:=detect;
   initgraph(gd,gm,'');
   line(Xa,Ya,Xb,Yb);
   putpixel(Xh,Yh,white);
   line(Xah,Yah,Xbh,Ybh);
   putpixel(Xr,Yr,white);
   line(Xar,Yar,Xbr,Xbr);
   repeat until keypressed;
   closegraph;
end.
