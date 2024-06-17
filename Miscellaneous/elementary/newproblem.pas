program newprob;
var n,j,i,k:integer;
    a:array[1..100000] of boolean;
    s:string;
begin
  readln(n);
  fillchar(a,sizeof(a),false);
  for i:=1 to n do
  begin
    readln(s);
    for j:=1 to length(s) do a[ord(s[j])-96]:=true;
    for j:=1 to length(s)-1 do a[ord(s[j+1])+100*ord(s[j])-9696]:=true;
  end;
  k:=1;
  while a[k] do if (k mod 100<26) then inc(k) else  k:=k+75;
  if k<30 then writeln(chr(k+96))
   else writeln(chr((k div 100)+96),chr((k mod 100)+96));
end.
