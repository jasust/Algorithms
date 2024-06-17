program p2;
var s:array[-200000..400001] of char;
    n,q,i,a,l,d:longint; x:integer;
    ch,vaiste:char; k:boolean;
begin
  readln(n,q); k:=true; l:=1; d:=n;
  for i:=1 to n do read(s[i]);
  for i:=1 to q do
  begin
    read(x);
    if x=2 then k:=not(k);
    if x=1 then
    begin
      read(a,vaiste,ch);
      if k then s[l+a-1]:=ch else s[d-a+1]:=ch;
    end;
    if x=3 then
    begin
      read(vaiste,ch);
      if k then begin inc(d); s[d]:=ch; end else begin dec(l); s[l]:=ch; end;
    end;
  end;
  if k then for i:=l to d do write(s[i])
   else for i:=d downto l do write(s[i]);
end.