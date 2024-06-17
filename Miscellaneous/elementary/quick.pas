program qui;
var a:array[1..1000] of longint;
n,i:longint;
procedure quick(d,g:longint);
var   i,j,p,mesto:longint;
   begin
     if d<g then
     begin
     i:=d;j:=g;mesto:=a[d];
     while (i<j) do
     begin
       while(a[i]<=mesto) and (i<j) do i:=i+1;
       while(a[j]>mesto) do j:=j-1;
         if(i<j) then
         begin
            p:=a[i];a[i]:=a[j];a[j]:=p;
         end;
     end;
        a[d]:=a[j];  a[j]:=mesto;
       if d<j-1 then quick(d,j-1);
       if j+1<g then quick(j+1,g);
     end;
   end;
begin
   read(n);
   for i:=1 to n do read(a[i]);
   quick(1,n);
   for i:=1 to n do write(a[i]:5);
end.