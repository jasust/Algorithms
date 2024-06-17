program p3;
var n,m,i,l,h,poc,kra,mid,k,j:integer; raste:boolean;
    a:array[0..100005] of longint;
    b,c:array[0..100005] of integer;
begin
  readln(n,m); raste:=true;
  for i:=1 to n do
  begin
    read(a[i]);
    if raste and (a[i]<a[i-1]) then raste:=false;
    if not(raste) and (a[i]>a[i-1]) then begin inc(k); b[k]:=i-1; raste:=true; end;
  end;
  raste:=not raste; j:=k;
  for i:=n-1 downto 1 do
  begin
    if raste and (a[i]<a[i+1]) then raste:=false;
    if not(raste) and (a[i]>a[i+1]) then begin raste:=true; c[j]:=i+1; dec(j); end;
  end;
  for i:=1 to m do
  begin
    read(poc,kra);
    l:=1; h:=k;
    while l<=h do
    begin
      mid:=l + (h-l) shr 1;
      if (b[mid]<=kra-1) and (b[mid]>=poc+1) and (c[mid]>poc) then
        begin writeln('No'); break; end
      else if b[mid]>kra-1 then h:=mid-1
       else l:=mid+1;
    end;
    if l>h then writeln('Yes');
  end;
end.
