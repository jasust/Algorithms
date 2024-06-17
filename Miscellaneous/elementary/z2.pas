program p1;
var a:array[1..10] of longint;
    i:longint;
    n,x:qword;
begin
  readln(n);
  while (n>1) and ((n mod 2=0)or(n mod 3=0)or(n mod 5=0)or(n mod 7=0)) do
  begin
    if n mod 2=0 then begin a[2]:=a[2]+1; n:=n div 2; end;
    if n mod 3=0 then begin a[3]:=a[3]+1; n:=n div 3; end;
    if n mod 5=0 then begin a[5]:=a[5]+1; n:=n div 5; end;
    if n mod 7=0 then begin a[7]:=a[7]+1; n:=n div 7; end;
  end;
  a[8]:=a[2] div 3; a[2]:=a[2] mod 3;
  a[4]:=a[2] div 2; a[2]:=a[2] mod 2;
  a[9]:=a[3] div 2; a[3]:=a[3] mod 2;
  if (a[2]=1) and (a[3]=1) then begin a[6]:=1; a[2]:=0; a[3]:=0; end;
  for i:=2 to 9 do while a[i]>0 do
  begin
    x:=x*10+i;
    a[i]:=a[i]-1;
  end;
  write(x);
end.
