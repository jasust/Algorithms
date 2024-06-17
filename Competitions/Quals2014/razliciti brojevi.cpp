#include <cstdio>
using namespace std;

bool a[100005];
int n, dp[100005], stari, novi, sol, q, i, l, r;

int main()
{
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &novi );
        dp[i] = dp[i-1];
        if (stari!=novi) a[i]=true, dp[i]++;
        stari = novi;
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &l, &r);
        sol = dp[r+1] - dp[l];
        if (!a[l+1]) sol++;
        printf("%d\n", sol);
    }
    return 0;
}
