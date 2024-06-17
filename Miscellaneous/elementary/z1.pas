program p1;
var m,s:array[1..5] of integer;
    i,t:integer;
function sek(n:integer):integer;
var x,y:array[1..1000] of longint;
    i,j,k,p1,p2:longint;
begin
  if n=3 then
  begin
    for i:=1 to 3 do readln(x[i],y[i]);
    sek:=1;
  end
  else
  begin
  k:=0;
  for i:=1 to n do readln(x[i],y[i]);
  x[n+1]:=x[1];y[n+1]:=y[1];
  for i:=1 to n-1 do
   for j:=i+1 to n do
   begin
     p1:=(y[j]-y[i])*(x[i+1]-x[i])-(y[i+1]-y[i])*(x[j]-x[i]);
     p2:=(y[j]-y[i])*(x[i+1]-x[i])-(y[i+1]-y[i])*(x[j]-x[i]);
     if p1*p2>=0 then k:=k+1;
   end;
  if k=((n-1)*n)/2 then sek:=1
  else sek:=-1;
  end;
end;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(m[i]);
    s[i]:=sek(m[i]);
  end;
  for i:=1 to t do if s[i]=1 then writeln('DA') else writeln('NE');
end.