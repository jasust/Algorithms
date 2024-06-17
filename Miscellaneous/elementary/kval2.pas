program p2;
var s:array[1..200001] of char;
    n,q,i,a:longint; x,k:integer; ch,vaiste:char;
begin
  read(n,q); readln(); k:=1;
  for i:=1 to n do read(s[i]);
  for i:=1 to q do
  begin
    read(x);
    if x=2 then k:=-k;
    if x=1 then
    begin
      read(a,vaiste,ch);
      if k=1 then s[a]:=ch else s[n-a+1]:=ch;
    end;
  end;
  if k=1 then for i:=1 to n do write(s[i])
   else for i:=n downto 1 do write(s[i]);
end.
