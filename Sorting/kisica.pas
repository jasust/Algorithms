program p1;
var n,i,j,k,s,max,maxx:integer;
    x1,x2,y1,y2,m,w,kor,z:array[1..100] of integer;
procedure zam(var a,b:integer);
var p:integer;
begin p:=a; a:=b; b:=p; end;

begin
  readln(n); s:=1;
  for i:=1 to n do
  begin
    read(x1[i],y1[i],x2[i],y2[i]);
    if y1[i]>y2[i] then begin zam(y1[i],y2[i]); zam(x1[i],x2[i]); end;
     if x1[i]<x2[i] then z[i]:=1 else z[i]:=-1;
    if x1[i]>maxx then maxx:=x1[i]; if x2[i]>maxx then maxx:=x2[i];
  end;
  for i:=1 to n-1 do
   for j:=i+1 to n do
   begin
     if (z[i]=z[j]) and (z[i]=-1) then
     begin
       if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))*((y2[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x2[i]-x1[j]))>0 then
       begin
         if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))<0 then
         begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end;
       end else if (y1[j]-y1[i])*(x2[i]-x1[i])-(y2[i]-y1[i])*(x1[j]-x1[i])>0 then
       begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end;
     end else if (z[i]=z[j]) and (z[i]=1) then
     begin
       if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))*((y2[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x2[i]-x1[j]))>0 then
       begin
         if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))>0 then
         begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end;
       end else if (y1[j]-y1[i])*(x2[i]-x1[i])-(y2[i]-y1[i])*(x1[j]-x1[i])<0 then
       begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end;
     end;
     if z[i]*z[j]=-1 then
     begin
      if z[i]=1 then if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))*((y2[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x2[i]-x1[j]))>=0 then
      if (y1[j]-y1[i])*(x2[i]-x1[i])-(y2[i]-y1[i])*(x1[j]-x1[i])<0 then begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end
      else if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))>=0 then begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end;
      if z[i]=-1 then if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))*((y2[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x2[i]-x1[j]))>=0 then
      if (y1[j]-y1[i])*(x2[i]-x1[i])-(y2[i]-y1[i])*(x1[j]-x1[i])>0 then begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end
      else if ((y1[i]-y1[j])*(x2[j]-x1[j])-(y2[j]-y1[j])*(x1[i]-x1[j]))<=0 then begin zam(y1[i],y1[j]); zam(x1[i],x1[j]); zam(y2[i],y2[j]); zam(x2[i],x2[j]); zam(z[i],z[j]); end;
    end;
   end;
  for i:=n downto 1 do
  begin
    k:=0; if z[i]=1 then begin for j:=x1[i] to x2[i] do begin k:=k+m[j]; m[j]:=-1; end; w[i]:=x2[i]-x1[i]+k+1; m[x1[i]]:=w[i]-1; end
    else begin for j:=x2[i] to x1[i] do begin k:=k+m[j]; m[j]:=-1; end; w[i]:=x1[i]-x2[i]+1+k; m[x1[i]]:=w[i]-1; end;
  end;
  for i:=1 to n do write(w[i],' ');
  for i:=1 to maxx do if m[i]>max then max:=m[i]; writeln;
  write(max+1,' - u tackama:'); for i:=1 to maxx do if m[i]=max then write(' ',i);
end.
