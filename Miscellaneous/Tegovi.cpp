/*
    Dato je N tegova sa tezinama, treba ih podeliti u 2 grupe tako da je razlika izmedju suma tegova u obe grupe
    najmanja.
*/
#include <cstdio>
#include <cstdlib>

int N, Sum1 , Min ;
int t[100],  Sol[100], Bit [100];

void TEG ( int pos , int Sum2 )
{
    if ( abs( Sum2 - Sum1 ) < Min )
    {
        Min = abs ( Sum2 - Sum1 );
        for (int i = 1 ; i <= N ; i++) Sol[i] = Bit[i] ;
    }
    for (int i=pos ; i<=N ; i++)
    {
        Bit[i] = 1;
        TEG ( pos + 1 , Sum2 + t[i] );

        Bit[i] = 0;
        TEG ( pos + 1 , Sum2 );
    }
}
int main()
{

    scanf("%d",&N);
    for (int i=1; i<=N ; i++)
     {
         scanf("%d",&t[i]);
         Sum1 +=t[i];
     }
    Sum1 /= 2;
    Min = 32000;
    TEG ( 1 , 0 );

    for (int i=1 ; i<=N ; i++)
        if ( Sol [ i ] ) printf("%d ",t[i]);
    printf("\n");

    for (int i=1 ; i<=N ; i++)
        if (! Sol [ i ] ) printf("%d ",t[i]);
    printf("\n");
    return 0;
}
