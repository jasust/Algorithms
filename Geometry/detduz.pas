{ako je dato n duzi odredi koliko ima preseka i udaljenost najdaljeg od kordinatnog pocetka}
program treci;
var n,i,j,k,s,l,P1,P2:integer; tx,ty,r,max:real;
    x1,x2,y1,y2:array[1..100]of integer; v:array[1..100]of record x,y:real; end;
function A(q:integer):integer;
begin A:=y1[q]-y2[q]; end;

function B(q:integer):integer;
begin B:=x2[q]-x1[q]; end;

function C(q:integer):integer;
begin C:=y1[q]*x2[q]-y2[q]*x1[q]; end;

function D(q,w:integer):integer;
begin D:=A(q)*B(w)-A(w)*B(q); end;

function Dx(q,w:integer):integer;
begin Dx:=C(q)*B(w)-C(w)*B(q); end;

function Dy(q,w:integer):integer;
begin Dy:=A(q)*C(w)-A(w)*C(q); end;

begin
  readln(n);
  for i:=1 to n do read (x1[i],y1[i],x2[i],y2[i]);
  for i:=1 to n-1 do
   for j:=i+1 to n do
   begin
     P1:=(y1[j]-y1[i])*(x2[i]-x1[i])-(y2[i]-y1[i])*(x1[j]-x1[i]);
     P2:=(y2[j]-y1[i])*(x2[i]-x1[i])-(y2[i]-y1[i])*(x2[j]-x1[i]);
     if P1*P2<=0 then
     begin
       P1:=(y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]);
       P2:=(y2[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x2[i]-x1[j]);
       if P1*P2<=0 then
       begin
         tx:=Dx(i,j)/D(i,j);
         ty:=Dy(i,j)/D(i,j);
         for l:=1 to s do if (v[l].x=tx) and (v[l].y=ty) then k:=k+1;
         if k=0 then begin s:=s+1; v[s].x:=tx; v[s].y:=ty; end;
       end;
     end;
   end;
   writeln('ima ',s,' preseka');
   for i:=1 to s do begin r:=sqrt(sqr(v[i].x)+sqr(v[i].y));if r>max then max:=r;end;
   writeln('najvece rastojanje preseka je duzine ',max:0:3);
end.
