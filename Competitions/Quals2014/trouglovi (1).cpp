#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define PI 3.14159265358979

int n, i, j, sol, prav;
float ang[2005], x[1005], y[1005];

int binser(double angle)
{
    int l=2, r=2*n-1, mid;
    while (l<r)
    {
        mid = (l+r) >> 1;
        if (ang[mid]-ang[j]>angle) r = mid-1;
         else l = mid+1;
    }
    return (l-1);
}
int binser1(double angle)
{
    int l=2, r=2*n-1, mid;
    while (l<r)
    {
        mid = (l+r) >> 1;
        if (ang[mid]-ang[j]<angle) l = mid+1;
         else r = mid-1;
    }
    return (l-1);
}

int main()
{
    scanf("%d", &n);
    for (i=1; i<=n; i++) scanf("%f%f", &x[i], &y[i]);
    sol = (n*(n-1)*(n-2))/6;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
         if (j!=i)
         {
             if (y[i]==y[j]) if (x[i]>x[j]) ang[j] = 3*PI/2; else ang[j] = PI/2;
             ang[j] = atan((x[j]-x[i])/(y[i]-y[j]));
             if (y[j]>y[i]) ang[j] += PI;
             if (ang[j]<0) ang[j] += 2*PI;
         } else ang[j] = -1;
         sort(ang+1, ang+n+1);
         for (j=1; j<n; j++) ang[n+j] = ang[j+1] + 2*PI;
         for (j=2; j<=n; j++)
         {
//             prav += binser(PI) - binser1(PI);
//             sol -= binser(PI) - binser1(PI/2);
               prav += upper_bound(ang+2, ang+2*n, ang[j]+PI) - lower_bound(ang+2, ang+2*n, ang[j]+PI);
               sol -= upper_bound(ang+2, ang+2*n, ang[j]+PI) - lower_bound(ang+2, ang+2*n, ang[j]+PI/2);
         }
    }
    sol += prav>>1;
    printf("%d", sol);
}
