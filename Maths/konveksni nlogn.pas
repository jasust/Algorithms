program konveksni;
type niz=array[0..1022] of longint;
var x,y,o:niz; i,n,br:longint;
    q,p:array[0..1022] of boolean;

function levoskr(a,b,c:longint):boolean;
begin
  if ((x[b]-x[a])*(y[c]-y[a])-(y[b]-y[a])*(x[c]-x[a])>=0) then levoskr:=true else levoskr:=false;
end;

function desnoskr(a,b,c:longint):boolean;
begin
  if ((x[b]-x[a])*(y[c]-y[a])-(y[b]-y[a])*(x[c]-x[a])<=0) then desnoskr:=true else desnoskr:=false;
end;

procedure heapsort(var a:niz);
var h1,h2,s,f,l:longint;
begin
  for i:=2 to n do
  begin
   h1:=a[i]; h2:=y[i]; s:=i; f:=s shr 1;
   while ((s>1) and (a[f]<h1)) do
   begin
     a[s]:=a[f]; y[s]:=y[f]; s:=f; f:=s shr 1;
   end;
   a[s]:=h1; y[s]:=h2;
 end;
 for i:=n downto 2 do
  begin
   h1:=a[i]; h2:=y[i]; a[i]:=a[1]; y[i]:=y[1]; f:=1;
   if ((i-1>=3) and (a[3]>a[2]))
     then s:=3 else s:=2;
   while (s<=i-1) and (a[s]>h1) do
     begin
     a[f]:=a[s]; y[f]:=y[s]; f:=s; s:=2*f;
     if ((s+1<=i-1) and (a[s+1]>a[s]))
         then s:=s+1;
     end;
   a[f]:=h1; y[f]:=h2;
  end;
end;

begin
  readln(n);
  for i:=1 to n do read(x[i],y[i]);
  heapsort(x); fillchar(o,sizeof(o),0);

  o[1]:=1; o[2]:=2; br:=2;
  q[1]:=true; q[2]:=true;
  for i:=3 to n do
  begin
    while (not levoskr(o[br-1],o[br],i)) and (br>1) do
    begin
      q[o[br]]:=false;
      o[br]:=0;
      dec(br);
    end;
    inc(br);
    o[br]:=i;
    q[o[br]]:=true;
  end;

  o[2]:=2; br:=2; p[2]:=true; p[1]:=true;
  for i:=3 to n do
  begin
    while (not desnoskr(o[br-1],o[br],i)) and (br>1) do
    begin
      p[br]:=false;
      o[br]:=0;
      dec(br);
    end;
    inc(br);
    o[br]:=i;
    p[o[br]]:=true;
  end;

  writeln;
  for i:=1 to n do if q[i] or p[i] then write(i,' ');
end.