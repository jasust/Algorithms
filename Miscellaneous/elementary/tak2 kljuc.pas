program p2;
var a:array[1..2000,1..2000] of shortstring; i,j,k,t,n,m,s:integer; ul,iz:text;
p:shortstring; b,x:array[1..2000] of integer; c:array[1..2000] of string;
begin
  assign(ul,'kljuc.in');
  reset(ul);
  assign(iz,'kljuc.out');
  rewrite(iz);
  readln(ul,n,m);
  for i:=1 to n do readln(ul,c[i]);
  for i:=1 to n do for j:=1 to m do begin a[i,j]:=copy(c[i],1,1); delete(c[i],1,1); end;
  for i:=1 to m do b[i]:=i;
  for i:=1 to m-1 do
   for j:=i+1 to m do
   begin
     if a[1,j]>a[1,i] then
     begin
       for k:=1 to n do begin p:=a[k,i]; a[k,i]:=a[k,j]; a[k,j]:=p; end;
       t:=b[i]; b[i]:=b[j]; b[j]:=t;
     end;
     if a[1,j]=a[1,i] then for s:=2 to n do if a[s,j]<a[s,i] then break else if a[s,j]>a[s,i] then
     begin
       for k:=1 to n do begin p:=a[k,i]; a[k,i]:=a[k,j]; a[k,j]:=p; end;
       t:=b[i]; b[i]:=b[j]; b[j]:=t; break;
     end;
   end;
  for i:=1 to m do x[b[i]]:=i;
  for i:=1 to m do write(iz,x[i]);
  close(ul); close(iz);
end.
