/* Dat je niz razlicitih prirodnih brojeva duzine n. Nad nizom mozete izvrsavati dve operacije: proizvoljan element iz niza
   prebacite na njegov pocetak ili na njegov kraj. Odrediti minimalni broj operacija tako da rezultujuci niz bude rastuci.
 */
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MaxN = 1 << 12;

int N, Max, Dp[MaxN+5], A[MaxN+5], B[MaxN+5];
map < int, int > Hash;

int main( void )
{

    scanf("%d",&N);

    for (int i=0; i<N; i++)
    {
            scanf("%d",&A[i]);
            B[i] = A[i];
    }

    sort(B, B + N);

    for (int i=0; i<N; i++) Hash[B[i]] = i + 1;
    for (int i=0; i<N; i++) A[i] = Hash[A[i]];

    for (int i=0; i<N; i++)
    {
        Dp[A[i]] = Dp[A[i] - 1] + 1;
        if ( Dp[A[i]] > Max ) Max = Dp[A[i]];
    }

    printf("%d",N - Max);

    return 0;
}
