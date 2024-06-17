{2.Stepenuj matricu nxn na k-ti stepen (A^n = A za n=1;(A^k^)2 za n=2k;A*(A^k)^2 za n=2k+1}
Program Z2;
var n,i,j,s,l,k,x:longint;
    a,b,c:array[1..100,1..100] of integer;

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

begin
  readln(n);
  for i:=1 to n do
   for j:=1 to n do
   begin read(a[i,j]); b[i,j]:=a[i,j]; end;
  readln(k); step(k);
  for i:=1 to n do
  begin for j:=1 to n do write(b[i,j],' '); writeln; end;
end.