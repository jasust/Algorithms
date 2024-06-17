{Odrediti kojim putem treba ici da bi ukupno rastojanje bilo minimalno}
program p1;
var a:array[0..100,0..100] of longint;
    o:array[1..100] of boolean;
    f,g:text; n,x,y,z,i,j,k,min:longint;
    t:array[1..100] of record u,iz:integer; end;
begin
  assign(f,'ulaz.in');
  assign(g,'izlaz.out');
  reset(f); rewrite(g);
  fillchar(o,sizeof(o),false);
  readln(f,n);
  while not(eof(f)) do
  begin
    readln(f,x,y,z);
    a[x,y]:=z;
    a[y,x]:=z;
  end;
  for i:=1 to n do
   for j:=1 to n do if a[i,j]=0 then a[i,j]:=maxint;
  k:=1; o[1]:=true;
  while k<=n-1 do
  begin
    min:=maxint;
    for i:=1 to n do
      for j:=1 to n do
        if (not(o[j])) and (o[i]) and (a[i,j]<=min) then
           begin
             min:=a[i,j]; t[k].iz:=i; t[k].u:=j;
           end;
    o[t[k].u]:=true;
    inc(k);
  end;
  for i:=1 to n do
   for j:=1 to n do if a[i,j]=maxint then a[i,j]:=-1;
  for i:=1 to k-1 do writeln(g,t[i].iz,'-',t[i].u,',',a[t[i].iz,t[i].u]);
  close(f); close(g);
end.
