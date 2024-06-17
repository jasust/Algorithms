#include<cstdio>
const int MaxN = 4000010;
typedef long long ll;

int q, type, x1, y1, x2, y2, v;
ll sum;

struct BIT
{
    ll bit[2][MaxN];
    void update1(int x,ll v,int t){ for(int i=x; i<MaxN; i+=(i&-i)) bit[t][i]+=v; }
    void update(int x,int y,ll v)
    {
        update1(x,v,0), update1(y+1,-v,0);
        update1(x,-(x-1)*v,1), update1(y+1,y*v,1);
    }
    ll get1(int x,int t)
    {
        ll ret = 0;
        for(int i=x; i; i-=(i&-i)) ret+=bit[t][i];
        return ret;
    }
    ll get(int x,int y){ return get1(y,0)*y + get1(y,1) - get1(x-1,0)*(x-1) - get1(x-1,1); }
} bit[2];

int main()
{
    scanf("%*d%*d%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d%d", &type, &x1, &y1, &x2, &y2);
        if(!type)
        {
            scanf("%d",&v);
            bit[0].update(x1,x2,(ll)(y2-y1+1) * v);
            bit[1].update(y1,y2,(ll)(x2-x1+1) * v);
            sum += (x2-x1+1) * (y2-y1+1) * v;
        }
        else printf("%lld\n",bit[0].get(x1,x2) + bit[1].get(y1,y2) - sum);
    }
    return 0;
}
