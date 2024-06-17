{25)broj cifara i znakova +,-,* u datom stringu koji ima do 80 karaktera}
program p25;
var a:set of char;
    s:string; i,k:integer;
begin
  readln(s); a:=[chr(42),chr(43),chr(45),chr(240)];
  for i:=48 to 57 do a:=a+[chr(i)];
  for i:=1 to length(s) do if s[i] in a then k:=k+1;
  writeln(k);
end.