program p1;
var o,t,u,q,j,n,i,r,x1,y1:integer;
    s:string;
    x,y,max1,max2,min1,min2:array[1..1000] of integer;
begin
  readln(t);
  for j:=1 to t do
  begin
    u:=0;
    readln(n);
    for i:=1 to n do
    begin
      readln(s);
      if s[1]='p' then
      begin
        inc(u);
        delete(s,1,2);
        val(copy(s,1,pos(' ',s)-1),x[u],q);
        delete(s,1,pos(' ',s));
        val(s,y[u],q);
      end;
      if s[1]='c' then
      begin
        delete(s,1,2);
        val(copy(s,1,pos(' ',s)-1),x1,q);
        delete(s,1,pos(' ',s));
        val(copy(s,1,pos(' ',s)-1),y1,q);
        delete(s,1,pos(' ',s));
        val(s,r,q);
        inc(u);
        x[u]:=x1+r;
        y[u]:=y1;
        inc(u);
        x[u]:=x1-r;
        y[u]:=y1;
        inc(u);
        x[u]:=x1;
        y[u]:=y1+r;
        inc(u);
        x[u]:=x1;
        y[u]:=y1-r;
      end;
      if s[1]='l' then
      begin
        inc(u);
        delete(s,1,2);
        val(copy(s,1,pos(' ',s)-1),x[u],q);
        delete(s,1,pos(' ',s));
        val(copy(s,1,pos(' ',s)-1),y[u],q);
        inc(u);
        delete(s,1,pos(' ',s));
        val(copy(s,1,pos(' ',s)-1),x[u],q);
        delete(s,1,pos(' ',s));
        val(s,y[u],q);
      end;
    end;
    readln();
    inc(o);
    min1[o]:=maxint;
    max1[o]:=0-maxint;
    min2[o]:=maxint;
    max2[o]:=0-maxint;
    for i:=1 to u do
    begin
      if x[i]>max1[o] then max1[o]:=x[i];
      if x[i]<min1[o] then min1[o]:=x[i];
      if y[i]>max2[o] then max2[o]:=y[i];
      if y[i]<min2[o] then min2[o]:=y[i]
    end;
  end;
  for i:=1 to o do writeln(min1[i],' ',min2[i],' ',max1[i],' ',max2[i]);
end.