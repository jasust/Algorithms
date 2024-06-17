{Za ucitanu matricu nxm odrditi odgovarajuca minska polja tako da se mine
 prebrojavaju za sva susedna polja}
program mine1;
var a,d:array[0..50,0..50] of integer;
    n,m,i,j,k,l,y,g:integer; s:string;
begin
  readln(n,m);
  for j:=1 to n do
  begin
    readln(s);
    for k:=1 to m do val(copy(s,k,1),d[j,k],i);
  end;
  repeat
  begin
    i:=1;
    while a[1,i]<>0 do
    begin
      a[1,i]:=0;
      inc(i);
    end;
    a[1,i]:=1;
    for j:=2 to n+1 do a[j,1]:=0;
  repeat
  begin
    g:=2;
    while a[g,1]<>0 do
    begin
      a[g,1]:=0;
      inc(g);
    end;
    a[g,1]:=1;
    l:=0;
    for j:=2 to n do
     for k:=2 to m do
     begin
      y:=d[j-1,k-1]-a[j-1,k]-a[j-1,k-2]-a[j-2,k-1]-a[j-2,k-2]-a[j-2,k]-a[j,k-1]-a[j,k-2];
      if (y=1) or (y=0) then begin a[j,k]:=y; inc(l); end;
     end;
    for j:=1 to m-1 do if d[n,j]=a[n-1,j]+a[n,j+1]+a[n,j-1]+a[n-1,j-1]+a[n-1,j+1] then inc(l);
    if -d[n,m]=-a[n-1,m]-a[n,m-1]-a[n-1,m-1] then inc(l,2);
    for j:=2 to n-1 do if -d[j,m]=-a[j-1,m]-a[j-1,m-1]-a[j,m-1]-a[j+1,m-1]-a[j+1,m] then inc(l);
    if l=m*n then
    begin
     for j:=1 to n do
     begin
      for k:=1 to m do write(a[j,k]);
      writeln;
     end;
    end;
  end;
  until a[n+1,1]=1;
  end;
  until a[1,m+1]=1;
end.
