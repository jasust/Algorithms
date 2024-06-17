program p1;
var i,j,k,x,s,max,min,pom,p:longint;
    a:array[1..8,1..8] of integer;
    b,kr,kr1,v,red:array[1..9] of integer;
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
        inc(max);
        inc(v[i]);
        inc(red[j]);
      end
      else a[i,j]:=0;
    end;
  end;
  readln(k);
  repeat
    s:=0; pom:=0;
    for i:=1 to 8 do if b[i]=1 then inc(pom);
    if pom<=k then
     for i:=1 to 8 do
     begin
       if b[i]=0 then s:=s+v[i];
       if b[i]=1 then s:=s+8-v[i];
     end;
     if s>max then
     begin
       max:=s;
       kr:=b;
       x:=pom;
     end;
     p:=1;
	   while b[p]<>0 do
	   begin
	     b[p]:=0;
	     inc(p);
	   end;
	   b[p]:=1;
  until b[9]=1;
  fillchar(b,sizeof(b),0);
  for i:=1 to 8 do
   if kr[i]=1 then
   begin
     v[i]:=8-v[i];
     for j:=1 to 8 do
     begin
       if a[i,j]=1 then dec(red[j]);
       if a[i,j]=0 then inc(red[j]);
     end;
   end;
   dec(k,x);
   x:=0;
   repeat
     s:=0; pom:=0;
     for i:=1 to 8 do if b[i]=1 then inc(pom);
     if pom<=k then
      for i:=1 to 8 do
      begin
        if b[i]=0 then s:=s+red[i];
        if b[i]=1 then s:=s+8-red[i];
      end;
      if s>max then
      begin
        max:=s;
        kr1:=b;
        x:=pom;
      end;
      p:=1;
	    while b[p]<>0 do
	    begin
	      b[p]:=0;
	      p:=p+1;
	    end;
	    b[p]:=1;
  until b[9]=1;
  dec(k,x);
  min:=64;
  if k mod 2=0 then writeln(max) else
  begin
    for i:=1 to 8  do
    begin
      if v[i]<min then min:=v[i];
      if red[i]<min then min:=red[i];
    end;
    max:=max-min;
    max:=max+8-min;
    writeln(max);
  end;
end.