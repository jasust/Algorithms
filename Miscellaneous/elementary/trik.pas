program trik;
var s:string; sol,i:byte;
begin
  readln(s);  sol:=1;
  for i:=1 to length(s) do
  begin
    if (sol=1) and (s[i]='A') then sol:=2
    else if (sol=1) and (s[i]='C') then sol:=3
    else if (sol=2) and (s[i]='A') then sol:=1
    else if (sol=2) and (s[i]='B') then sol:=3
    else if (sol=3) and (s[i]='B') then sol:=2
    else if (sol=3) and (s[i]='C') then sol:=1;
  end;
  write(sol);
end.
