//  Codeforces Problem 369E - Valera and Queries
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=300003;
const int inf=1000006;
struct seg{ int l,r; } s[maxn];
int z[maxn], prv[maxn], n, m, c, j, x;

struct binaryindextree
{
    int t[inf];
    void upd(int i,int x) { for (; i<inf; i+=i&-i) t[i]+=x; }
    int sum(int i) { int s=0; for (; i; i-=i&-i) s+=t[i]; return s; }
} bit;

struct prc
{
    int val,idx;
    prc(int a,int b){ val=a; idx=b; }
};
vector <prc> p;
bool cmp1(const seg &a,const seg &b){ return a.r<b.r; }
bool cmp2(const prc &a,const prc &b){ return a.val<b.val; }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d%d", &s[i].l, &s[i].r);
    sort(s+1,s+n+1,cmp1);
    for (int i=0; i<inf; i++) bit.t[i]=0;
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &c);
        while (c--)
        {
            scanf("%d", &x);
            p.push_back(prc(x,i));
        }
        p.push_back(prc(inf-1,i));
    }
    sort(p.begin(),p.end(),cmp2);

    for (int i=0, j=1; i<p.size(); i++)
    {
        while (j<=n && s[j].r < p[i].val) bit.upd(s[j].l,1), j++;
        z[p[i].idx] += bit.sum(p[i].val) - bit.sum(prv[p[i].idx]);
        prv[p[i].idx] = p[i].val;
    }

    for (int i=1; i<=m; i++) printf("%d\n",n-z[i]);
    return 0;
}
