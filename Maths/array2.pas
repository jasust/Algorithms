{Ako je zadat niz od n (3<=n<=100) celih brojeva, podeliti taj niz na tri dela tako da je
 proizvod prvog negativan, drugog pozitivan i treceg jednak nuli. Resenje uvek postoji.}
program array2;
var a:array[1..101] of integer;
    n,i,br1:integer; br2:boolean;
    b:array[1..5] of integer;
begin
  readln(n);
  for i:=1 to n do
  begin                           //Program radi po istom principu kao array1.pas
    read(a[i]);                   //samo sto na racun niza b radi u O(n) dok array2.pas
    if (a[i]<0) and (br1<3) then  //radi u O(n^2), ali nema neke velike razlike jer je n<=100
    begin
      inc(br1);
      b[br1]:=i;
    end else
    if (a[i]>0) and not(br2) then
    begin
      b[4]:=i;
      br2:=true;
    end;
  end;
  if br2 then
  begin
    writeln('1 ',a[b[1]]);
    writeln('1 ',a[b[4]]);
    write(n-2,' ');
    for i:=1 to n do if (i<>b[1]) and (i<>b[4]) then write(a[i],' ');
  end else
  begin
    writeln('1 ',a[b[1]]);
    writeln('2 ',a[b[2]],' ',a[b[3]]);
    write(n-3,' ');
    for i:=1 to n do if (i<>b[1]) and (i<>b[2]) and (i<>b[3]) then write(a[i],' ');
  end;
end.