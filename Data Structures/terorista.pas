{Zgrada ima N spratova.Na svakom spratu se nalazi bazen.Terorista zeli da srusi
zgradu tako sto ce porusiti prvi sprat.Za svaki sprat je poznato:

Wi - tezina vode koja se nalazi u bazenu na i-tom spratu na pocetku
Li - tezina vode koju i -ti sprat moze da izdrzi
Ci - cena dinamita potrebnog da se porusi i-ti sprat
Sva voda iz srusenog sprata odlazi na sledeci nici.Ako tezina vode na nekom spratu
postane veca od one koju moze da izdrzi,pod se rusi i sva voda prelazi nadole.

Vas zadatak je da pomognete teroristi da sa sto manje novca srusi prvi sprat.}

program terorist;
var l,c,w,a,heap:array[0..100005] of int64;
    n,i,k:longint;
    heapsize,x,min,curr:int64;

procedure ubaci(x:longint);    //procedura za ubacivanje elemenata u heap
var s,f:longint;
begin
  inc(heapsize);
  s:=heapsize; f:=s div 2;
  while (s>1) and (a[heap[f]]>a[x]) do
  begin
    heap[s]:=heap[f];
    s:=f;
    f:=s div 2;
  end;
  heap[s]:=x;
end;

procedure izbaci;    //procedura za izbacivanje elemenata iz heap-a
var h,s,f:longint;
begin
  heap[1]:=heap[heapsize];
  h:=heap[1]; f:=1;
  while (2*f<heapsize) do
  begin
    if a[heap[f*2]]>a[heap[2*f+1]] then s:=2*f+1 else s:=2*f;
    if a[heap[s]]<a[h] then
    begin
      heap[f]:=heap[s];
      f:=s;
    end else break;
  end;
  heap[f]:=h;
  dec(heapsize);
end;

begin
  readln(n);
  read(w[1],l[1],c[1]);
  for i:=2 to n do
  begin
    read(x,l[i],c[i]);
    w[i]:=w[i-1]+x;
    a[i]:=l[i]+w[i-1];
  end;
  min:=c[1]; heap[1]:=1; a[1]:=l[1];
  curr:=c[1]; k:=1; heapsize:=1;
  for i:=2 to n do
  begin
    inc(curr,c[i]);
    ubaci(i);
    while heapsize>0 do
    if w[i]>a[heap[1]] then
    begin
      dec(curr,c[heap[1]]);
      izbaci;
    end else break;
    if curr<min then begin min:=curr; k:=i; end;
  end;
  writeln(min);
  for i:=k downto 1 do
   if w[k]<=a[i] then writeln(i);
end.
