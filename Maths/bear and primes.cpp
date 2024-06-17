#include <cstdio>
using namespace std;
const int maxp=10000010;

int c[maxp], a[maxp], n, m, x, l, r;
bool f[maxp];

int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        c[x]++;
    }

    for (int i=2; i<maxp; i++) if (!f[i])
        for (int j=1; i*j<maxp; j++) f[i*j]=1,a[i]+=c[i*j];
    for (int i=1;i<maxp;i++) a[i]+=a[i-1];

    scanf("%d",&m);
    while (m--)
    {
        scanf("%d %d",&l,&r);
        if (r>=maxp) r=maxp-1;
        if (l>=maxp) l=maxp-1;
        printf("%d\n",a[r]-a[l-1]);
    }
    return 0;
}
