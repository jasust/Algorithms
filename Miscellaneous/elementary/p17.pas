{17)razlika dva stringa}
program p17;
var a,b,c:set of char;
    s:string; i:integer;
begin
  readln(s);
  for i:=1 to length(s) do a:=a+[s[i]];
  readln(s);
  for i:=1 to length(s) do b:=b+[s[i]];
  c:=a-b;
  for i:=1 to 255 do if chr(i) in c then write(chr(i));
end.