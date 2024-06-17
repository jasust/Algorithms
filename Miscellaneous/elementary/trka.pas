program p1;
var a:array[1..127,1..127] of real;
    v:array[1..127] of real;
    t:array[0..126] of longint;
    n,p,q,r,i,j,sol:integer; l,d:real;

begin
  readln(n,p,q,r);
  t[0]:=3600*p+60*q+r;
  for i:=1 to n do
  begin
    readln(v[i],p,q,r);
    t[i]:=3600*p+60*q+r;
  end;
  for i:=1 to n do
   for j:=1 to n do
   begin
     if v[i]=v[j] then a[i,j]:=0
      else a[i,j]:=(t[i]*v[i]-t[j]*v[j])/(v[i]-v[j]);
   end;
   for i:=1 to n do
   begin
     l:=t[i]; d:=t[0]; p:=0;
     for j:=1 to n do
     begin
       if (a[i,j]<=t[i]) and ((t[i]>t[j]) or (v[i]<v[j])) then break;
       if (a[i,j]>t[i]) and (a[i,j]>t[0]) and (t[j]<t[i]) then break;
       if (a[i,j]>t[i]) and (a[i,j]<=t[0]) and (t[i]<t[j]) and (a[i,j]<d) then d:=a[i,j];
       if (a[i,j]>t[i]) and (a[i,j]<=t[0]) and (t[i]>t[j]) and (a[i,j]>l) then l:=a[i,j];
       inc(p);
     end;
     if (p=n) and (l<=d) then inc(sol);
   end;
   writeln(sol);
end.
