{Ako je dato n,n<10^5 tacaka u koordinatnom sistemu odrediti najmanju ugao
 koji obuhvata sve te tacke}
Program Codeforces;
var i,n,j,s,f,x,y:longint;
    u:array[0..100001] of real;
    t,max,h,l:real;
begin

  readln(n);
  if n=1 then begin write('0.000000'); halt(0); end;
  for i := 1 to n do
  begin                                 //odredjivanje ugla koji prava koja sadrzi
    readln(x,y);                        //koordinatni pocetak i datu tacku zaklapa sa x osom
    if y > 0 then u[i]:=(arctan(x/y)*180)/pi
     else if y < 0 then u[i]:=((arctan(x/y)*180)/pi)+180
      else if x < 0 then u[i]:=270.0
       else u[i]:=90.0;
  end;

  for i:=2 to n do
  begin
    h:=u[i]; s:=i; f:=s div 2;
    while ((s>1) and (u[f]<h)) do
    begin
      u[s]:=u[f]; s:=f; f:=s div 2;
    end;
    u[s]:=h;
  end;                                      //sortiranje uglova heap sortom
  for i:=n downto 2 do
  begin
    l:=u[i]; u[i]:=u[1]; f:=1;
    if (i-1>=3) and (u[3]>u[2]) then s:=3 else s:=2;
    while (s<=i-1) and (u[s]>l) do
    begin
      u[f]:=u[s]; f:=s; s:=2*f;
      if (s+1<=i-1) and (u[s+1]>u[s]) then s:=s+1;
    end;
    u[f]:=l;
  end;

  max:=360-u[n]+u[1];              //odredjivanje maximalnog ugla izmedju dve tacke
  for i := 1 to n-1 do
   if u[i+1]-u[i] > max then max := u[i+1]-u[i];
  writeln(360-max:0:8);
end.                         //360-max je upravo resenje zadatka
