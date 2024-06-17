program kolicnik;
var n,m,k:integer;
procedure kol(ind:boolean;n,m,k:integer);
begin
  if ind then write(n div m,'.')
         else write(n div m);
  if k<>0 then kol(false,(n mod m)*10,m,k-1);
end;
begin
  readln(n,m,k);
  kol(true,n,m,k);
end.