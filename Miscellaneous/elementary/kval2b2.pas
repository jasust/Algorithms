program p1;
var s:ansistring;
    n,q,i,a:longint; x:integer;
    ch,vaiste:char; k:boolean;
begin
  readln(n,q); readln(s);
  k:=true;
  for i:=1 to q do
  begin
    read(x);
    if x=1 then
    begin
      read(a,vaiste,ch);
      if k then s[a]:=ch else s[n-a+1]:=ch;
    end;
    if x=2 then k:=not(k);
    if x=3 then
    begin
      read(vaiste,ch);
      inc(n);
      if k then s:=s+ch else s:=ch+s;
    end;
  end;
  if not(k) then for i:=n downto 1 do write(s[i]) else write(s);
end.