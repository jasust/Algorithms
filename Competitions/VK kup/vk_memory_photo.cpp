#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;

int n,a[maxn],h[maxn],w[maxn],s,x,y;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d %d", &w[i], &h[i]);

    for (int i=0; i<n; i++) s += w[i];

    for (int i=0; i<n; i++) a[i] = h[i];

    sort(a, a + n);

    for (int i=0; i<n; i++)
    {
        x = s-w[i];
        if (h[i] == a[n-1]) y = a[n-2];
        else y = a[n-1];
        printf("%d ", x*y);
    }

    return 0;
}
