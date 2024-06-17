program p2;
var n,t,i,l,h,mid,max:longint;
    a:array[0..100005] of longint;
begin
  readln(n,t);
  for i:=1 to n do begin read(a[i]); a[i]:=a[i]+a[i-1]; end;
  for i:=1 to n do
  begin
    l:=i; h:=n;
    while l<=h do
    begin
      mid:=l + (h-l) shr 1;
      if a[mid]-a[i-1]=t then begin if mid-i+1>max then max:=mid-i+1; break; end;
      if a[mid]-a[i-1]<t then l:=mid+1
       else h:=mid-1;
    end;
    if (h-i+1>max) and (a[h]-a[i-1]<t) then max:=h-i+1;
  end;
  writeln(max);
end.


