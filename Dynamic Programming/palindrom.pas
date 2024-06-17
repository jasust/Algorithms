Program p3;
var mat:array[0..100,0..100] of longint;
    rec:array[0..100,0..100,1..1000] of string[100];
    br:array[0..100,0..100] of longint;
    nasao:array[0..1000] of boolean;
    a,b:string[100];  i,j,p,d,q:longint;
begin
  readln(a); readln(b);
  for i:=1 to length(a) do
   for j:=1 to length(b) do
    begin
      if a[i]=b[j] then
      begin
        mat[i,j]:=mat[i-1,j-1]+1;
        if mat[i,j]=1 then
        begin
          br[i,j]:=1;  rec[i,j,1]:=a[i];
        end
        else  begin
                br[i,j]:=br[i-1,j-1];
                for p:=1 to br[i-1,j-1] do rec[i,j,p]:=rec[i-1,j-1,p]+a[i];
              end;
        end
      else  begin
            if mat[i-1,j]>mat[i,j-1] then
            begin
              mat[i,j]:=mat[i-1,j];   br[i,j]:=br[i-1,j];
              for p:=1 to br[i-1,j] do  rec[i,j,p]:=rec[i-1,j,p];
            end
          else if mat[i-1,j]<mat[i,j-1] then
          begin
            mat[i,j]:=mat[i,j-1];
            br[i,j]:=br[i,j-1];
            for p:=1 to br[i,j-1] do  rec[i,j,p]:=rec[i,j-1,p];
          end
          else
            begin
              mat[i,j]:=mat[i-1,j];
              if mat[i-1,j]=0 then continue;
              d:=0;
              for p:=1 to br[i-1,j] do
              begin
                for q:=1 to br[i,j-1] do
                if rec[i-1,j,p]=rec[i,j-1,q] then nasao[q]:=true;
                inc(d);  rec[i,j,d]:=rec[i-1,j,p];
              end;
              for q:=1 to br[i,j-1] do
                begin
                  if not(nasao[q]) then
                    begin
                      inc(d);  rec[i,j,d]:=rec[i,j-1,q];
                    end
              else nasao[q]:=false;
           end;
        br[i,j]:=d;
        end;
     end;
  end;
  for i:=1 to br[length(a),length(b)] do
  writeln(rec[length(a),length(b),i]);
end.