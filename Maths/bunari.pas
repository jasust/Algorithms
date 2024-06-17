{Zadata je staza duzine n koja ima q rupa. Za svaku rupu zadate su leva i desna
granica odredjene celim brojevima. Rupe su disjunktne i redom su poredjane. Koja
je minimalna duzina koraka kojom se moze preci staza a da se ne upadne u rupu}

program p1;
type niz=array[0..1005] of real;
var a:array[0..10005] of boolean;
    b:niz; sol,pom:real;
    n,q,i,l,d,k,divisor,j,br,max:longint;

procedure quics(var e:niz; d,g:longint);
var i,j:longint; mesto,p:real;
begin
  if d<g then
  begin
    i:=d; j:=g; mesto:=e[d];
    while (i<j) do
    begin
      while(e[i]<=mesto) and (i<j) do i:=i+1;
      while(e[j]>mesto) do j:=j-1;
      if(i<j) then
      begin
        p:=e[i]; e[i]:=e[j]; e[j]:=p;
      end;
    end;
    e[d]:=e[j];  e[j]:=mesto;
    quics(e,d,j-1);
    quics(e,j+1,g);
  end;
end;

begin
  readln(n,q);
  for i:=1 to q do
  begin
    read(l,d);
    if d-l-1>max then max:=d-l-1;   //najmanji korak je sigurno >= od najduzeg bunara
    for j:=l+1 to d do a[j]:=true;  //bunare obelezavamo sa true, ne ukljucujuci levu granicu
    inc(k); b[k]:=d;
  end;
  br:=k;
  for i:=1 to k do
  begin
    divisor:=2;
    while b[i]/divisor>=max do  //u najoptimalnijem resenju sigurno gazimo na neku od
    begin                       //desnih granica-zato generisemo sve mogucnosti za korake
      inc(br);
      b[br]:=b[i]/divisor;
      inc(divisor);
    end;
  end;
  quics(b,1,br);
  sol:=n;
  for i:=1 to br do
  begin
    pom:=b[i];
    while pom<=n do         //najmanji korak koji zadovoljava uslove je resenje
    begin
      if a[trunc(pom)+1] and not((trunc(pom)=pom) and not(a[trunc(pom)])) then break;
      pom:=pom+b[i];
    end;
    if pom>=n then begin sol:=b[i]; break; end;
  end;
  writeln(sol:0:2);
end.
