 {Primov algoritam reda n^2}

Program PrimovAlgoritam;
var a:array [-2..1000,-2..1000] of longint;
o:array [-2..1000] of boolean;
t,r:array [-2..1000] of longint;
n,i,j,z,minpos,min:longint;

begin
readln(n);
for i:=1 to n do
 for j:=1 to n do
  begin
   read(a[i,j]);
   if i=1 then r[j]:=a[i,j];
  end;

o[1]:=true; r[1]:=0; t[1]:=-1;

for j:=1 to n-1 do
 begin
  minpos:=0; min:=0;

  for i:=1 to n do
   if not o[i] and (r[i]>0) and ((minpos=0) or (min>r[i])) then
    begin
     min:=r[i]; minpos:=i;
    end;
  o[minpos]:=true;

  for i:=1 to n do
   if not o[i] and (a[minpos,i]>0) and ((r[i]=0) or (r[i]>a[minpos,i])) then
    begin
     r[i]:=a[minpos,i]; t[i]:=minpos;
    end;

 end;

 for i:=1 to n do
  begin
   inc(z,r[i]);
   if t[i]=0 then t[i]:=1;
   if t[i]=-1 then t[i]:=0;
   writeln(t[i],'-',i);
  end;
 writeln(z); 
end.