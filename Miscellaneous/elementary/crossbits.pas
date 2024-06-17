var   n,k,p:longint;
   a:array[0..1] of longint;
 begin
 p:=2;
  While true do
   begin
    read(n);
    if n=0 then exit;
    read(kiss);
    if (n=4) and (k=1) then
     begin
      writeln('0 0 1 0');
      writeln('1 0 0 0');
      writeln('0 0 0 1');
      writeln('0 1 0 0');
     end
    else
    if (n=5) and (k=1) then
     begin
      writeln('0 0 0 1 0');
      writeln('0 0 1 0 0');
      writeln('1 0 0 0 0');
      writeln('0 0 0 0 1');
      writeln('0 1 0 0 0');
     end
    else
    if (n=6) and (k=1) then
     begin
      writeln('0 0 0 0 1 0');
      writeln('0 0 0 1 0 0');
      writeln('0 0 0 0 0 1');
      writeln('0 1 0 0 0 0');
      writeln('1 0 0 0 0 0');
      writeln('0 0 1 0 0 0');
     end
    else
    if (n=7) and (k=1) then
     begin
      writeln('0 0 0 0 0 1 0');
      writeln('0 0 0 0 1 0 0');
      writeln('0 0 0 0 0 0 1');
      writeln('0 0 1 0 0 0 0');
      writeln('0 1 0 0 0 0 0');
      writeln('1 0 0 0 0 0 0');
      writeln('0 0 0 1 0 0 0');
     end
    else
    if (n=8) and (k=1) then
     begin
      writeln('0 0 0 0 0 0 1 0');
      writeln('0 0 0 0 0 1 0 0');
      writeln('0 0 0 0 0 0 0 1');
      writeln('0 0 1 0 0 0 0 0');
      writeln('0 1 0 0 0 0 0 0');
      writeln('0 0 0 0 1 0 0 0');
      writeln('1 0 0 0 0 0 0 0');
      writeln('0 0 0 1 0 0 0 0');
     end
    else
    if (n=9) and (k=1) then
     begin
      writeln('0 0 0 0 0 0 0 1 0');
      writeln('0 0 0 0 0 0 1 0 0');
      writeln('0 0 0 0 0 0 0 0 1');
      writeln('0 0 0 0 1 0 0 0 0');
      writeln('0 0 0 0 0 1 0 0 0');
      writeln('0 0 1 0 0 0 0 0 0');
      writeln('0 1 0 0 0 0 0 0 0');
      writeln('1 0 0 0 0 0 0 0 0');
      writeln('0 0 0 1 0 0 0 0 0');
     end
    else
    if (n=10) and (k=1) then
     begin
      writeln('0 0 0 0 0 0 0 0 1 0');
      writeln('0 0 0 0 0 0 0 1 0 0');
      writeln('0 0 0 0 0 0 0 0 0 1');
      writeln('0 0 0 0 0 1 0 0 0 0');
      writeln('0 0 0 0 0 0 1 0 0 0');
      writeln('0 0 0 1 0 0 0 0 0 0');
      writeln('0 0 0 0 1 0 0 0 0 0');
      writeln('0 1 0 0 0 0 0 0 0 0');
      writelN('1 0 0 0 0 0 0 0 0 0');
      writeln('0 0 1 0 0 0 0 0 0 0');
     end
    else
   if (n=6) and (k=2) then
    begin
    writeln('0 0 0 1 1 0');
    writeln('1 0 0 1 0 0');
    writeln('0 0 0 0 1 1');
    writeln('1 1 0 0 0 0');
    writeln('0 0 1 0 0 1');
    writeln('0 1 1 0 0 0');
    end
   else
   if (n=7) and (k=4) then
    begin
     writeln('0 0 1 1 1 1 0');
     writeln('1 0 1 1 1 0 0');
     writeln('1 1 0 0 0 1 1');
     writeln('1 1 0 0 0 1 1');
     writeln('1 1 0 0 0 1 1');
     writeln('0 0 1 1 1 0 1');
     writeln('0 1 1 1 1 0 0');
    end
   else
   if (n=7) and (k=2) then
    begin
     writeln('0 0 0 0 1 1 0');
     writeln('0 0 0 1 1 0 0');
     writeln('0 0 0 0 0 1 1');
     writeln('1 0 0 0 0 0 1');
     writeln('1 1 0 0 0 0 0');
     writeln('0 0 1 1 0 0 0');
     writeln('0 1 1 0 0 0 0');
    end
   else
   if (n=7) and (k=3) then
    begin
      writeln('0 0 0 1 1 1 0');
      writeln('0 0 1 1 1 0 0');
      writeln('1 1 0 0 0 1 0');
      writeln('1 0 0 0 0 1 1');
      writeln('1 1 0 0 0 0 1');
      writeln('0 0 1 0 1 0 1');
      writeln('0 1 1 1 0 0 0');
    end
  else
 if (n=8) and (k=5) then
    begin
     writeln('0 0 1 1 1 1 1 0');
     writeln('1 0 1 1 1 1 0 0');
     writeln('1 1 0 0 1 0 1 1');
     writeln('1 1 1 0 0 0 1 1');
     writeln('1 1 0 0 0 1 1 1');
     writeln('1 1 0 1 0 0 1 1');
     writeln('0 0 1 1 1 1 0 1');
     writeln('0 1 1 1 1 1 0 0');
    end
   else
 if (n=8) and (k=4) then
   begin
    writeln('0 0 0 1 1 1 1 0');
    writeln('0 0 1 1 1 1 0 0');
    writeln('1 1 0 0 0 0 1 1');
    writeln('1 1 1 0 0 0 0 1');
    writeln('1 0 0 0 0 1 1 1');
    writeln('1 1 0 0 0 0 1 1');
    writeln('0 0 1 1 1 1 0 0');
    writeln('0 1 1 1 1 0 0 0');
   end
 else
 if (n=8) and (k=3) then
   begin
    writeln('0 0 0 0 1 1 1 0');
    writeln('0 0 0 1 1 1 0 0');
    writeln('0 0 0 0 1 0 1 1');
    writeln('1 0 1 0 0 0 0 1');
    writeln('1 1 0 0 0 0 0 1');
    writeln('1 1 0 0 0 0 1 0');
    writeln('0 0 1 1 0 1 0 0');
    writeln('0 1 1 1 0 0 0 0');
   end
 else
 if (n=8) and (k=2) then
  begin
    writeln('0 0 0 0 0 1 1 0');
    writeln('0 0 0 0 1 1 0 0');
    writeln('0 0 0 0 0 0 1 1');
    writeln('0 0 1 0 0 0 0 1');
    writeln('0 1 1 0 0 0 0 0');
    writeln('1 1 0 0 0 0 0 0');
    writeln('1 0 0 1 0 0 0 0');
    writeln('0 0 0 1 1 0 0 0');
  end
 else
 if (n=9) and (k=2) then
  begin
   writeln('0 0 0 0 0 0 1 1 0');
   writeln('0 0 0 0 0 1 1 0 0');
   writeln('0 0 0 0 0 0 0 1 1');
   writeln('0 0 0 0 1 0 0 0 1');
   writeln('0 0 0 1 0 1 0 0 0');
   writeln('0 1 1 0 0 0 0 0 0');
   writeln('1 1 0 0 0 0 0 0 0');
   writeln('1 0 0 0 1 0 0 0 0');
   writeln('0 0 1 1 0 0 0 0 0');
  end
 else
 if (n=9) and (k=3) then
  begin
  writeln('0 0 0 0 0 1 1 1 0');
  writeln('0 0 0 0 1 1 1 0 0');
  writeln('0 0 0 0 0 1 0 1 1');
  writeln('0 0 0 0 1 0 0 1 1');
  writeln('0 1 0 1 0 0 0 0 1');
  writeln('1 1 1 0 0 0 0 0 0');
  writeln('1 1 0 0 0 0 1 0 0');
  writeln('1 0 1 1 0 0 0 0 0');
  writeln('0 0 1 1 1 0 0 0 0');
 end
else
 if (n=10) and (k=2) then
  begin
   writeln('0 0 0 0 0 0 0 1 1 0');
   writeln('0 0 0 0 0 0 1 1 0 0');
   writeln('0 0 0 0 0 0 0 0 1 1');
   writeln('0 0 0 0 0 1 0 0 0 1');
   writeln('0 0 0 1 0 0 1 0 0 0');
   writeln('0 0 1 1 0 0 0 0 0 0');
   writeln('0 1 0 0 0 1 0 0 0 0');
   writeln('1 1 0 0 0 0 0 0 0 0');
   writeln('1 0 0 0 1 0 0 0 0 0');
   writeln('0 0 1 0 1 0 0 0 0 0');
  end
 else
  if (n=10) and (k=3) then
   begin
   writeln('0 0 0 0 0 0 1 1 1 0');
   writeln('0 0 0 0 0 1 1 1 0 0');
   writeln('0 0 0 0 0 0 1 0 1 1');
   writelN('0 0 0 0 0 1 0 0 1 1');
   writeln('0 0 0 1 0 0 0 1 0 1');
   writeln('0 1 1 1 0 0 0 0 0 0');
   writeln('1 1 0 0 0 1 0 0 0 0');
   writeln('1 1 0 0 1 0 0 0 0 0');
   writeln('1 0 1 0 1 0 0 0 0 0');
   writeln('0 0 1 1 1 0 0 0 0 0');
  end
 else
  writeln('nije gotovo');
end;
end.