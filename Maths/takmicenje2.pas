{dao je n takmicara i broj bodova, kvalifikuje se k takmicara.
Odredi broj bodova zadnjeg takmicara i njegov indeks}
program p1;
var a,b:array[1..100] of integer;
    n,i,p,j,k:integer;
begin
  readln(n,k);
  for i:=1 to n do begin read(a[i]); b[a[i]]:=i; end;
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if a[i]<a[j] then
    begin
      p:=a[i];
      a[i]:=a[j];
      a[j]:=p;
    end;
  write(a[k],': ',b[a[k]]);
end.