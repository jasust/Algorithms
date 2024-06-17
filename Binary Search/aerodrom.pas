{M ljudi putuje u Australiju,te trenutno stoji u redu za registraciju.Registracija
 se obavlja na N saltera,salteri rade razlicitim brzinama. k-tom salteru treba T[k]
 sekundi da obavi registraciju jedne osobe i ti brojevi su poznati.Na pocetku svi su
 salteri slobodni.U nekom trenutku osoba odmah moze otici na neki slobodni salter
 (ako takav postoji),ali moze i cekati da se oslobodi neki brzi.Izracunati najkrace
 vreme za koje ce svi da zavrse sa registracijom.
 N (1ÛNÛ100 000),broj saltera,i M (1ÛMÛ1 000 000 000),broj ljudi
 U sledecih N redova nalaze se brojevi Tk (1ÛTkÛ1 000 000 000).}
program aerodrom;
var n,m,i:longint;
    d,l,sred,s:qword;
    t:array[1..100000] of longint;

begin
  read(n,m);
  for i:=1 to n do read(t[i]);
  l:=1; d:=1000000000000000000;

  while (l<d) do
  begin
    s:=0; sred:=(l+d) div 2;
    for i:=1 to n do s:=s+(sred div t[i]);
    if s=m then begin writeln(sred); halt(0); end
     else if s>m then d:=sred
      else l:=sred+1;
  end;
  writeln(l);

end.