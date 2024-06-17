{Ako je zadat niz od n (3<=n<=100) celih brojeva, podeliti taj niz na tri dela tako da je
 proizvod prvog negativan, drugog pozitivan i treceg jednak nuli. Resenje uvek postoji.}
program array1;
var x,p,i,n,j:longint;
    a:array[0..101] of longint;
begin

  read(n);
  for i:=1 to n do
  begin                      //Kako je uslovom zadatka zagarantovano postojanje
    read(a[i]);              //bar jednog negativnog broja nas samo interesuje
    if (a[i]>0) then inc(x); //da li postoje i pozitivni brojevi u ovom nizu
  end;

  for i:=1 to n-1 do
   for j:=i+1 to n do    // Posto je n malo, sortiranjem mozemo izbeci
    if (a[i]>a[j]) then  // pamcenje indeksa i zakomplikovavanje programa
    begin
      p:=a[i];
      a[i]:=a[j];
      a[j]:=p;
    end;

  if x>0 then
  begin
    writeln(1,' ',a[1]);   //Dovoljno je ispisati jedan pozitivan, jedan
    writeln(1,' ',a[n]);   //negativan, i sve ostale brojeve kada ima pozitivnih
    write(n-2,' ');
    for i:=2 to n-1 do write(a[i],' ');
  end else
  begin
    writeln(1,' ',a[1]);           //i jedan negativan, dva negativna i sve
    writeln(2,' ',a[2],' ',a[3]);  //ostale, ako nema pozitivnih brojeva
    write(n-3,' ');
    for i:=4 to n do write(a[i],' ');
  end;

end.
