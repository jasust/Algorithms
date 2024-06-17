{Zadata je matrica nxm od 0 i 1 i pocetne koordinate coveka koji se krece po 0-ma.
Odrediti koliko ima izlaza, njihove koordinate i udaljenost najblizeg izlaza}
program p2;
var s,i,j,n,m,x,y,min:integer;
    o:array[0..50,0..50] of boolean;
    a:array[0..50,0..50] of integer;
    b:array[0..100] of integer;

procedure pored(q,w:integer);
begin
  o[q,w]:=true;
  if (q=1) or (w=1) or (q=n) or  (w=m) then begin s:=s+1; b[(s-1)*3+1]:=a[q,w]-1; b[(s-1)*3+2]:=q; b[s*3]:=w; end;
  if (a[q,w+1]>0) and not (o[q,w+1]) then begin inc(a[q,w+1],a[q,w]); pored(q,w+1); end;
  if (a[q+1,w]>0) and not (o[q+1,w]) then begin inc(a[q+1,w],a[q,w]); pored(q+1,w); end;
  if (a[q,w-1]>0) and not (o[q,w-1]) then begin inc(a[q,w-1],a[q,w]); pored(q,w-1); end;
  if (a[q-1,w]>0) and not (o[q-1,w]) then begin inc(a[q-1,w],a[q,w]); pored(q-1,w); end;
end;

begin
  readln(n,m); min:=maxint;
  for i:=1 to n do
   for j:=1 to m do begin read(a[i,j]); if a[i,j]=1 then a[i,j]:=0 else a[i,j]:=1; end;
  readln(x,y); pored(x,y);
  writeln('Ima ',s,' izlaza na koordinatama: ');
  for i:=0 to s-1 do write('(',b[i*3+2],',',b[i*3+3],') ');
  for i:=0 to s-1 do if b[i*3+1]<min then min:=b[i*3+1];
  writeln('Najblizi izlaz je na udaljenosti: ',min);
end.