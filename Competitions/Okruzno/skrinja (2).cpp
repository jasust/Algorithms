#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010, inf = 2000000009;
int n, k, sol = inf, a[N];
int re[N], te[N], s[N];

void rek(int c, int d)
{
    if (c > n)
    {
        int mi = inf, ma = 0;
        for (int i = 1; i <= k; i++) mi = min(mi, s[i]);
        for (int i = 1; i <= k; i++) ma = max(ma, s[i]);
        if (ma - mi < sol)
        {
            sol = ma - mi;
            for (int i = 1; i <= n; i++) re[i] = te[i];
        }
        return;
    }
    int g = min(d + 1, k);
    for (int i = 1; i <= g; i++)
    {
        s[i] += a[c]; te[c] = i;
        if (i == d + 1) rek(c + 1, d + 1); else
        rek(c + 1, d);
        s[i] -= a[c];
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    rek(1, 0);
    printf("%d\n", sol);
    for (int i = 1; i <= n; i++) printf("%d ", re[i]); printf("\n");
    return 0;
}
