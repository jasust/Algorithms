#include <cstdio>
#include <algorithm>
using namespace std;

int d0[3003], d1[3003], a[3003], b[3003], c[3003], n;

int main()
{
    scanf("%d", &n);

    for (int i=1; i<=n; i++) scanf("%d", a + i);
    for (int i=1; i<=n; i++) scanf("%d", b + i);
    for (int i=1; i<=n; i++) scanf("%d", c + i);

    d0[1] = a[1];
    d1[1] = b[1];

    for (int i=2; i<=n; i++)
    {
        d0[i] = max(a[i]+d1[i-1], b[i]+d0[i-1]);
        d1[i] = max(b[i]+d1[i-1], c[i]+d0[i-1]);
    }

    printf("%d", d0[n]);
    return 0;
}
