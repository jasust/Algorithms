program turnir;
type niz=array[1..300000] of longint;
var a,b:niz;
    s:array[0..300000] of int64;
    n,k,pom,i,br:longint; sol:qword;

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
  readln(n); k:=1;
  for i:=1 to n do k:=k*2;
  for i:=1 to k do read(a[i]);
  n:=k; heapsort(a);
  for i:=1 to n do s[i]:=s[i-1]+a[i];
  while k>1 do
  begin
    sol:=sol+s[n]-s[pom];
    k:=k shr 1;
    pom:=pom+k;
  end;
  k:=n; br:=n;
  if n=1 then b[1]:=a[1] else
  begin
    br:=br shr 1;
    b[br]:=a[n]; b[br*2]:=a[n-1];
    n:=n-2;
    while br>1 do
    begin
      pom:=br shr 1;
      b[pom]:=a[n];
      dec(n); inc(pom,br);
      while pom<k do
      begin
        b[pom]:=a[n];
        dec(n);
        inc(pom,br);
      end;
      br:=br shr 1;
    end;
  end;
  writeln(sol);
  for i:=1 to k do write(b[i],' ');
end.
