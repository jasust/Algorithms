program p1;
type niz=array[1..1024] of longint;
var n,a,b,c,x,y,i:integer;
    e:niz; sol:real;

procedure quics(var e:niz; d,g:integer);
var i,j,p,mesto:longint;
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
  readln(n,a,b,c);
  for i:=1 to n do
  begin
    read(x,y);
    e[i]:=-(a*x+b*y);
  end;
  quics(e,1,n);
  sol:=(e[n div 2]+e[(n+1) div 2])/2;
  writeln(a,' ',b,' ',sol:0:2);
end.
