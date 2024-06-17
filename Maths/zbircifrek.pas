{Od zadatih n brojeva odrediti koji ima najveci zbir cifara preko rekurzije}
program p1;
var m,n,i,max,k,s:integer;

function zbr(n:integer):integer;
var j:integer;
begin
 if n=0 then zbr:=0
 else zbr:=n mod 10+zbr(n div 10);
end;

begin
  readln(m);
  max:=0;
  for i:=1 to m do
  begin
    read(n);
    k:=k+1;
    if zbr(n)>max then
    begin
      max:=zbr(n);
      s:=k;
    end;
  end;
  writeln(s,'-ti clan ima najveci zbir cifara koji je',max)
end.
