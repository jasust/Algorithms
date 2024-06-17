{Translacija za zadati vektor}

program translacija;
uses graph,crt;
var gd,gm:integer;
    Xa,Ya,Xt,Yt,Xat,Yat:integer;
begin
   read(Xa,Ya,Xt,Yt);
   Xat:=Xa+Xt;
   Yat:=Ya+Yt;

   gd:=detect;
   initgraph(gd,gm,'');
   putpixel(Xa,Ya,red);
   putpixel(Xat,Yat,white);
   delay(10000);
   closegraph;
end.
