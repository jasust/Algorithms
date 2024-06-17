{Problem meseca A- odrediti koja permutacija nedostaje}
program pm;
var a:array[97..122,1..10] of longint;
    b:array[97..122] of integer;
    n,i:longint; s:string; j,duz:integer;
begin
  readln(n);
  readln(s);
  duz:=length(s);
  for j:=1 to duz do begin inc(a[ord(s[j]),j]); inc(b[ord(s[j])]); end;
  for i:=97 to 122 do b[i]:=b[i]*(n+1) div duz;
  for i:=2 to n do
  begin
    readln(s);
    for j:=1 to duz do inc(a[ord(s[j]),j]);
  end;
  for i:=1 to duz do
   for j:=97 to 122 do if a[j,i]=b[j]-1 then write(chr(j));
end.
