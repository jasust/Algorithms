program p1;
var n,m,x,mask:integer;
    d:array[0..100,0..100] of integer;

procedure calc(x,y,mask,next_mask:integer);
var my_mask:integer;
begin
  if y>=m then inc(d[x+1,next_mask],d[x,mask]) else
   begin
     my_mask:=1<<y;
     if (mask and my_mask)>0 then calc(x,y+1,mask,next_mask) else
     begin
       calc(x,y+1,mask,(next_mask or my_mask));
       if (y+1<m) and ((mask and my_mask)=0) and ((mask and (my_mask<<1))=0) then
        calc(x,y+2,mask,next_mask);
     end;
   end;
end;

begin
  read(n,m);
  d[0,0]:=1;
  for x:=0 to n-1 do
   for mask:=0 to (1<<m) do
    calc(x,0,mask,0);
  writeln(d[n,0]);
end.
