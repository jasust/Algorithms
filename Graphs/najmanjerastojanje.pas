{U datoteci je zadat broj gradova N. U sledecem redu su zadata dva grada
A i B. Ako su u svim ostalim redovima zadate veze izmedju gradova,
odrediti najkrace rastojanje izmedju gradova A i B i rekonstruisati put}
program p53;
var n,a,b,i,j,k,x,y,z:integer; ulaz,izlaz:text;
    c,put:array[0..100,0..100] of integer;

function vece(a,b:integer):boolean;
begin
  if (a= 0) then
  begin
   if (b>0) then vece:=true  else vece:=false;
  end
  else if (a>0) then
  begin
    if (b>0) and (a>b) then vece:=true else vece:=false;
  end;
end;

function zb(a,b:integer):integer;
begin
  if (a=0) or (b=0) then zb:=0 else zb:=a+b;
end;

begin
  assign(ulaz, 'ulaz.in');
  assign(izlaz, 'izlaz.out');
  reset(ulaz); rewrite(izlaz);
  readln(ulaz,n);
  readln(ulaz,a,b);
  while not(eof(ulaz)) do
  begin
    readln(ulaz,x,y,z);
    c[x,y]:= z;
    c[y,x]:= z;
  end;
  for k:=1 to n do
   for i:=1 to n do
    for j:=1 to n do
     if(i<>j) and (i<>k) and (k<>j) then
      if vece(c[i,j],zb(c[i,k],c[k,j])) then
      begin
        c[i,j]:=c[i,k]+c[k,j];
        put[i,j]:=k;
      end;
  writeln(izlaz,c[a,b]);
  while put[a,b]<>0 do
  begin
    write(izlaz,a,'->');
    a:=put[a,b];
  end;
  writeln(izlaz,a,'->',b);
  close(ulaz); close(izlaz);
end.
