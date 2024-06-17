#include <cstdio>
#include <algorithm>

int n, br, mac=-1, a[100005], o[100005],b[100005], c[100005] ;
bool d[100005];

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", a + i);
        o[a[i]]++;
        if (a[i]> mac) mac=a[i];
    }
    for (int i=0; i<=mac; i++)
    {
        b[i]=-1;
        c[i]=0;
        d[i]=true;
    }

    for (int i=0; i<n; i++)
    if (o[a[i]]>1)
    {
        if (b[a[i]] == -1) b[a[i]] = i;
        else if (c[a[i]] == 0) { c[a[i]] = i - b[a[i]]; b[a[i]] = i; }
        else if (i != b[a[i]] + c[a[i]]) d[a[i]] = false;
        else b[a[i]] = i;
    }

    for (int i=0; i<=mac; i++) if (o[i]>0 and d[i]) br++;
    printf("%d\n", br);

    for (int i=0; i<=mac; i++) if (o[i]>0 and d[i]) printf("%d %d\n", i, c[i]);

    return 0;
}
