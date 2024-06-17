{5.Zadat je niz longintova duzine n<=10^5. Postoji q<=10^5 upita, dva tipa:
 1-za zadate l i r odrediti sumu clanova niza od l-tog do r-tog(i njih ukljucujemo)
 2-za zadate l i r zameniti clanove niza sa njihovim trecim stepenom
 Posto je broj moze biti jako veliki, ispisati ga po modulu 95542721.}
program p5;
const md=95542721;
var f:array [0..400333,0..48] of longint;
    ost,shift:array [0..400333] of longint;
    n,m,i,j,l,r,t,sz:longint; x,y:int64;
    next:array [0..123] of longint;
    a:array [0..100333] of longint;

procedure recount(v:longint);
var s1,s2,j:longint;
begin
  if v>=sz then exit;
  s1:=shift[2*v];
  s2:=shift[2*v+1];
  for j:=0 to 47 do f[v,ost[j-s1+48]]:=f[2*v,j];
  for j:=0 to 47 do
  begin
    inc(f[v,ost[j-s2+48]],f[2*v+1,j]);
    if f[v,ost[j-s2+48]]>=md then dec(f[v,ost[j-s2+48]],md);
  end;
end;

procedure upd(v,ll,rr,l,r:longint);
var c:longint;
begin
  if (ll>r) or (l>rr) then exit;
  if (l<=ll) and (r>=rr) then
  begin
    shift[v]:=ost[shift[v]+1];
    exit;
  end;
  c:=(ll+rr) shr 1;
  upd(2*v,ll,c,l,r);
  upd(2*v+1,c+1,rr,l,r);
  recount(v);
end;

function get(v,ll,rr,l,r,nshift:longint):longint;
var c:longint;
begin
  if (ll>r) or (l>rr) then exit(0);
  nshift:=ost[nshift+shift[v]];
  if (l<=ll) and (r>=rr) then exit(f[v,nshift]);
  c:=(ll+rr) shr 1;
  c:=get(2*v,ll,c,l,r,nshift)+get(2*v+1,c+1,rr,l,r,nshift);
  if c>=md then c:=c-md;
  get:=c;
end;

begin
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    a[i]:=a[i] mod md;
  end;
  sz:=1;
  while sz<n do sz:=2*sz;
  for i:=0 to 400000 do ost[i]:=i mod 48;
  for j:=0 to 47 do next[j]:=j+1;
  next[47]:=0;
  for i:=1 to n do
  begin
    x:=a[i];
    for j:=0 to 47 do
    begin
      f[i+sz-1,j]:=x;
      y:=x;
      x:=x*x mod md;
      x:=x*y mod md;
    end;
  end;
  for i:=sz-1 downto 1 do
  begin
    for j:=0 to 47 do
    begin
      f[i,j]:=f[2*i,j]+f[2*i+1,j];
      if f[i,j]>=md then f[i,j]:=f[i,j]-md;
    end;
  end;
  read(m);
  for i:=1 to m do
  begin
    read(t,l,r);
    if t=1 then Writeln(get(1,1,sz,l,r,0)) else upd(1,1,sz,l,r);
  end;
end.
