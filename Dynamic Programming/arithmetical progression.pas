{Naci duzinu najduzeg podniza a niza b tako da vazi
    a1=p,gde je p neki integer;
    ai= ai-1 + (-1)^i+1 ú q(i>1),gde je q neki integer.}
program aap;
var  res,n,i,j:integer;
     b,p:array[0..1000000] of integer;
     dp:array[0..4001,0..4001] of integer; //dp--matrica cije polje dp[i,j] pokazuje duzinu
begin                                     //najduzeg podniza niza b do i-tog polja sa datim
                                         //osobinama i poslednjom cifrom na j-om mestu
  readln(n);
  for i:=1 to n do read(b[i]);   //ucitavanje niza b

  for i:=0 to n+1 do               //popunjavanje matrice dp jedinicama jer svaki
    for j:=0 to n+1 do dp[i,j]:=1; //podniz duzine 1 ima date osobine
  fillchar(p,sizeof(p),0);

  for i:=n-1 downto 1 do
   for j:=n downto i+1 do
    begin                        //popunjavanje matrice dp tako sto na duzinu podniza
      dp[i,j]:=dp[j,p[b[i]]]+1;  // do j nadovezemo jos jedan clan
      p[b[j]]:=j;
    end;

  for i:=1 to n-1 do
    for j:=i+1 to n do if dp[i,j]>res then res:=dp[i,j];
  if res>0 then writeln(res) else writeln(1);             //resenje je najveci broj matrice dp

end.
