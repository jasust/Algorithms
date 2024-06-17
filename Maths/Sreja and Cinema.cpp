#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lld;
const lld mod=1000000007;

struct node
{
    lld val,idx;
    node(){}
    node(lld _val,lld _idx){ val=_val; idx=_idx; }
};
vector <node> v;

lld n, fact[100005], li[100005], ri[100005], lc[100005], rc[100005];
bool cmp(const node &a,const node &b){ return a.val<b.val; }

lld step(lld x,lld y)
{
    if (!y) return 1;
    lld s=step(x,y>>1);
    s=(s*s)%mod;
    if (y&1) s=(s*x)%mod;
    return s;
}

lld calc(lld idx,bool b1,bool b2)
{
    lld l1,l2,r1,r2;
    if (!b1) l1=li[idx], r1=v[idx].idx;
     else l1=v[idx].idx,r1=ri[idx];
    if (!b2) l2=li[idx-1],r2=v[idx-1].idx;
     else l2=v[idx-1].idx,r2=ri[idx-1];

    if (l1<0||l1>n||r1<1||r1>n) return 0;
    if (l2<1||l2>n||r1<1||r2>n) return 0;
    if (l2<l1||r2>r1) return 0;
    if (l1==l2&&r1==r2) return 0;

    lld res,x,y;
    x=r1-r2-1;
    y=l2-l1-1;
    if (b1) swap(x,y);
    if (!b2) res=lc[idx-1];
     else res=rc[idx-1];
    res=(((res*fact[x+y+1])%mod)*((step(fact[x],mod-2)*step(fact[y+1],mod-2))%mod))%mod;
    return res;
}

int main()
{
    scanf("%I64d",&n);
    v.push_back(node(n+1,0));
    for (lld i=1; i<=n; i++)
    {
        lld x;
        scanf("%I64d",&x);
        if (x) v.push_back(node(x,i));
    }

    fact[0]=1;
    for (lld i=1; i<=n; i++) fact[i]=(fact[i-1]*i)%mod;
    sort(v.begin(),v.end(),cmp);

    if (v[0].val==1)
    {
        lc[0]=1;li[0]=v[0].idx;
        rc[0]=0;ri[0]=v[0].idx;
    } else
    {
        lc[0]=step(2,v[0].val-2);
        li[0]=v[0].idx-v[0].val+1;
        rc[0]=step(2,v[0].val-2);
        ri[0]=v[0].idx+v[0].val-1;
    }

    for (lld i=1;i<v.size();i++)
    {
        li[i]=v[i].idx-v[i].val+1;
        ri[i]=v[i].idx+v[i].val-1;
        lc[i]=(calc(i,0,0)+calc(i,0,1))%mod;
        rc[i]=(calc(i,1,0)+calc(i,1,1))%mod;
    }

    printf("%I64d\n",rc[v.size()-1]);
    return 0;
}
