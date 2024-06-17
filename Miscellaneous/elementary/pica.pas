{3.Naci put iz A i B tako da pokupite sve 1<D<=3, ne smete preci preko #}
Program D3;
var a:array [0..1000,0..1000] of longint;
    dx,dy:array [1..3] of longint;
    s:array [1..6] of longint;
    m,n,i,j,bd,px,py,kx,ky,min:longint;
    c,blank:char;

function BFS(x,y,z,q:longint):longint;
var t,u,tx,ty:longint;
    ls,b:array [0..1000,0..1000] of longint;
begin
  for i:=1 to m do fillchar(b[i],sizeof(b[i]),0);
  t:=1; u:=1;  ls[t,1]:=x; ls[t,2]:=y;
  while (t<=u) do
  begin
    tx:=ls[t,1]; ty:=ls[t,2];
    if (tx+1<n+1) and (a[tx+1,ty]<>-1) and ( ((b[tx+1,ty]=0) and not((tx+1=x) and (ty=y)) ) or (b[tx+1,ty]>b[tx,ty]+1)) then
     begin  inc(u); ls[u,1]:=tx+1; ls[u,2]:=ty; b[tx+1,ty]:=b[tx,ty]+1;  end;
    if (ty+1<m+1) and (a[tx,ty+1]<>-1) and (((b[tx,ty+1]=0) and not((tx=x) and (ty+1=y)) ) or (b[tx,ty+1]>b[tx,ty]+1)) then
     begin  inc(u); ls[u,1]:=tx; ls[u,2]:=ty+1; b[tx,ty+1]:=b[tx,ty]+1; end;
    if (tx-1>0) and (a[tx-1,ty]<>-1) and (((b[tx-1,ty]=0) and not((tx-1=x) and (ty=y)) ) or (b[tx-1,ty]>b[tx,ty]+1)) then
     begin  inc(u); ls[u,1]:=tx-1; ls[u,2]:=ty; b[tx-1,ty]:=b[tx,ty]+1; end;
    if (ty-1>0) and (a[tx,ty-1]<>-1) and (((b[tx,ty-1]=0) and not((tx=x) and (ty-1=y)) ) or (b[tx,ty-1]>b[tx,ty]+1)) then
     begin  inc(u); ls[u,1]:=tx; ls[u,2]:=ty-1; b[tx,ty-1]:=b[tx,ty]+1; end;
    inc (t);
  end;
  BFS:=b[z,q];
end;
begin
  readln (n,m);
  for i:=1 to n do
   for j:=1 to m do
   begin
     read (c,blank);
     if j=m then read(blank);
     if c='#' then a[i,j]:=-1
      else if c='A' then begin px:=i; py:=j; end
       else if c='B' then begin kx:=i; ky:=j; end
        else if c='D' then
        begin
          inc(bd);
          dx[bd]:=i;
          dy[bd]:=j;
        end;
   end;
case bd of
 1:writeln (BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky));
 2: begin
     s[1]:=BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],dx[2],dy[2])+BFS(dx[2],dy[2],kx,ky);
     s[2]:=BFS(px,py,dx[2],dy[2])+BFS(dx[2],dy[2],dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky);
     if s[1]<=s[2] then writeln(s[1])
      else  writeln(s[2]);
    end;
 3: begin
     s[1]:=BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],dx[2],dy[2])+BFS(dx[2],dy[2],dx[3],dy[3])+BFS(dx[3],dy[3],kx,ky);
     s[2]:=BFS(px,py,dx[1],dy[1])+BFS(dx[1],dy[1],dx[3],dy[3])+BFS(dx[3],dy[3],dx[2],dy[2])+BFS(dx[2],dy[2],kx,ky);
     s[3]:=BFS(px,py,dx[2],dy[2])+BFS(dx[2],dy[2],dx[1],dy[1])+BFS(dx[1],dy[1],dx[3],dy[3])+BFS(dx[3],dy[3],kx,ky);
     s[4]:=BFS(px,py,dx[2],dy[2])+BFS(dx[2],dy[2],dx[3],dy[3])+BFS(dx[3],dy[3],dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky);
     s[5]:=BFS(px,py,dx[3],dy[3])+BFS(dx[3],dy[3],dx[1],dy[1])+BFS(dx[1],dy[1],dx[2],dy[2])+BFS(dx[2],dy[2],kx,ky);
     s[6]:=BFS(px,py,dx[3],dy[3])+BFS(dx[3],dy[3],dx[2],dy[2])+BFS(dx[2],dy[2],dx[1],dy[1])+BFS(dx[1],dy[1],kx,ky);
     min:=s[1];
     for i:=2 to 6 do
      if s[i]<min then min:=s[i];
     writeln(min);
    end;
 end;
end.
