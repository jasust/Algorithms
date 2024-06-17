#include <cstdio>
using namespace std;
const int N = 100005;

int n, k, i, x, y, h[N], v[N], d1[2*N], d2[2*N];

int main()
{
    scanf("%d %d", &n, &k);

    for (i=1; i<=n; i++)
    {
        scanf("%d %d", &x, &y);
        if (++h[y]==k) break;
        if (++v[x]==k) break;
        if (++d1[100000+x-y]==k) break;
        if (++d2[x+y]==k) break;
    }

    if (i<=n) printf("%d", i); else printf("-1");

    return 0;
}
