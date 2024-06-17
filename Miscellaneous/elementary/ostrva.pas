{2.Data je matrica 1 i 0 i pocetna pozicija.Naci najblizi izlaz iz lavirinta (0 na ivici matrice) i sve izlaze}
Program D2;
var a:array [0..1000,0..1000] of longint;
    i,j,m,n,min,mx,my,px,py:longint;
procedure BFS(x,y:longint);
var t,u,tx,ty:longint;
    ls:array [0..1000,0..1000] of longint;
begin
  t:=1; u:=1; ls[t,1]:=x; ls[t,2]:=y;
  while (t<=u) do
   begin
     tx:=ls[t,1]; ty:=ls[t,2];
     if (tx+1<n+1) and (a[tx+1,ty]<>-1) and ( ((a[tx+1,ty]=0) and not((tx+1=x) and (ty=y)) ) or (a[tx+1,ty]>a[tx,ty]+1)) then
       begin inc(u); ls[u,1]:=tx+1; ls[u,2]:=ty; a[tx+1,ty]:=a[tx,ty]+1;  end;
     if (ty+1<m+1) and (a[tx,ty+1]<>-1) and (((a[tx,ty+1]=0) and not((tx=x) and (ty+1=y)) ) or (a[tx,ty+1]>a[tx,ty]+1)) then
       begin inc(u); ls[u,1]:=tx; ls[u,2]:=ty+1; a[tx,ty+1]:=a[tx,ty]+1; end;
     if (tx-1>0) and (a[tx-1,ty]<>-1) and (((a[tx-1,ty]=0) and not((tx-1=x) and (ty=y)) ) or (a[tx-1,ty]>a[tx,ty]+1)) then
       begin inc(u); ls[u,1]:=tx-1; ls[u,2]:=ty; a[tx-1,ty]:=a[tx,ty]+1; end;
     if (ty-1>0) and (a[tx,ty-1]<>-1) and (((a[tx,ty-1]=0) and not((tx=x) and (ty-1=y)) ) or (a[tx,ty-1]>a[tx,ty]+1)) then
       begin inc(u); ls[u,1]:=tx; ls[u,2]:=ty-1; a[tx,ty-1]:=a[tx,ty]+1; end;
     inc(t);
  end;
end;

begin
  readln (n,m);
  for i:=1 to n do
   for j:=1 to m do
   begin
     read (a[i,j]);
     if a[i,j]=1 then a[i,j]:=-1;
   end;
  readln(px,py);
  BFS(px,py);
  min:=maxint;
  for i:=1 to n do
  begin
    if a[i,1]>0 then
    begin
      writeln (a[i,1],' na koordinatama ',i,'.1');
      if a[i,1]<min then
      begin
        min:=a[i,1];
        mx:=i;
        my:=1;
      end;
    end;
  if a[i,m]>0 then
  begin
    writeln (a[i,m],' na koordinatama ',i,'.',m);
    if a[i,m]<min then
    begin
      min:=a[i,m];
      mx:=i;
      my:=m;
     end;
   end;
  end;
  for j:=1 to m do
  begin
    if a[1,j]>0 then
    begin
      writeln (a[1,j],' na koordinatama 1.',j);
      if a[1,j]<min then
      begin
        min:=a[1,j];
        mx:=1;
        my:=j;
      end;
    end;
    if a[n,j]>0 then
    begin
      writeln (a[n,j],' na koordinatama ',n,'.',j);
      if a[n,j]<min then
      begin
        min:=a[n,j];
        mx:=n;
        my:=j;
      end;
    end;
  end;
  if min=maxint then
  begin
    min:=0;
    mx:=px; mx:=py;
  end;
  if min<>-1 then writeln ('Najblizi izlaz je udaljen ',min,' i nalazi se na koor: ',mx,'.',my)
   else writeln('THERE IS NO ESCAPE!');
  for i:=1 to n do
  begin
    for j:=1 to m do
    write (a[i,j]:3);
    writeln;
  end;
end.
