/* 2. Река је x оса, дато је n градова кординатама (xi, yi) и к излетишта кординатама (ai,bi), n<=k,
   која се налазе са исте стране реке са грдовима. Из града (xi,yi) треба отићи у неко од излетишта (ai,bi),
   а да се прво дође до реке. Израчунај укупну дужину свих путева тако да она буде најкраћа. */
#include<cstdio>
#include<cmath>
using namespace std;

struct koor
{
    int x,y;
} a[1003], b[1003];

int i, j, n, k;
float dist[1003][1003];

int main()
{
    scanf("%d", &n);
    for (i=0; i<n; i++) scanf("%d %d", &a[i].x, &a[i].y);
    scanf("%d", &k);
    for (i=0; i<n; i++) scanf("%d %d", &b[i].x, &b[i].y);
    for (i=0; i<n; i++)
        for (j=0; j<k; j++) dist[i][j] = sqrt((a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y+b[j].y)*(a[i].y+b[j].y));


    return 0;

}
