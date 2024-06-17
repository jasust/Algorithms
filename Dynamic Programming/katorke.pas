{Za dati niz odrediti k-torku clanova, takvu da je suma apsolutnih razlika svaka
 dva clana te k-torke najmanja}
program katorke;
type niz=array[1..100] of integer;
var a:niz; j,i,n,k,k1,p,s,s1,sm,m,r,r1,pom:integer;

procedure quics(var a:niz;d,g:integer);
var i,j,p,mesto:integer;
begin
  if d<g then
  begin
    i:=d; j:=g; mesto:=a[d];
    while (i<j) do
    begin
      while(a[i]<=mesto) and (i<j) do i:=i+1;
      while(a[j]>mesto) do j:=j-1;
      if(i<j) then
      begin
        p:=a[i];a[i]:=a[j];a[j]:=p;
      end;
    end;
    a[d]:=a[j]; a[j]:=mesto;
    quics(a,d,j-1);
    quics(a,j+1,g);
  end;
end;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  quics(a,1,n); pom:=1-k;
  for i:=1 to k do inc(s,a[i]);
  for i:=1 to k do begin r:=r+pom*a[i]; inc(pom,2); end;
  sm:=s; m:=r; k1:=1;
  for i:=2 to n-k+1 do
  begin
    s1:=s-a[i-1]+a[i+k-1];
    r1:=r+(k-1)*a[i-1]-2*(s1-a[i+k-1])+(k-1)*a[i+k-1];
    if r1<m  then
    begin
      m:=r1; k1:=i; sm:=s1;
    end
    else if(r1=m) and (s1>sm) then
    begin
      m:=r1; k1:=i; sm:=s1;
    end;
    s:=s1; r:=r1;
  end;
  for i:=k1 to k1+k-1 do write(a[i],' ');
end.