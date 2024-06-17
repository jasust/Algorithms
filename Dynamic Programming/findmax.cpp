#include <cstdio>

const int maxn = 1e5;

int n,a[maxn + 5],b[maxn + 5],dp[maxn + 5],dp1[maxn + 5], m, sol;
char x;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        dp[i] = dp[i-1]+a[i];
    }
    scanf("\n");

    for (int i=1; i<=n; i++)
    {
        scanf("%c", &x);
        if (x == '1')
        {
            b[i] = 1;
            if (i>m) m = i;
            dp1[i] = dp1[i-1]+a[i];
        }
        else
        {
            b[i] = 0;
            dp1[i] = dp1[i-1];
        }
    }

    sol = dp1[n];

    for (int i=1; i<=m; i++)
    if ((b[i]==1) and (dp1[n]-dp1[i]+dp[i-1]>sol)) sol = dp1[n]-dp1[i]+dp[i-1];

    printf("%d", sol);
    return 0;
}
