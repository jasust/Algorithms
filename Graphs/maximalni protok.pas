program maxprotok;
var cap:array[1..100,1..100] of integer;
    bio:array[1..100] of boolean;
    put:array[1..100] of integer;
    n,i,j,min,res,d:integer;
    prom,stop:boolean;

procedure obidji(s,r:integer);
var j:integer;
begin
  bio[s]:=true; put[r]:=s;
  if s=n then
  begin
    d:=r;
    stop:=true;
  end else
  begin
    for j:=1 to n do
     if (cap[s,j]>0) and not(bio[j]) then
     begin
       obidji(j,r+1);
       if stop then break;
     end;
  end;
end;

procedure protok;
var i,j:integer;
begin
  res:=0;
  repeat
   prom:=false; stop:=false; min:=0;
   fillchar(bio,sizeof(bio),false);
   obidji(1,1);
   prom:=stop;
   if prom then
   begin
     min:=maxint;
     for i:=1 to d-1 do
      if min>cap[put[i],put[i+1]] then min:=cap[put[i],put[i+1]];
     for i:=1 to d-1 do
     begin
       dec(cap[put[i],put[i+1]],min);
       inc(cap[put[i+1],put[i]],min);
     end;
     inc(res,min);
   end;
  until not prom;
end;

begin
  readln(n);
  for i:=1 to n do
   for j:=1 to n do read(cap[i,j]);
  protok;
  writeln(res);
end.
