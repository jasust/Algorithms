{Data je matrica mxn.Naci put iz J u S tako da pokupite sve 1<D<=3,
tako da ne smete preci preko #}
Program D3;
var a:array [0..100,0..100] of integer;
    dx,dy:array [1..3] of integer;
    s:array [1..6] of integer;
    m,n,i,j,brpi,px,py,kx,ky,min:integer;
    c,space:char;

function BFS(x,y,z,q:integer):integer;
var u,t,tx,ty:longint;
    red,b:array [0..100,0..100] of integer;
begin
 for i:=1 to m do fillchar(b[i],sizeof(b[i]),0);
 t:=1; u:=1; red[t,1]:=x; red[t,2]:=y;
 while (t<=u) do
  begin
   tx:=red[t,1]; ty:=red[t,2];
   if (tx+1<n+1) and (a[tx+1,ty]<>-1) and (((b[tx+1,ty]=0) and not((tx+1=x) and (ty=y))) or (b[tx+1,ty]>b[tx,ty]+1)) then
     begin inc(u); red[u,1]:=tx+1; red[u,2]:=ty; b[tx+1,ty]:=b[tx,ty]+1; end;
   if (ty+1<m+1) and (a[tx,ty+1]<>-1) and (((b[tx,ty+1]=0) and not((tx=x) and (ty+1=y)) ) or (b[tx,ty+1]>b[tx,ty]+1)) then
     begin inc(u); red[u,1]:=tx; red[u,2]:=ty+1; b[tx,ty+1]:=b[tx,ty]+1; end;
   if (tx-1>0) and (a[tx-1,ty]<>-1) and (((b[tx-1,ty]=0) and not((tx-1=x) and (ty=y)) ) or (b[tx-1,ty]>b[tx,ty]+1)) then
     begin inc(u); red[u,1]:=tx-1; red[u,2]:=ty; b[tx-1,ty]:=b[tx,ty]+1; end;
   if (ty-1>0) and (a[tx,ty-1]<>-1) and (((b[tx,ty-1]=0) and not((tx=x) and (ty-1=y)) ) or (b[tx,ty-1]>b[tx,ty]+1)) then
     begin inc(u); red[u,1]:=tx; red[u,2]:=ty-1; b[tx,ty-1]:=b[tx,ty]+1; end;
   t:=t+1;
  end;
  BFS:=b[z,q];
end;

begin
  readln(n,m);
  for i:=1 to n do
   for j:=1 to m do
   begin
     read (c,space);
     if j=m then read(space);
     if c='#' then a[i,j]:=-1
     else if c='J' then begin px:=i; py:=j; end
     else if c='S' then begin kx:=i; ky:=j; end
     else if c='D' then
     begin
       inc(brpi);
       dx[brpi]:=i;
       dy[brpi]:=j;
       end;
   end;
 case brpi of
 1: writeln(BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky));
 2: begin
     s[1]:=BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],dx[2],dy[2])+BFS(dx[2],dy[2],kx,ky);
     s[2]:=BFS(px,py,dx[2],dy[2])+BFS(dx[2],dy[2],dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky);
     if s[1]<=s[2] then writeln(s[1]) else writeln(s[2]);
    end;
 3: begin
     s[1]:=BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],dx[2],dy[2])+BFS(dx[2],dy[2],dx[3],dy[3])+BFS(dx[3],dy[3],kx,ky);
     s[2]:=BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],dx[3],dy[3])+BFS(dx[3],dy[3],dx[2],dy[2])+BFS(dx[2],dy[2],kx,ky);
     s[3]:=BFS(px,py,dx[2],dy[2])+BFS(dx[2],dy[2],dx[1],dy[1])+BFS(dx[1],dy[1],dx[3],dy[3])+BFS(dx[3],dy[3],kx,ky);
     s[4]:=BFS(px,py,dx[2],dy[2])+BFS(dx[2],dy[2],dx[3],dy[3])+BFS(dx[3],dy[3],dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky);
     s[5]:=BFS(px,py,dx[3],dy[3])+BFS(dx[3],dy[3],dx[1],dy[1])+BFS(dx[1],dy[1],dx[2],dy[2])+BFS(dx[2],dy[2],kx,ky);
     s[6]:=BFS(px,py,dx[3],dy[3])+BFS(dx[3],dy[3],dx[2],dy[2])+BFS(dx[2],dy[2],dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky);
     min:=s[1];
     for i:=2 to 6 do if s[i]<min then min:=s[i];
     writeln(min);
    end;
 end;
end.