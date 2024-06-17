program p1;
type niz=array[1..1000] of longint;
var  a:niz; i,n:longint;

procedure heapsort(var a:niz);
var h,s,f,l:longint;
begin
  for i:=2 to n do
  begin
   h:=a[i]; s:=i; f:=s shr 1;
   while ((s>1) and (a[f]<h)) do
   begin
     a[s]:=a[f]; s:=f; f:=s shr 1;
   end;
   a[s]:=h;
 end;
 for i:=n downto 2 do
  begin
   l:=a[i]; a[i]:=a[1]; f:=1;
   if ((i-1>=3) and (a[3]>a[2]))
     then s:=3 else s:=2;
   while (s<=i-1) and (a[s]>l) do
     begin
     a[f]:=a[s]; f:=s; s:=2*f;
     if ((s+1<=i-1) and (a[s+1]>a[s]))
         then s:=s+1;
     end;
   a[f]:=l;
  end;
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  heapsort(a);
  for i:=1 to n do write(a[i],' ');
end.