// Z-trening problem z-pumpe //
#include <cstdio>
using namespace std;
int a[105][105], n, m, k, x, y, l, w, r, mini = 2147483647, bio[105];
bool p[105], t;

void DFS( int st, int tr )
{
    if ( st == n )
    {
        t = true;
        if ( tr<mini ) mini = tr;
    }
    else
    {
        bio[st] = true;
        if ( p[st] ) r = l;
        for (int i=1; i<=n; i++)
           if (a[st][i] && a[st][i]<=r && !bio[i])
           {
                r -= a[st][i];
                DFS( i, tr+a[st][i]);
           }
           bio[st] = false;
    }
}

 int main()
 {
     scanf("%d%d%d%d", &n, &m, &l, &k);
     for (int i=1; i<=k; i++)
     {
         scanf("%d%d%d", &x, &y, &w);
         a[x][y] = a[y][x] = w;
     }
     for (int i=1; i<=m; i++)
     {
         scanf("%d", &x);
         p[x] = true;
     }
     DFS( 1, 0 );
     if (t) printf("%d", mini); else printf("-1");
 }
