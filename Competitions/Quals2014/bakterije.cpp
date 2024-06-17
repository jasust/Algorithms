#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long lld;
const lld Maxt = 1e10;
FILE *f;

int n, i, j, br, t;
lld maxx;
struct node
{
    int x, y, t, s, c;
    lld v;
} a[1006];
struct node1
{
    int prvi, drugi;
    lld dis;
} b[1000006];
bool cmp1(const node1 &a, const node1 &b) { return a.dis<b.dis; }

int main()
{
    f=fopen("input0.txt","r");
    fscanf(f,"%d", &n);
    for (i=1; i<=n; i++)
    {
        fscanf(f,"%d %d %d %d", &a[i].x, &a[i].y, &a[i].t, &a[i].s);
        a[i].v = Maxt;
        a[i].c = i;
    }
    for (i=2; i<=n; i++)
        for (j=1; j<i; j++)
    {
        br++;
        b[br].dis = (abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)-abs(a[i].t-a[j].t)+1)>>1;
        if (b[br].dis<0) b[br].dis=0;
        b[br].dis += max(a[i].t,a[j].t);
        b[br].prvi = j;
        b[br].drugi = i;
    }
    sort(b+1, b+br+1, cmp1);
    for (i=1; i<=br; i++)
        if (a[b[i].prvi].v>=b[i].dis && a[b[i].drugi].v>=b[i].dis)
        {
            if (a[b[i].prvi].s==a[b[i].drugi].s)
            {
                if (a[b[i].prvi].v==b[i].dis)
                {
                    t=b[i].drugi;
                    while (a[t].v>b[i].dis) { a[t].v=b[i].dis; t=a[t].c; }
                }
                else if (a[b[i].drugi].v==b[i].dis)
                {
                    t=b[i].prvi;
                    while (a[t].v>b[i].dis) { a[t].v=b[i].dis; t=a[t].c; }
                }
                else { t=a[b[i].prvi].c; a[b[i].prvi].c=a[b[i].drugi].c; a[b[i].drugi].c=t; }
            }
            else
            {
                if (a[b[i].prvi].v>b[i].dis || a[b[i].drugi].v>b[i].dis) maxx=b[i].dis;
                t=b[i].drugi;
                while (a[t].v>b[i].dis) { a[t].v=b[i].dis; t=a[t].c; }
                t=b[i].prvi;
                while (a[t].v>b[i].dis) { a[t].v=b[i].dis; t=a[t].c; }
            }
        }
    for (i=1; i<=n; i++)
     if (a[i].v == Maxt)
     {
         printf("%I64d\n1\n%d", maxx, a[i].s);
         return 0;
     }
     printf("%I64d\n0\n", maxx);
     return 0;
}
