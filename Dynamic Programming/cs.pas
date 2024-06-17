{Za niz sastavljen od slova ispisati koliko najmanje slova treba izbaciti da
 susedna slova budu razlicita}
program colorstripes;
var s:string;
    i,j,k,l,m,n,b:longint;
    c:char; ans:longint;

procedure two(s:string);
var n1,n2:longint;
begin
    n1:=0; n2:=0;
    for i:=1 to length(s) do
    if odd(i) then
    begin
      if s[i]='A' then inc(n2) else
      inc(n1);
    end else
    begin
      if s[i]='B' then inc(n2) else
      inc(n1);
    end;
    if n1<n2 then
    begin
      writeln(n1);
      for i:=1 to length(s) do
      if odd(i) then write('A') else write('B')
    end else
    begin
      writeln(n2);
      for i:=1 to length(s) do
      if not odd(i) then write('A') else write('B');
    end;
    writeln;
end;

begin
  readln(n,k);
  readln(s);
  if k=2 then two(s) else
  begin
    ans:=0;
    s:=s+'#';
    for i:=2 to n do
        if s[i]=s[i-1] then
        begin
            inc(ans);
            for c:='A' to 'Z' do
            if (c<>s[i-1]) and  (c<>s[i+1]) then
            begin
                s[i]:=c;
                break;
            end;
        end;
        writeln(ans);
        delete(s,n+1,1);
        writeln(s);
  end;
end.
