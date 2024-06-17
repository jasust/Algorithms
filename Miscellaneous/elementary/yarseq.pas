program yarseq;
var n,x,i,br,min,sum:longint;
begin
  readln(n); min:=1001;
  for i:=1 to 2*n-1 do
  begin
    read(x);
    if x<0 then
    begin
      x:=-x;
      inc(br);
    end;
    if x<min then min:=x;
    sum:=sum+x;
  end;
  if (br=0) or ((n mod 2=0) and (br mod 2=0)) or (n mod 2=1) then
   writeln(sum) else writeln(sum-2*min);
end.
