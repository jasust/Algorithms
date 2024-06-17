program pas;
var x,y:array[1..100005] of longint;
    pr:array[1..100005] of integer;
    n,r,d,i:longint; ras,duz:extended; sol:int64;

begin
  read(n,R,d);
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    if ((x[i]>=0) and (y[i]>=0) and (y[i]-x[i]<R)) or ((x[i]>=0) and (y[i]<=0) and (x[i]+y[i]>=R)) then pr[i]:=1
    else if ((x[i]>=0) and (y[i]<=0) and (y[i]+x[i]<R)) or ((x[i]<=0) and (y[i]<=0) and (x[i]-y[i]>=R)) then pr[i]:=2
    else if ((x[i]<=0) and (y[i]<=0) and (x[i]-y[i]<R)) or ((x[i]<=0) and (y[i]>=0) and (x[i]+y[i]<=-R)) then pr[i]:=3
    else if ((x[i]<=0) and (y[i]>=0) and (x[i]+y[i]>-R)) or ((x[i]>=0) and (y[i]>=0) and (y[i]-x[i]>=R)) then pr[i]:=4;
  end;

  for i:=1 to n do
  begin
    if pr[i]=1 then
    begin
      duz:=d-R*sqrt(2);
      ras:=sqrt(sqr(x[i])+sqr(y[i]-R));
      while ras<=duz do begin inc(sol); duz:=duz-4*R*sqrt(2); end;
    end
    else if pr[i]=2 then
    begin
      duz:=d-R*2*sqrt(2);
      ras:=sqrt(sqr(y[i])+sqr(x[i]-R));
      while ras<=duz do begin inc(sol); duz:=duz-4*R*sqrt(2); end;
    end
    else if pr[i]=4 then
    begin
      duz:=d;
      ras:=sqrt(sqr(y[i])+sqr(x[i]+R));
      while ras<=duz do begin inc(sol); duz:=duz-4*R*sqrt(2); end;
    end
    else if pr[i]=3 then
    begin
      duz:=d-3*R*sqrt(2);
      ras:=sqrt(sqr(x[i])+sqr(y[i]+R));
      if (x[i]<=0) and (y[i]>=0) and (x[i]+y[i]<=-R) and (sqrt(sqr(x[i]+R)+sqr(y[i]))<=d) then inc(sol);
      while ras<=duz do begin inc(sol); duz:=duz-4*R*sqrt(2); end;
    end;
  end;
  writeln(sol);
end.
