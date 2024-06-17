program ZPumpe;
var a:array [1..100,1..100] of longint;  p:array [1..100] of boolean;  bio:array [1..100] of boolean;
    n,m,k,i,x,y:integer;
    l,w,r,min:longint;
    t:boolean;
procedure DFS(st:integer;tr:longint);
var i:integer;
begin
 if st=n then
  begin
   t:=true;
   if tr<min then min:=tr;
  end
 else
  begin
   bio[st]:=true;
   if p[st] then r:=l;
   for i:=1 to n do
    if (a[st,i]<>0) and (a[st,i]<=r) and (not(bio[i])) then
     begin
      r:=r-a[st,i];
      DFS(i,tr+a[st,i]);
     end;
   bio[st]:=false;
  end;
end;

begin
 readln(n,m,l,k);
 for i:=1 to k do
  begin
   readln(x,y,w);
   a[x,y]:=w; a[y,x]:=w;
  end;
 for i:=1 to m do
  begin
   readln(x);p[x]:=true;
  end;
 min:=2147483647; r:=l;
 DFS(1,0);
 if t then writeln(min)
 else writeln(-1);
end.
