/* BOI 2013 - Kebab eating contest */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 200000 +5;
int n, m, cnt[maxn], val[maxn], sol[maxn], bit1[maxn], bit2[maxn];

struct pnt{
    int p,v,s;
} a[maxn];
bool cmp1(const pnt &x,const pnt &y){ if (x.p==y.p) return x.s < y.s; else return x.p < y.p; }
bool cmp2(int i, int j) { return i>j; }

void update1( int j, int x )
{
    while ( j<=n )
    {
        bit1[j] += x;
        j += j & -j;
    }
}
void update2( int j, int x )
{
    while ( j<=n )
    {
        bit2[j] += x;
        j += j & -j;
    }
}
int get1(int j)
{
    int ret = 0;
    while ( j )
    {
        ret += bit1[j];
        j -= j & -j;
    }
    return ret;
}
int get2(int j)
{
    int ret = 0;
    while ( j )
    {
        ret += bit2[j];
        j -= j & -j;
    }
    return ret;
}
int binser( int x )
{
    int l = 1, r = n, mid, temp;
    while ( l < r )
    {
         mid = (l + r) / 2;
         temp = get1(mid);
         if ( x == temp ) return mid;
         else if ( temp > x ) r = mid - 1;
         else l = mid + 1;
    }
    return l;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &a[i].p);
    for (int i=1; i<=n; i++) { scanf("%d", &a[i].v); cnt[i] = a[i].v; a[i].s=i; }
    for (int i=n+1; i<=m+n; i++) scanf("%d", &a[i].p);
    for (int i=n+1; i<=m+n; i++) { scanf("%d", &a[i].v); a[i].s = i; }

    sort(a + 1, a + n + m + 1, cmp1);
    sort(cnt + 1, cnt + n + 1, cmp2);
    for (int i=1; i<=n; i++) val[cnt[i]] = i;

    for (int i=1; i<=n+m; i++)
    {
        if (a[i].s <= n)
        {
            update1( val[a[i].v], 1);
            update2( val[a[i].v], a[i].v);
            val[a[i].v]--;
        }
        else sol[a[i].s - n] = get2 ( binser( a[i].v ));
    }
    for (int i=1; i<=m; i++) printf("%d ", sol[i]);

    return 0;
}
