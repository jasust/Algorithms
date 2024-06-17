{21)odredi sve proste brojeve do 10^6 pomocu Eratostenovog sita}
program p21;
var s:array [2..1000000] of boolean;
    i,j,n:longint;
begin
  readln(n);
  fillchar(s,sizeof(s),false);
  for i:= 2 to n do
   if not s[i] then
   begin
     write(i,' ');
     j:=2*i;
     while j<=n do
     begin
       s[j]:=true;
       inc(j,i);
     end;
   end;
end.
