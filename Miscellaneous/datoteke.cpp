#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{

FILE *f;
int i;

f=fopen("test1.txt","w");                /*otvaranje datoteke za čitanje i pisanje*/
if(f==NULL)                                   /*ispitivanje valjanosti otvaranja datoteke*/
{
printf("Greska pri otvaranju");
exit(1);
}

for(i=1;i<=100;i++)                        /*upis podataka u datoteku; for petljom; brojeva od 1-100*/
fprintf(f,"%d\n",i);
fclose(f);                                     /*zatvaranje datoteke*/

system ("PAUSE");
return 0;
}
