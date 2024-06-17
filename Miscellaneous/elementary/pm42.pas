program p1;
type niz=array[0..100000] of longint;
var a,b:niz; i,n:longint;

procedure quics(var a:niz; d,g:integer);
var i,j,p,mesto:integer;
begin
  if d<g then
  begin
    i:=d;  j:=g;  mesto:=a[d];
    while (i<j) do
    begin
      while(a[i]<=mesto) and (i<j) do i:=i+1;
      while(a[j]>mesto) do j:=j-1;
      if(i<j) then
      begin
        p:=a[i];a[i]:=a[j];a[j]:=p;
      end;
    end;
    a[d]:=a[j];  a[j]:=mesto;
    quics(a,d,j-1);
    quics(a,j+1,g);
  end;
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=b[i-1]+a[i];
  end;
  quics(b,1,n);
  for i:=1 to n do write(b[i],' ');
end.