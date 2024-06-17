#include <cstdio>
#include <algorithm>
using namespace std;

bool a[100005];
int n, bit[100005], stari, novi, br, q, i, x;
struct sve { int l, r, idx, sol; } up[100005];
bool cmp1 ( const sve &a, const sve &b ) { return a.r<b.r; }
bool cmp2 ( const sve &a, const sve &b ) { return a.idx<b.idx; }

int main()
{
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &novi );
        if (stari!=novi) a[i]=true;
        stari = novi;
    }
    scanf("%d", &q);
    for (i=0; i<q; i++)
    {
        scanf("%d %d", &up[i].l, &up[i].r);
        up[i].idx = i;
    }
    sort(up, up+q, cmp1);
    for (i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=j&-j) bit[j]++;
        if (!a[i]) for(int j=i-1; j<=n; j+=j&-j) bit[j]--;
        while (up[x].r==i-1)
        {
            for(int j=i; j>0; j-=j&-j) up[x].sol+=bit[j];
            for(int j=up[x].l; j>0; j-=j&-j) up[x].sol-=bit[j];
            x++;
        }
    }

    sort(up, up+q, cmp2);
    for (i=0; i<q; i++) printf("%d\n", up[i].sol);
    return 0;
}
