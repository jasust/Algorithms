//Tangentta 73/1 - 3.Podniz
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[10005], dp[10005][1005]; //dp[i][j] nam govori kolika je duzina najduzeg podniza do i-tog clana niza
                               //tako da njihov zbir daje ostatak j pri deljenju sa m
int main()
{
    scanf("%d%d", &m, &n);

    for (int i = 1; i<=n; i++)
    {
        scanf("%d", a + i);
        a[i] %= m;
    }
    for (int i = 1; i<m; i++) dp[0][i] = -10005;

    for (int i = 1; i<=n; i++)
        for (int j = 0; j<m; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][(m+j-a[i])%m] + 1);

    printf("%d", dp[n][0]);

    return 0;
}
