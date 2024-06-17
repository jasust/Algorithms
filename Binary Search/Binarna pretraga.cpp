/* binarna pretraga, quick select, ternarna pretraga
   slozenost log(n)
   primena: klasicna, longest rising subsequence, pretraziti resenje pa ga proveriti
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define EPS 0.0000000001
#define PI  3.1415926536

int n, x, a[100005];
pair <int *,int *> bounds;

bool cmp(int _a, int _b) { return _a<_b; }

bool binary( int *_a, int _n, int _x)
{
    int l=0, r=_n-1, mid;
    while (l<=r)
    {
        mid=(l+r)>>1;
        if (_a[mid]==_x) return 1;
        if (_a[mid]<_x) l=mid+1;
        else r=mid-1;
    }
    return 0;
}

int lower( int *_a, int _n, int _x)
{
    int l=0, r=n-1, mid;
    while (l<=r)
    {
        mid = (l+r)>>1;
        if (_a[mid]<_x) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int upper( int *_a, int _n, int _x)
{
    int l=0, r=_n-1, mid;
    while (l<=r)
    {
        mid = (l+r)>>1;
        if (_a[mid]>_x) r=mid-1;
        else l=mid+1;
    }
    return l;
}

bool p(double sol) {
    return (sol<PI);
}

double cbinary() {
    double l = 0.0, r = 10000000.0, mid;
    while (r-l>EPS) {
        mid = l+(r-l)/2;
        if (p(mid)) l = mid+EPS;
            else r = mid-EPS;
    }
    return (l+r)/2;
}

int main()
{
    printf("Pi: %.10lf\n", cbinary());

    scanf("%d", &n);
    for (int i=0; i<n; i++) { scanf("%d", a+i); }

    sort(a, a+n, cmp);
    for (int i=0; i<n; i++) { printf("%d ", a[i]); }
    printf("\n");

    scanf("%d", &x);

    printf("%s\n", binary_search(a, a+n, x) ? "true" : "false");
    bounds = equal_range(a, a+n, x);
    printf("%d %d\n", bounds.first - a, bounds.second - a);
    printf("%d %d\n", lower_bound(a, a+n, x)-a, upper_bound(a, a+n, x)-a);

    printf("%s\n", binary(a, n, x) ? "true" : "false");
    printf("%d %d", lower(a, n, x), upper(a, n, x));

    return 0;
}
