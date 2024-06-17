program p1;
var a,b:ansistring; i,max,raz,j:longint; sl:integer;
    o:array[97..122] of longint;
begin
  readln(a);
  readln(b);
  for i:=1 to length(b) do
   if b[i]='?' then
     begin
       max:=0;
       fillchar(o,sizeof(o),0);
       for j:=i to length(a)-length(b)+i do inc(o[ord(a[j])]);
       for j:=97 to 122 do if o[j]>max then begin max:=o[j]; sl:=j; end;
       b[i]:=chr(sl);
       inc(raz,length(a)-length(b)+1-max);
     end else
     begin
       for j:=i to length(a)-length(b)+i do if b[i]<>a[j] then inc(raz);
     end;
  writeln(b); writeln(raz);
end.
