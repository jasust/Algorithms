
#include <stdio.h>  //13194993 na 10, na 6 13295951, na 20 13223574
#include <cstdlib>
#include <climits>

using namespace std;

const int velicinaGrupe=11;
const int brGrupa=20;

struct st
{
    char min, max, tek;
    st(int mn=0, int mx=0, int t=0):min(mn),max(mx),tek(t){}
};
st A[220];
st AA[220];

char c;
int poz, tek,N, pret;
int r[12];

int main(int argc, const char * argv[]) {
    A[0]=st(10, 10, 10);
    A[1]=st(32,40,34);
    A[2]=st(41,50,44);
    A[3]=st(51,60,54);
    A[4]=st(61,70,64);
    A[5]=st(71,80,74);
    A[6]=st(81,90,84);
    A[7]=st(91,99,94);
    A[8]=st(100,108,104);
    A[9]=st(109,117,114);
    A[10]=st(118,126,124);
    for(int i=0; i<velicinaGrupe; i++)
        r[i]=i;
    for(int i=0; i<11; i++)
        for(int j=0;j<brGrupa; j++)
            AA[i+j*velicinaGrupe]=A[r[i]];
    
    printf ("++++++++++[");
    for(int i=0; i<velicinaGrupe*brGrupa; i++)
        switch(r[i%velicinaGrupe]){
            case 0:printf(">+"); break;
            case 1:printf(">+++"); break;
            case 2:printf(">++++"); break;
            case 3:printf(">+++++"); break;
            case 4:printf(">++++++"); break;
            case 5:printf(">+++++++"); break;
            case 6:printf(">++++++++"); break;
            case 7:printf(">+++++++++"); break;
            case 8:printf(">++++++++++"); break;
            case 9:printf(">+++++++++++"); break;
            case 10:printf(">++++++++++++"); break;
        }
    for(int i=0; i<brGrupa*velicinaGrupe;i++)
        putchar('<');
    printf("-]");
    printf ("++++[");
    for(int i=0; i<brGrupa; i++)
    {
        putchar('>');
        for(int j=1; j<velicinaGrupe; j++)
            printf(">+");
    }
    for(int i=0; i<brGrupa*velicinaGrupe;i++)
        putchar('<');
    printf("-]");
    poz=(brGrupa/2)*velicinaGrupe;
    for(int i=0; i<=poz;i++)
        putchar('>');
    
    while((c=getchar())!=EOF)
    {
        int minVr=poz+abs(c-A[0].tek);
        int minP=0;
        for(tek=1; tek<brGrupa*velicinaGrupe; tek++)
            if(abs(poz-tek)+abs(c-AA[tek].tek)<minVr)
            {
                minVr=abs(poz-tek)+abs(c-AA[tek].tek);
                minP=tek;
            }
        tek=minP;
        while(poz<tek)
        {
            putchar('>');
            poz++;
        }
        while(poz>tek)
        {
            putchar('<');
            poz--;
        }
        while(AA[tek].tek<c)
        {
            putchar('+');
            AA[tek].tek++;
        }
        while(AA[tek].tek>c)
        {
            putchar('-');
            AA[tek].tek--;
        }
        putchar('.');
    }
    return 0;
}
