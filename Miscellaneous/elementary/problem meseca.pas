program pm;
var n,i:longint; s:string[11];
    br,j,duz,k:integer; p:int64;

function faktorijel(a:integer):longint;
var i:integer; f:longint;
begin
  if a=0 then f:=0 else f:=1;
  for i:=2 to a do f:=f*i;
  faktorijel:=f;
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s); duz:=length(s);
    for j:=1 to duz-1 do
    begin
      br:=0;
      for k:=j+1 to duz do if s[k]<s[j] then inc(br);
      p:=p+faktorijel(duz-j)*br;
    end;
    inc(p);
  end;
  p:=(((n+2)*(n+1)) div 2)-p;
  writeln(p);
end.