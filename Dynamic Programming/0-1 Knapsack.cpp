/* Algoritam za odredjivanje maksimalne vrednosti koja moze stati u ranac datog kapaciteta.
   Mozemo uzeti najvise jedan komad od svake vrste predmeta.
   Slozenost O(n*m).
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, w[1003], v[1003], dp[1003];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) scanf("%d %d", w+i, v+i);

    for (int i=1; i<=n; i++) dp[i]=0;

    for (int i=0; i<m; i++)
        for (int j=n; j>=w[i]; j--)
            if (dp[j-w[i]]>=0) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);

    printf("%d", dp[n]);

    return 0;
}
