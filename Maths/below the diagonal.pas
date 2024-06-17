program diagonaal;
var a:array [1..10000,1..3] of longint;
    x,y,c,h,dau:array [1..10000] of longint;
    n,i,j,KQ,max,t,k,p:longint;
begin
    readln(n); KQ:=0;
    fillchar(dau,sizeof(dau),0);
    for i:=1 to n-1 do
        begin
            readln(x[i],y[i]);
            inc(c[y[i]]);
        end;
    t:=1;
    repeat
        begin
            max:=0;
            for j:=1 to n-1 do
                if (max<c[y[j]]) and (dau[y[j]]=0) then
                    begin
                        max:=c[y[j]];
                        k:=j;
                    end;
            if (y[k]<>t) and (dau[y[k]]<>1) then
                begin
                    inc(KQ);
                    a[KQ][1]:=2;
                    a[KQ][2]:=t;
                    a[KQ][3]:=y[k];
                    for j:=1 to n-1 do
                        if y[j]=t then y[j]:=y[k];
                    y[k]:=t;
                end;
            dau[t]:=1;inc(t);
        end;
    until t=n;
    t:=n;
    for i:=1 to n-1 do
        if y[i]>h[x[i]] then h[x[i]]:=y[i];
    fillchar(dau,sizeof(dau),0);
    repeat
        begin
            max:=0;
            for j:=1 to n-1 do
                if (h[x[j]]>max) and (dau[x[j]]=0) then
                    begin
                        max:=h[x[j]];
                        k:=j;
                    end;
            if (t<>x[k]) and (dau[x[k]]<>1) then
                begin
                    inc(KQ); a[KQ][1]:=1;
                    a[KQ][2]:=t;
                    a[KQ][3]:=x[k];
                    p:=h[t]; h[t]:=h[x[k]];
                    h[x[k]]:=p;
                    for j:=1 to n-1 do
                        if x[j]=t then x[j]:=x[k];
                end;
            dau[t]:=1; dec(t);
        end;
    until t=0;
    writeln(KQ);
    for i:=1 to KQ do writeln(a[i][1],' ',a[i][2],' ',a[i][3]);
end.
