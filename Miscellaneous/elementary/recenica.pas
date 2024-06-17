{4. Odrediti da li se recenica zavrsava sa lala ili pocinje sa miao.}
program p1;
var s,s1,s2:string[101];
    n,i,j:longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    s1:=copy(s,1,5);
    s2:=copy(s,length(s)-4,5);
    if (s1='miao.') and (s2<>'lala.') then writeln('Rainbow''s')
    else if (s1<>'miao.') and (s2='lala.') then writeln('Freda''s')
    else writeln('OMG>.< I don''t know!');
  end;
end.
