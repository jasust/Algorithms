{Odrediti zbir brojeva u n redova}
Program p1;
var a:array[1..100] of integer;
    s:string; f,g:text;
    n,k,code,code2,i:integer;
begin
  assign(f,'ulaz.in');
  assign(g,'izlaz.out');
  reset(f); rewrite(g);
  while not(eof(f)) do
  begin
    readln(f,s); inc(n);
    while length(s)>0 do
    begin
      k:=0;
      val(s,k,code);
      if code>0 then
      begin
        val(copy(s,1,code-1),k,code2);
        inc(a[n],k);
        delete(s,1,code);
      end else
      begin
        inc(a[n],k);
        delete(s,1,length(s));
      end;
    end;
  end;
  for i:=1 to n do write(g,a[i],' ');
  close(f); close(g);
end.
