program p1;
var n,q,i,j,b:longint;
s1,s2,max:qword;
a:array[1..100000] of longint;
begin
        readln(n,q);
        for i:=1 to n do read(a[i]);
        i:=2;
        j:=n-1;
        s1:=a[1];
        s2:=a[n];
        while i<=j do
        begin
                if s1>s2 then
                begin
                        inc(s2,a[j]);
                        dec(j);
                end
                else begin
                        inc(s1,a[i]);
                        inc(i);
                end;
        end;
        if s1<s2 then max:=s1
        else max:=s2;
        for i:=1 to q do
        begin
                readln(b);
                if b<max then writeln('d')
                else writeln('n');
        end;
end.
