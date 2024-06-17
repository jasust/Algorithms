Program StepenovanjeMatrice;

type    matrica = array [1..100,1..100] of integer;

var     a,b,c:matrica;
        n,k,i,p,m,j:integer;

        begin
        read(n,k);
        for i:=1 to n do
        for j:=1 to n do read (a[i,j] );

        fillchar(c,sizeof(c),0); b:=a;
        for p:= 1 to k-1 do
        begin
        for i:=1 to n do
        for j:=1 to n do
        for m:=1 to n do c[i,j]:=c[i,j]+b[i,m]*a[m,j];
        b:=c;
        end;
        for i:=1 to n do
        begin
        for j:=1 to n do write(b[i,j],'  '); writeln;
        end;
end.
