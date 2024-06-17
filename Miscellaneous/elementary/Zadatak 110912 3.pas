{3.Za matricu nxn odredi sve puteve sa:
     1)Tacno jednim presedanjem
     2)Tacno k presedanja
     3)Najvise k presedanja
     4)Sve puteve koji postoje}
Program p3;
var n,i,j,s,l,k,x:integer;
a,b,c,max:array[1..100,1..100] of integer;

procedure puta;
begin
  for i:=1 to n do
   for j:=1 to n do begin c[i,j]:=b[i,j]; b[i,j]:=0; end;
  for i:=1 to n do
   for j:=1 to n do
    for s:=1 to n do inc(b[i,j],c[i,s]*a[s,j]);
end;

procedure kvadrat;
begin
  for i:=1 to n do
   for j:=1 to n do
   begin c[i,j]:=b[i,j]; b[i,j]:=0; end;
  for i:=1 to n do
   for j:=1 to n do
    for s:=1 to n do
   inc(b[i,j],c[i,s]*c[s,j]);
end;

procedure step(x:longint);
begin
  if x>1 then
   if x mod 2=0 then begin step(x div 2); kvadrat; end
   else begin step(x div 2); kvadrat; puta;
  end;
end;

procedure rb;
begin
for i:=1 to n do
 for j:=1 to n do b[i,j]:=a[i,j];
end;

procedure rmax;
begin
for i:=1 to n do
 for j:=1 to n do max[i,j]:=0;
end;

begin
  readln (n);
  for i:=1 to n do
   for j:=1 to n do
   begin read(a[i,j]); b[i,j]:=a[i,j]; end;
  readln(k);
  writeln('Sa 1 presedanjem: ');
  step(2);
  for i:=1 to n do
  begin for j:=1 to n do write(b[i,j],' '); writeln; end;
  writeln; rb;
  writeln('Sa tacno k presedanja: ');
  step(k+1);
  for i:=1 to n do
  begin for j:=1 to n do write(b[i,j],' '); writeln; end;
  writeln; rb;
  writeln('Sa najvise k presedanja: ');
  for L:=1 to k+1 do
  begin
    step(L);
    for i:=1 to n do
     for j:=1 to n do inc(max[i,j],b[i,j]);
    rb;
  end;
  for i:=1 to n do
  begin for j:=1 to n do write(max[i,j],' '); writeln; end;
  writeln; rb; rmax;
  writeln('Sve puteve: ');
  for L:=1 to n-1 do
  begin
    step(L);
    for i:=1 to n do
     for j:=1 to n do inc(max[i,j],b[i,j]);
    rb;
  end;
  for i:=1 to n do begin
  for j:=1 to n do write(max[i,j],' '); writeln; end;
end.