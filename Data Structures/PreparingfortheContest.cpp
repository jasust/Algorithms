// Codeforces Problem 377B - Preparing for the contest
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long lld;

const lld inf=1e18, maxn=200005;
struct node{ bool t; lld val,idx,c; } a[maxn];
lld ans[maxn], ans1[maxn];
lld n, m, s, x, l, r, mid, t, sc, cu;

bool cmp1(const node &a,const node &b) { return a.val<b.val||(a.val==b.val&&a.t<b.t); }
bool operator > (const node &a,const node &b){ return a.c>b.c; }
priority_queue < node, vector <node>, greater<node> > dq;

int main()
{
    scanf("%I64d %I64d %I64d", &n, &m, &s);
    for (int i=1; i<=m; i++)
    {
        scanf("%I64d", &a[i].val);
        a[i].t=0;
        a[i].idx=i;
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%I64d", &a[m+i].val);
        a[m+i].t=1;
        a[m+i].idx=i;
    }
    for (int i=1; i<=n; i++) scanf("%I64d", &a[m+i].c);
    sort(a+1, a+n+m+1, cmp1);

    l=0, r=m+1;
    while (l < r-1)
    {
        mid = (l+r)>>1;
        x=1; t=0; sc=0;
        while (!dq.empty()) dq.pop();
        for (int i=n+m; i; i--) if (a[i].t) dq.push(a[i]); else
        {
            t++;
            if (t==x && !dq.empty())
            {
                cu=dq.top().idx;
                sc+=dq.top().c;
                dq.pop();
                x=mid;t=0;
            } else
            if (t==x&&dq.empty())
            {
                sc=inf;
                break;
            }
            ans1[a[i].idx]=cu;
        }
        if (sc<=s)
        {
            r=mid;
            for (int i=1; i<=m; i++) ans[i]=ans1[i];
        } else l=mid;
    }

    if ( l==m ){ printf("NO\n"); return 0; }
    printf("YES\n");
    for (int i=1; i<=m; i++) printf("%I64d ", ans[i]);
    return 0;
}
