#include <cstdio>
using namespace std;
const int mod = 1e9 + 7;

long long int n, i, j, k, sol, dp[35][35], dp1[35][35], q[35];

int main()
{
    scanf("%I64d", &k); k++;
    for (n=0; n<35; n++) if (1LL<<n>k) break;
    for (i=0; i<=n; i++) q[i] = 1LL<<i % mod;
    dp1[n][0] = 1;
    while (i--)
        for (j=0; j<n; j++)
    {
        dp[i][j+1] = dp[i+1][j];
        dp[i][j] = (dp[i][j]+q[j]*dp[i+1][j]) % mod;
		if (k>>i&1)
        {
            dp[i][j] = (dp[i][j]+(j?q[j-1]:1)*dp1[i+1][j]) % mod;
			dp1[i][j+1] = dp1[i+1][j];
        }
        dp1[i][j]=(dp1[i][j]+(j?q[j-1]:0)*dp1[i+1][j]) % mod;
    }
    for (i=0; i<n; i++) sol = (sol+dp[0][i]) % mod;
    printf("%I64d", sol);
	return 0;
}
