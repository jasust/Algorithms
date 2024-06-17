program p2;
var k,l,x:array[1..10000] of integer;
    a,b,s,y,i:integer;
procedure step(p:integer);
var m,j:integer;
begin
  for j:=2 to p do
  begin
    m:=p; k[p]:=0;
    while m mod j=0 do
    begin
      m:=m div j;
      k[p]:=k[p]+1;
    end;
    if (m=1) and (k[p]>l[p]) then begin l[p]:=k[p]; x[p]:=j; end;
  end;
end;
begin
  readln(a,b);
  step(a);
  s:=l[a]; y:=x[a];
  for i:=a+1 to b do begin step(i); if (l[i]>s) or ((l[i]=s) and (x[i]<y)) then begin s:=l[i]; y:=x[i]; end; end;
  write(y,' ',s);
end.