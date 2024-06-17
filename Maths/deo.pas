program deo;
var a,b:array[-10..100000] of integer;
    k,sol,n,i:longint; s:string[10];

procedure puta2;
var ost:integer;
begin
  ost:=0;
  for i:=1 to n do
  if b[i]<5 then
  begin
    b[i]:=2*b[i]+ost;
    ost:=0;
  end else
  begin
    b[i]:=b[i]*2-10+ost;
    ost:=1;
  end;
  if ost=1 then begin inc(n); b[n]:=1; end;
  inc(sol);
end;

function poklapanje:boolean;
var x:longint;
begin
  x:=0;
  for i:=k downto 1 do if a[i]=b[n-i+1] then inc(x);
  if (x=k) and (n>2*k) then poklapanje:=true else poklapanje:=false;
end;

begin
  sol:=6; n:=2;
  b[1]:=4; b[2]:=6;
  readln(s); k:=length(s);
  for i:=1 to k do val(s[i],a[i]);
  while not poklapanje do puta2;
  writeln(sol);
end.
