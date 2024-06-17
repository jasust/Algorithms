program p1;
var i,j,k,s,max,min,pom,p:longint; ch:char;
    a:array[1..8,1..8] of integer;
    b:array[1..17] of integer;
begin
  for i:=1 to 8 do
  begin
    for j:=1 to 8 do
    begin
      read(ch);
      if ch='+' then a[i,j]:=1 else a[i,j]:=0;
    end;
    readln();
  end;
  readln(k);
  repeat
    s:=0; pom:=0;
    for i:=1 to 16 do if b[i]=1 then inc(pom);
    if (pom<=k) and not(odd(k-pom)) then
    begin
      for i:=1 to 8 do
       for j:=9 to 16 do
        if ((b[i]=b[j]) and (a[i,j-8]=1)) or
            ((b[i]<>b[j]) and (a[i,j-8]=0)) then inc(s);
      min:=9;
      if s>max then max:=s;
    end;
    p:=1;
	  while b[p]<>0 do
	  begin
	    b[p]:=0;
	    inc(p);
	  end;
	  b[p]:=1;
  until b[17]=1;
  writeln(max);
end.