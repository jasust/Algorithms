/*Data su dva prirodna broja n <= 1000 i k <= 10000. Naci broj permutacija brojeva od 1 do n koji imaju tacno k inverzija.
  Broj inverzija u permutaciji (p1, p2, ..., pn) je broj parova (i, j) takvih da je pi > pj za 1 <= i < j <= n. */
#include <cstdio>
using namespace std;

int N, K, Dp[2][10005];

int main ( )
{
    scanf("%d%d",&N,&K);
    Dp[1][0] = 1; Dp[0][0] = 1;
    for (int i=1; i<=K; i++) Dp[0][i] = 0;

    for (int i=2; i<=N; i++)
    {
        for (int j=1; j<=K; j++)
        {
            Dp[1][j] = Dp[1][j-1] + Dp[0][j];
            if (j >= i) Dp[1][j] -= Dp[0][j-i];
        }
        for (int j=0; j<=K; j++) Dp[0][j] = Dp[1][j];
    }

    printf("%d",Dp[0][K]);

    return 0;
}
