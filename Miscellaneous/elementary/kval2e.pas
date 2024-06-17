program p1;
var n,m,i,j,sol:integer; nasao:boolean;
    a:array[-1..1022,-1..1022] of char;
    b:array[-1..1022,-1..1022] of integer;
    c:array[0..1022] of record idx,idy:integer; end;

procedure proveri(x,y,kraj:integer);
begin
  if ((abs(b[x-2,y-2]-kraj)=1) or (abs(b[x-1,y-2]-kraj)=1) or (abs(b[x-2,y-1]-kraj)=1) or (abs(b[x-2,y]-kraj)=1) or (abs(b[x,y-2]-kraj)=1)) and (a[x-1,y-1]='.') and (b[x-1,y-1]=0) then
   begin inc(sol); c[sol].idx:=x-1; c[sol].idy:=y-1; b[x-1,y-1]:=6; end;
  if ((abs(b[x-2,y+2]-kraj)=1) or (abs(b[x-1,y+2]-kraj)=1) or (abs(b[x-2,y+1]-kraj)=1) or (abs(b[x-2,y]-kraj)=1) or (abs(b[x,y+2]-kraj)=1)) and (a[x-1,y+1]='.') and (b[x-1,y+1]=0) then
   begin inc(sol); c[sol].idx:=x-1; c[sol].idy:=y+1; b[x-1,y+1]:=6; end;
  if ((abs(b[x+2,y-2]-kraj)=1) or (abs(b[x+1,y-2]-kraj)=1) or (abs(b[x+2,y-1]-kraj)=1) or (abs(b[x+2,y]-kraj)=1) or (abs(b[x,y-2]-kraj)=1)) and (a[x+1,y-1]='.') and (b[x+1,y-1]=0) then
   begin inc(sol); c[sol].idx:=x+1; c[sol].idy:=y-1; b[x+1,y-1]:=6; end;
  if ((abs(b[x+2,y+2]-kraj)=1) or (abs(b[x+1,y+2]-kraj)=1) or (abs(b[x+2,y+1]-kraj)=1) or (abs(b[x+2,y]-kraj)=1) or (abs(b[x,y+2]-kraj)=1)) and (a[x+1,y+1]='.') and (b[x+1,y+1]=0) then
   begin inc(sol); c[sol].idx:=x+1; c[sol].idy:=y+1; b[x+1,y+1]:=6; end;
  if ((abs(b[x,y-2]-kraj)=1) or (abs(b[x-1,y-2]-kraj)=1) or (abs(b[x+1,y-2]-kraj)=1)) and (a[x,y-1]='.') and (b[x,y-1]=0) then
   begin inc(sol); c[sol].idx:=x; c[sol].idy:=y-1; b[x,y-1]:=6; end;
  if ((abs(b[x,y+2]-kraj)=1) or (abs(b[x-1,y+2]-kraj)=1) or (abs(b[x+1,y+2]-kraj)=1)) and (a[x,y+1]='.') and (b[x,y+1]=0) then
   begin inc(sol); c[sol].idx:=x; c[sol].idy:=y+1; b[x,y+1]:=6; end;
  if ((abs(b[x-2,y]-kraj)=1) or (abs(b[x-2,y-1]-kraj)=1) or (abs(b[x-2,y+1]-kraj)=1)) and (a[x-1,y]='.') and (b[x-1,y]=0) then
   begin inc(sol); c[sol].idx:=x-1; c[sol].idy:=y; b[x-1,y]:=6; end;
  if ((abs(b[x+2,y]-kraj)=1) or (abs(b[x+2,y-1]-kraj)=1) or (abs(b[x+2,y+1]-kraj)=1)) and (a[x+1,y]='.') and (b[x+1,y]=0) then
   begin inc(sol); c[sol].idx:=x+1; c[sol].idy:=y; b[x+1,y]:=6; end;
end;

procedure dfs(x,y,kraj:integer);
begin
  b[x,y]:=kraj;
  if (b[x,y-1]=kraj-1) or (b[x+1,y]=kraj-1) then nasao:=true;
  proveri(x,y,kraj);
  if (a[x-1,y-1]='#') and (b[x-1,y-1]=0) then dfs(x-1,y-1,kraj);
  if (a[x,y-1]='#') and (b[x,y-1]=0) then dfs(x,y-1,kraj);
  if (a[x+1,y-1]='#') and (b[x+1,y-1]=0) then dfs(x+1,y-1,kraj);
  if (a[x-1,y]='#') and (b[x-1,y]=0) then dfs(x-1,y,kraj);
  if (a[x-1,y+1]='#') and (b[x-1,y+1]=0) then dfs(x-1,y+1,kraj);
  if (a[x,y+1]='#') and (b[x,y+1]=0) then dfs(x,y+1,kraj);
  if (a[x+1,y]='#') and (b[x+1,y]=0) then dfs(x+1,y,kraj);
  if (a[x+1,y+1]='#') and (b[x+1,y+1]=0) then dfs(x+1,y+1,kraj);
end;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;

  fillchar(b,sizeof(b),0);
  for i:=0 to n+1 do begin b[i,0]:=2; b[i,m+1]:=3; end;
  for i:=0 to m+1 do begin b[n+1,i]:=2; b[0,i]:=3; end;
  b[0,0]:=0; b[n+1,m+1]:=0; a[1,1]:=','; a[n,m]:=',';

  for i:=2 to m do if (a[1,i]='#') and (b[1,i]=0) and not(nasao) then dfs(1,i,3);
  for i:=1 to n-1 do if (a[i,m]='#') and (b[i,m]=0) and not(nasao) then dfs(i,m,3);
  for i:=2 to n do if (a[i,1]='#') and (b[i,1]=0) and not(nasao) then dfs(i,1,2);
  for i:=1 to m-1 do if (a[n,i]='#') and (b[n,i]=0) and not(nasao) then dfs(n,i,2);

  if nasao then
   begin
     sol:=0;
     for i:=1 to n do
      for j:=1 to m do
       if a[i,j]='.' then begin inc(sol); c[sol].idx:=i; c[sol].idy:=j; end;
   end else
   if n=1 then for i:=2 to m-1 do begin inc(sol); c[sol].idx:=1; c[sol].idy:=i; end
    else if m=1 then for i:=2 to n-1 do begin inc(sol); c[sol].idx:=i; c[sol].idy:=1; end;

   writeln(sol);
   for i:=1 to sol do writeln(c[i].idx,' ',c[i].idy);
end.
