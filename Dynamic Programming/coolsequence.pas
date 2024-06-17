{Par prirodnih brojeva (x,y) je cool ako se x moze predstaviti kao zbir y uzastopnih
 celih brojeva. Niz je cool ako je svako od parova (a[i],a[i+1]) cool. Ako je
 zadat niz od n<=5000 clanova manjih od 10^15, koliko najmanje brojeva mozemo
 promeniti da bi taj niz postao cool?               DP                      }

program coolsequences;
var p,a,dp:array[0..10000] of int64;  //algoritam radi u O(n^2)
    i,j,n,ans:longint;
                                     //x=n1 * 2^a
function max(x,y:int64):int64;       //y=n2 * 2^b
begin
  if x>y then max:=x else max:=y;
end;
                     //brojevi koji se mogu dobiti kao zbir y uzastopnih celih
begin                //brojeva su oblika y(y+1)/2 + ky, gde je k neki ceo broj
  readln(n);         //razmatranjem po parnosti y, dobijamo da je (x,y) cool
  for i:=1 to n do   //             akko n2|n1 i (b=0 ili b=a+1)
  begin
    read(a[i]);
    while a[i] mod 2=0 do
    begin
      a[i]:=a[i] shr 1; //niz a drzi najvece neparne delioce clanova niza
      inc(p[i]);        //niz p drzi stepene dvojke svakog clana niza
    end;
  end;
  for i:=1 to n do    //broj dp[i] nam govori koliko najvise brojeva ne moramo
  begin               //da promenimo pre i-tog(ukljucujuci i-tog) ako bismo ga zadrzali
    dp[i]:=1;
    for j:=1 to i-1 do
     if (a[j] mod a[i]=0) and ((p[j]+i-j=p[i])or(p[i]<=i-j-1)) then dp[i]:=max(dp[i],dp[j]+1);
     ans:=max(ans,dp[i]); //niz dp kreiramo tako sto za svako j pre i proveravamo da li je
  end;                    //moguce kreirati cool niz zadrzavajuvi i-ti i j-ti, menjajuci sve izmedju
  writeln(n-ans);         //(n-najveci clan dp-a) je resenje
end.
