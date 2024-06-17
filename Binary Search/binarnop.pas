program bp;
var a:array [1..1000] of longint;
    i,n,h,s,f,l,value,left,right,mid:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=2 to n do
  begin
    h:=a[i]; s:=i;f:=s div 2;
    while ((s>1) and (a[f]<h)) do
    begin
      a[s]:=a[f]; s:=f; f:=s div 2;
    end;
    a[s]:=h;
  end;
  for i:=n downto 2 do
  begin
    l:=a[i]; a[i]:=a[1]; f:=1;
    if ((i-1>=3) and (a[3]>a[2])) then s:=3 else s:=2;
    while (s<=i-1) and (a[s]>l) do
    begin
      a[f]:=a[s]; f:=s; s:=2*f;
      if ((s+1<=i-1) and (a[s+1]>a[s])) then s:=s+1;
    end;
    a[f]:=l;
  end;
  readln(value); left:=1; right:=n;
  while left<=right do
  begin
    mid:=(right-left) div 2+left;
    if a[mid]=value then begin writeln(mid); break; end else
    if value<a[mid] then right:=mid-1 else left:=mid+1;
  end;
end.
