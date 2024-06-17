#include <cstdio>
#include <cstring>
using namespace std;

int n, i, j, x, y, l, q, dp[1003][1003];
char a[1003], b[1003];

int main()
{
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    for (i=0; i<=n; i++) dp[0][i] = dp[i][0] = 0;

    for (i=0; i<n; i++)
    {
        for (j=1; j+i<=n; j++)
        {
            dp[j][i+j] = dp[j-1][i+j-1];
            if (a[j-1]==b[i+j-1]) dp[j][i+j]++;
        }
        for (j=1; (j+i<=n) && i; j++)
        {
            dp[i+j][j] = dp[i+j-1][j-1];
            if (a[i+j-1]==b[j-1]) dp[i+j][j]++;
        }
    }

    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d%d", &x, &y, &l);
        printf("%d\n", dp[x+l-1][y+l-1]-dp[x-1][y-1]);
    }

    return 0;
}
