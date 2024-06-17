{Zadata je staza duzine n koja ima q rupa. Za svaku rupu zadate su leva i desna
granica odredjene celim brojevima. Rupe su disjunktne i redom su poredjane. Koja
je minimalna duzina koraka kojom se moze preci staza a da se ne upadne u rupu}

program p1;
var a:array[0..10005] of boolean;
    b:array[0..1005] of longint;
    n,q,i,l,d,k,divisor,max,j:longint;
    sol,pom:real;
begin
  readln(n,q);
  for i:=1 to q do
  begin
    read(l,d);
    if d-l-1>max then max:=d-l-1;
    for j:=l to d do a[j]:=true;
    inc(k); b[k]:=d;
  end;
  sol:=n;
  for i:=1 to k do
  begin
    divisor:=1;
    while b[k]/divisor>=max do
    begin
      pom:=b[k]/divisor;
      while pom<=n do
      begin
        if (a[trunc(pom)]=true) and (a[trunc(pom)+1]=true) then break;
        pom:=pom+b[k]/divisor;
      end;
      if pom>=n then sol:=b[k]/divisor;
      inc(divisor);
    end;
    if sol<>n then break;
  end;
  writeln(sol:0:2);
end.
