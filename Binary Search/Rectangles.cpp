/*                        Codeforces Problem 333D Characteristics of Rectangles
  Ako je vrednost matrice n x m (n,m<=1000, a[i]<=10^9)definisana kao minimum brojeva u temenima te matrice, odrediti za zadatu
  matricu najvecu vrednost koju moze da ima neka njena podmatrica koja se dobija brisanjem nekih vrsta i kolona pocetne matrice
*/
#include<cstdio>
#include<cstring>
using namespace std;

int n, m, l, r, tmp[1005], a[1005][1005], ck[1005][1005];

bool check(int lim)
{
    memset(ck,0,sizeof(ck));
    for(int i=0; i<n; i++)
    {
        int sz = 0;
        for(int j=0; j<m; j++)
         if(a[i][j] >= lim)
         {
            for(int k=0; k<sz; k++)
            {
                if(ck[tmp[k]][j]) return 1;
                ck[tmp[k]][j] = 1;
            }
            tmp[sz++] = j;
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) scanf("%d",&a[i][j]);
    l=0, r=1e9+5;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (check(mid)) l=mid+1;
        else r = mid - 1;
    }
    printf("%d",l-1);
    return 0;
}
