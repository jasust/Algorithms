{Na koliko nacina se m dama mogu rasporediti na tabli nxn tako da se ne napadaju}
program dame;
var rec:array[1..1000] of record p,d:longint; end;
    c,n,m,br,i:longint;
procedure dama;
var i,j,e,k:integer;
begin
  for i:=1 to n do
   for j:=1 to n do
   begin
     e:=0;
     for k:=1 to c do
     if (rec[k].p-rec[k].d<>i-j) and (rec[k].p+rec[k].d<>i+j) and
        (rec[k].p<>i) and (rec[k].d<>j) then inc(e);
     if e=c then
      if c=m-1 then inc(br) else
      begin
        inc(c);
        rec[c].p:=i;
        rec[c].d:=j;
        dama;
      end;
   end;
   dec(c);
end;
begin
  readln(n,m);
  dama;
  for i:=2 to m do br:=br div i;
  writeln(br);
end.
