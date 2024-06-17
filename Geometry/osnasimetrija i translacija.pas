{1.Dat je pravougli trougao cije su katete paralelne osama, krajevima hipotenuze.
 Koordinate temena pravog ugla su manje od a i b. Ako su koordinate centra kruga celobrojne
 opisati krug. Datu sliku preslikaj osno simetricno u odnosu na pravu PQ. Dobijenu
 sliku preslikati translacijom za vektor v}
program p1;
uses graph,crt;
var gd,gm,xa,ya,xb,yb,xp,yp,xq,yq,xv,yv,p,r : integer;
    xc,yc,D,Dx,Dy,xr,yr,cna,cnb,cnc,cpq,an,bn,cnr : longint;
    PathToDriver : string;
    pos:boolean;
begin
  read(xa,ya,xb,yb);
  read(xp,yp,xq,yq);
  read(xv,yv);
  gd:=detect; gm:=0;
  PathToDriver:='C:\PP\BGI';
  InitGraph(gd,gm,PathToDriver);
  if GraphResult<>grok then halt(0);

  if xa>xb then begin p:=xa; xa:=xb; xb:=p; p:=ya; ya:=yb; yb:=p; end;
  if odd(xa-xb) or odd(ya-yb) then pos:=false else pos:=true;
  line(xa,ya,xb,yb);
  line(xa,yb,xb,yb);
  line(xa,ya,xa,yb);
  xc:=xa; yc:=yb;
  if pos then begin xr:=(xb+xa) shr 1; yr:=(ya+yb) shr 1; end;
  r:=trunc(sqrt(sqr(xb-xa)+sqr(ya-yb))) shr 1;
  if pos then circle(xr,yr,r);

  an:=xq-xp;
  bn:=yq-yp;
  cna:=-xa*an-ya*bn;
  cnb:=-xb*an-yb*bn;
  cnc:=-xc*an-yc*bn;
  cpq:=xp*bn-yp*an;
  if pos then cnr:=-xr*an-yr*bn;
  D:=an*an+bn*bn;
  Dx:=cna*an-cpq*bn;
  Dy:=an*cpq+bn*cna;
  xa:=-2*round(Dx/D)-xa;
  ya:=-2*round(Dy/D)-ya;
  Dx:=cnb*an-cpq*bn;
  Dy:=an*cpq+bn*cnb;
  xb:=-2*round(Dx/D)-xb;
  yb:=-2*round(Dy/D)-yb;
  Dx:=cnc*an-cpq*bn;
  Dy:=an*cpq+bn*cnc;
  xc:=-2*round(Dx/D)-xc;
  yc:=-2*round(Dy/D)-yc;
  if pos then begin
  Dx:=cnr*an-cpq*bn;
  Dy:=an*cpq+bn*cnr;
  xr:=-2*round(Dx/D)-xr;
  yr:=-2*round(Dy/D)-yr; end;
  line(xa,ya,xc,yc);
  line(xb,yb,xc,yc);
  line(xa,ya,xb,yb);
  if pos then circle(xr,yr,r);

  xa:=xa+xv; ya:=ya+yv;
  xb:=xb+xv; yb:=yb+yv;
  xc:=xc+xv; yc:=yc+yv;
  if pos then begin xr:=xr+xv; yr:=yr+yv; end;
  line(xa,ya,xc,yc);
  line(xb,yb,xc,yc);
  line(xa,ya,xb,yb);
  if pos then circle(xr,yr,r);

  delay(10000);

  CloseGraph;
end.
