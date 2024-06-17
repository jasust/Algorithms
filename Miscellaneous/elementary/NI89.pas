program p1;
type niz=array[1..1000005] of longint;
var n,a,b,c,i:integer;
    e,x,y:niz;

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
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  read(a,b,c);
  for i:=1 to n do e[i]:=-(a*x[i]+b*y[i]);
  quics(e,1,n);
  writeln(a,' ',b,' ',e[n div 2]);
end.
