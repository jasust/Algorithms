#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 2147483647;

int n, k, i, j, l, mid, sum, a[2003], dp[2003][27];
priority_queue < int, vector<int>, less<int> > down;
priority_queue < int, vector<int>, greater<int> > up;

int main()
{
    while (true)
    {
        scanf("%d%d", &n, &k);
        if (!n && !k) break;
        for (i=1; i<=n; i++) scanf("%d", a+i);
        for (i=0; i<=n; i++)
            for (j=0; j<=k; j++) dp[i][j] = inf;
        dp[0][0] = 0;
        for (i=1; i<=n; i++)
        {
            mid = a[i];
            sum = 0;
            for (j=0; j<k; j++) dp[i][j+1] = min(dp[i][j+1], dp[i-1][j]);
            for (l=i-1; l; l--)
            {
                if ((i-l)&1)
                {
                    if (a[l]>=mid)
                    {
                        down.push(mid); up.push(a[l]);
                        sum += a[l] - mid;
                    } else
                    {
                        down.push(a[l]); up.push(mid);
                        sum += mid - a[l];
                    }
                } else
                {
                    if (a[l]>up.top())
                    {
                        mid = up.top();
                        up.pop(); up.push(a[l]);
                        sum += a[l] - mid;
                    } else
                    if (a[l]<down.top())
                    {
                        mid = down.top();
                        down.pop(); down.push(a[l]);
                        sum += mid - a[l];
                    } else mid = a[l];
                }
                for (j=0; j<k; j++)
                    if (dp[l-1][j]<inf) dp[i][j+1] = min(dp[i][j+1], dp[l-1][j]+sum);
            }
            while (!up.empty()) up.pop(), down.pop();
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
