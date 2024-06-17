program ABCcoci;
var a,b,c,p,i:integer; s:string;
begin
  readln(a,b,c);
  readln(s);
  if a>b then begin p:=a; a:=b; b:=p; end;
  if a>c then begin p:=a; a:=c; c:=p; end;
  if b>c then begin p:=c; c:=b; b:=p; end;
  for i:=1 to 3 do
   if s[i]='A' then write(a,' ')
    else if s[i]='B' then write(b,' ')
     else write(c,' ');
end.