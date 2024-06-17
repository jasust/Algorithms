program p1;
var o:array[97..122] of longint;
    la,lb,i,max:longint; raz:qword;
    a,b:ansistring; j:integer;
begin
  readln(a); readln(b);
  la:=length(a); lb:=length(b);
  for i:=1 to la-lb do inc(o[ord(a[i])]);
  for i:=1 to lb do
  begin
    inc(o[ord(a[i+la-lb])]);
    if b[i]='?' then
    begin
      max:=-1;
      for j:=97 to 122 do
       if o[j]>max then
       begin
         max:=o[j];
         b[i]:=chr(j);
       end;
       raz:=raz+la-lb+1-max;
    end else raz:=raz+la-lb+1-o[ord(b[i])];
    dec(o[ord(a[i])]);
  end;
  writeln(b);
  writeln(raz);
end.
