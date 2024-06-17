program p1;
var i,j,k,s,max,min,pom,p:longint;
    a:array[1..8,1..8] of integer;
    b,v,red:array[1..17] of integer;
    st:string;
begin
  for i:=1 to 8 do
  begin
    readln(st);
    for j:=1 to 8 do
    begin
      if st[j]='+' then
      begin
        a[i,j]:=1;
        inc(v[i]);
        inc(red[j]);
      end
      else a[i,j]:=0;
    end;
  end;
  readln(k);
  repeat
    s:=0; pom:=0;
    for i:=1 to 16 do if b[i]=1 then inc(pom);
    if (pom<=k) and not(odd(k-pom)) then
    begin
      for i:=1 to 8 do
       if b[i]=0 then inc(s,v[i])
        else inc(s,8-v[i]);
      for i:=9 to 16 do
       if b[i]=0 then inc(s,red[i-8])
        else inc(s,8-red[i-8]);
       min:=9; s:=s div 2;
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